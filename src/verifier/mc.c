/*
 * mc.c
 *
 *   Copyright (c) 2008, Ueda Laboratory LMNtal Group
 *                                         <lmntal@ueda.info.waseda.ac.jp>
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are
 *   met:
 *
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *
 *    3. Neither the name of the Ueda Laboratory LMNtal Group nor the
 *       names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior
 *       written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */

#include "mc.h"
#include "mc_worker.h"
#include "task.h"
#include "dpor.h"
#include "error.h"
#include "delta_membrane.h"
#include "propositional_symbol.h"
#include "ltl2ba_adapter.h"
#include "runtime_status.h"
#ifdef DEBUG
#  include "dumper.h"
#endif


/** =======================================
 *  ==== Entrance for model checking ======
 *  =======================================
 */


static inline void do_mc(LmnMembrane *world_mem, Automata a, Vector *psyms, int thread_num);
static void mc_dump(LmnWorkerGroup *wp);


/* 非決定実行を行う. run_mcもMT-unsafeなので子ルーチンとしては使えない */
void run_mc(Vector *start_rulesets, Automata a, Vector *psyms)
{
  static LmnMembrane *mem;

  if (lmn_env.nd_cleaning) {
    /* nd_cleaning状態の場合は、グローバルルート膜の解放を行う */
    lmn_mem_free_rec(mem);
    lmn_env.nd_cleaning = FALSE;
  }

  if(!lmn_env.nd_remain && !lmn_env.nd_remaining) {
    mem = lmn_mem_make();
  }

  react_start_rulesets(mem, start_rulesets);
  lmn_mem_activate_ancestors(mem);

  do_mc(mem, a, psyms, lmn_env.core_num);

  if (lmn_env.nd_remain) {
    lmn_env.nd_remaining = TRUE;
  } else {
    lmn_env.nd_remaining = FALSE;
    lmn_mem_drop(mem);
    lmn_mem_free(mem);
  }
}


static inline void do_mc(LmnMembrane *world_mem_org,
                         Automata    a,
                         Vector      *psyms,
                         int         thread_num)
{
  LmnWorkerGroup *wp;
  StateSpace states;
  State *init_s;
  BYTE p_label;

  /** INITIALIZE
   */
  wp = lmn_workergroup_make(a, psyms, thread_num);
  states = worker_states(workers_get_worker(wp, LMN_PRIMARY_ID));
  p_label = a ? automata_get_init_state(a)
              : DEFAULT_STATE_ID;
  init_s  = state_make(lmn_mem_copy(world_mem_org),
                       p_label,
                       statespace_use_memenc(states));
  state_id_issue(init_s); /* 状態に整数IDを発行 */
#ifdef KWBT_OPT
  if (lmn_env.opt_mode != OPT_NONE) state_set_cost(init_s, 0U, NULL); /* 初期状態のコストは0 */
#endif
  statespace_set_init_state(states, init_s, lmn_env.enable_compress_mem);

  /** START
   */
  launch_lmn_workers(wp);

#ifdef DEBUG
  if (lmn_env.show_reduced_graph && lmn_env.enable_por && !lmn_env.enable_por_old) {
    dpor_explore_redundunt_graph(states);
  }
#endif

  /** FINALIZE
   */
  profile_statespace(wp);
  mc_dump(wp);
  lmn_workergroup_free(wp);
}


/* 後始末と出力周りを担当 */
static void mc_dump(LmnWorkerGroup *wp)
{
  StateSpace ss = worker_states(workers_get_worker(wp, LMN_PRIMARY_ID));
  if (lmn_env.dump) {
    statespace_format_states(ss);

    /* 1. 状態遷移グラフの標準出力 */
    if (lmn_env.trace) {
      statespace_dumper(ss);
    }

    /* 2. 反例パス or 最終状態集合の出力 */
    if (wp->do_search) {
      mc_dump_all_errors(wp, ss->out);
    }
    else if (lmn_env.end_dump && lmn_env.mc_dump_format == CUI) {
      /* とりあえず最終状態集合の出力はCUI限定。(LaViTに受付フォーマットがない) */
      statespace_ends_dumper(ss);
    }

    /* CUIモードの場合状態数などのデータも標準出力 */
    if (lmn_env.mc_dump_format == CUI) {
      fprintf(ss->out, "\'# of States\'(stored)   = %lu.\n", statespace_num(ss));
      fprintf(ss->out, "\'# of States\'(end)      = %lu.\n", statespace_end_num(ss));
      if (wp->do_search) {
        fprintf(ss->out, "\'# of States\'(invalid)  = %lu.\n", mc_invalids_get_num(wp));
      }
#ifdef KWBT_OPT
      if (lmn_env.opt_mode != OPT_NONE) {
        if (!workers_opt_end_state(wp)) {
          fprintf(ss->out, "\'# can't solve the problem\'.\n");
        } else {
          fprintf(ss->out, "\'# optimized cost\'      = %lu.\n", workers_opt_cost(wp));
        }
      }
#endif
    }
  }

  if (statespace_has_property(ss)) lmn_prof.has_property = TRUE;
  if (workers_have_error(wp))      lmn_prof.found_err = TRUE;
}



/** =====================================================
 *  === Fundamental System for StateSpace Generation ====
 *  =====================================================
 */

static inline void mc_gen_successors_inner(LmnReactCxt *rc, LmnMembrane *cur_mem);
static inline void stutter_extension(State       *s,
                                     LmnMembrane *mem,
                                     BYTE        next_label,
                                     LmnReactCxt *rc,
                                     BOOL        flags);


/* 状態sから1stepで遷移する状態を計算し, 遷移元状態と状態空間に登録を行う
 * 遷移先状態のうち新規状態がnew_statesに積まれる */
void mc_expand(const StateSpace ss,
               State            *s,
               AutomataState    p_s,
               LmnReactCxt      *rc,
               Vector           *new_ss,
               Vector           *psyms,
               BOOL             f)
{
  LmnMembrane *mem;

  /** restore : 膜の復元 */
  mem = state_restore_mem(s);

  /** expand  : 状態の展開 */
  if (p_s) {
    mc_gen_successors_with_property(s, mem, p_s, rc, psyms, f);
  } else {
    mc_gen_successors(s, mem, DEFAULT_STATE_ID, rc, f);
  }

  if (mc_react_cxt_expanded_num(rc) == 0) {
    /* sを最終状態集合として記録 */
    statespace_add_end_state(ss, s);
  }
  else if (mc_enable_por(f) && !s_is_reduced(s)) {
    /* POR: 遷移先状態集合:en(s)からample(s)を計算する.
     * 呼び出し先で, mc_store_successorsに相当する処理を済ませる */
    dpor_start(ss, s, rc, new_ss, f);
  }
  else {
    /* sのサクセッサを状態空間ssに記録 */
    mc_store_successors(ss, s, rc, new_ss, f);
  }

  if (!state_mem(s)) {
    /** free   : 遷移先を求めた状態sからLMNtalプロセスを開放 */
#ifdef PROFILE
    if (lmn_env.profile_level >= 3) {
      profile_add_space(PROFILE_SPACE__REDUCED_MEMSET, lmn_mem_space(mem));
    }
#endif
    lmn_mem_free_rec(mem);
  }

  /* この時点で, sのサクセッサ登録が全て完了->フラグセット
   * (フラグがセットされた状態が, 受理サイクル探索の対象となるので,
   *  フラグセットのタイミングは重要.) */

  set_expanded(s);
  RC_CLEAR_DATA(rc);

#ifdef PROFILE
  if (lmn_env.profile_level >= 3) {
    profile_total_space_update(ss);
  }
#endif
}


/* 状態sの全ての遷移先状態のコストを可能ならば更新し、updateフラグを立てる.
 * TODO: 排他制御が適当です by kawabata */
void mc_update_cost(State *s, Vector *new_ss, EWLock *ewlock)
{
  unsigned int i, n;
  BOOL f;
  State *succ;

#ifdef PROFILE
  if (lmn_env.profile_level >= 3) {
    profile_start_timer(PROFILE_TIME__COST_UPDATE);
  }
#endif

  s_unset_update(s);
  n = state_succ_num(s);
  f = (lmn_env.opt_mode == OPT_MINIMIZE);
  for (i = 0; i < n; i++) {
    succ = state_succ_state(s, i);
    state_update_cost(succ, transition(s, i), s, new_ss, f, ewlock);
  }

#ifdef PROFILE
  if (lmn_env.profile_level >= 3) {
    profile_finish_timer(PROFILE_TIME__COST_UPDATE);
  }
#endif
}


/** 生成した各Successor Stateが既出か否かを検査し, 遷移元の状態sのサクセッサに設定する.
 *   + 多重辺を除去する.
 *   + "新規"状態をnew_ssへ積む.　 */
void mc_store_successors(const StateSpace ss,
                         State            *s,
                         LmnReactCxt      *rc,
                         Vector           *new_ss,
                         BOOL             f)
{
  unsigned int i, succ_i;

  /** 状態登録 */
  succ_i = 0;
  for (i = 0; i < mc_react_cxt_expanded_num(rc); i++) {
    Transition src_t;
    st_data_t tmp;
    State *src_succ, *succ;
    LmnMembrane *src_succ_m;

    /* 状態sのi番目の遷移src_tと遷移先状態src_succを取得 */
    if (!has_trans_obj(s)) {
      /* Transitionオブジェクトを利用しない場合 */
      src_t    = NULL;
      src_succ = (State *)vec_get(RC_EXPANDED(rc), i);
    } else {
      src_t    = (Transition)vec_get(RC_EXPANDED(rc), i);
      src_succ = transition_next_state(src_t);
    }

    if (RC_MC_USE_D(rc) && RC_D_COND(rc)) {
      /* delta-stringフラグをこの時点で初めて立てる */
      s_set_d(src_succ);
    }

    /* 状態空間に状態src_succを記録 */
    if (RC_MC_USE_DMEM(rc)) {           /* --delta-mem */
      MemDeltaRoot *d = (struct MemDeltaRoot *)vec_get(RC_MEM_DELTAS(rc), i);
      succ       = statespace_insert_delta(ss, src_succ, d);
      src_succ_m = NULL;
    }
    else if (is_encoded(src_succ)) {    /* !--delta-mem && --mem-enc */
      if (s_is_d(src_succ)) state_calc_binstr_delta(src_succ);
      succ       = statespace_insert(ss, src_succ);
      src_succ_m = NULL;
    }
    else { /* default */
      src_succ_m = state_mem(src_succ); /* for free mem pointed by src_succ */
      succ       = statespace_insert(ss, src_succ);
    }

    if (succ == src_succ) {
      /* new state */
      state_id_issue(succ);
      if (mc_use_compress(f) && src_succ_m) {
        lmn_mem_free_rec(src_succ_m);
      }
      if (new_ss)        vec_push(new_ss, (vec_data_t)succ);
      if (mc_is_dump(f)) dump_state_data(succ, (LmnWord)stdout, (LmnWord)NULL);
    }
    else {
      /* contains */
      state_free(src_succ);
      if (has_trans_obj(s)) {
        /* Transitionオブジェクトが指すサクセッサを検出した等価な状態の方へ設定し直す */
        transition_set_state(src_t, succ);
      }
    }

    /* 多重辺(1stepで合流する遷移関係)を除去 */
    tmp = 0;
    if (!st_lookup(RC_SUCC_TBL(rc), (st_data_t)succ, (st_data_t *)&tmp)) {
      /* succへの遷移が多重辺ではない場合 */
      st_data_t ins;
      if (has_trans_obj(s)) {
        ins = (st_data_t)src_t;
      } else {
        ins = (st_data_t)succ;
      }
      /* 状態succをサクセッサテーブルへ記録(succをkeyにして, succに対応する遷移insを登録) */
      st_add_direct(RC_SUCC_TBL(rc), (st_data_t)succ, ins);
      /* 遷移先情報を記録する一時領域(in ReactCxt)を更新 */
      vec_set(RC_EXPANDED(rc), succ_i++, ins);
    }
    else if (has_trans_obj(s)) {
      /* succへの遷移が多重辺かつTransitionオブジェクトを利用する場合 */
      /* src_tは状態生成時に張り付けたルール名なので, 0番にしか要素はないはず */
      transition_add_rule((Transition)tmp,
                          transition_rule(src_t, 0),
                          transition_cost(src_t));
      transition_free(src_t);
    } /*
    else succへの遷移が多重辺かつTransitionオブジェクトを利用しない場合
         then "辺"という構造を持たない(直接pointerで刺している)ので何もしない
    */
  }

  st_clear(RC_SUCC_TBL(rc));

  RC_EXPANDED(rc)->num = succ_i;      /* 危険なコード. いつか直すかも. */
  RC_EXPANDED_RULES(rc)->num = succ_i;
/*  上記につられて以下のコードを記述すると実行時エラーになる. (r436でdebug)
 *  RC_MEM_DELTASはmc_store_successors終了後に, struct MemDeltaRootの開放処理を行うため要素数に手を加えてはならない. */
//  if (RC_MC_USE_DMEM(rc)) {
//    RC_MEM_DELTAS(rc)->num = succ_i;
//  }

  state_D_progress(s, rc);
  state_succ_set(s, RC_EXPANDED(rc)); /* successorを登録 */
}


/*
 * 状態を展開する
 * 引数として与えられた膜と、その膜に所属する全てのアクティブ膜に対して
 * ルール適用検査を行う
 * 子膜からルール適用を行っていく
 */
BOOL mc_expand_inner(LmnReactCxt *rc, LmnMembrane *cur_mem)
{
  BOOL ret_flag = FALSE;

  for (; cur_mem; cur_mem = cur_mem->next) {
    unsigned long org_num = mc_react_cxt_expanded_num(rc);

    /* 代表子膜に対して再帰する */
    if (mc_expand_inner(rc, cur_mem->child_head)) {
      ret_flag = TRUE;
    }
    if (lmn_mem_is_active(cur_mem)) {
      react_all_rulesets(rc, cur_mem);
    }
    /* 子膜からルール適用を試みることで, 本膜の子膜がstableか否かを判定できる */
    if (org_num == mc_react_cxt_expanded_num(rc)) {
      lmn_mem_set_active(cur_mem, FALSE);
    }
  }

  return ret_flag;
}


/** 膜memから1stepで遷移可能な膜を, state_nameと合わせて状態として生成し,
 *  TransitionをRC_EXPANDEDへセットする.
 *  生成された状態は重複（多重辺）を含む */
void mc_gen_successors(State       *src,
                       LmnMembrane *mem,
                       BYTE        state_name,
                       LmnReactCxt *rc,
                       BOOL        f)
{
  Vector *expanded_roots, *expanded_rules;
  unsigned int i, n, old;

  RC_SET_GROOT_MEM(rc, mem);

  /* 性質遷移数だけ本関数を呼び出している.
   * 一つ前までの展開遷移数をメモしておくことで, 今回の展開遷移数を計算する */
  old = mc_react_cxt_expanded_num(rc);

  /** Generate Successor Membrane (or DeltaMemrane) */
  mc_gen_successors_inner(rc, mem);

  /** Generate Successor States */
  expanded_roots   = RC_EXPANDED(rc);       /* DeltaMembrane時は空 */
  expanded_rules   = RC_EXPANDED_RULES(rc);
  n = mc_react_cxt_expanded_num(rc);

  for (i = old; i < n; i++) {
    State *news;
    vec_data_t data;

    /* DeltaMembrane時はこの時点でSuccessor Membraneがない */
    if (mc_use_delta(f)) {
      news = state_make_minimal();
    } else {
      news = state_make((LmnMembrane *)vec_get(expanded_roots, i),
                        state_name,
                        mc_use_canonical(f));
    }

    state_set_property_state(news, state_name);
    state_set_parent(news, src);
    if (mc_has_trans(f)) {
      lmn_interned_str nid;
      nid  =  lmn_rule_get_name((LmnRule)vec_get(expanded_rules, i));
      data = (vec_data_t)transition_make(news, nid);
      set_trans_obj(src);
    } else {
      data = (vec_data_t)news;
    }

    /* DeltaMembrane時は, expanded_rootsが空であるため, 生成した空の状態を積む
     * 通常時は, expanded_rootsのi番目のデータを
     *           Successor MembraneからSuccessor Stateへ設定し直す */
    if (mc_use_delta(f)) {
      vec_push(expanded_roots, data);
    } else {
      vec_set(expanded_roots, i, data);
    }
  }

  RC_ND_SET_ORG_SUCC_NUM(rc, (n - old));
}



/* 膜memから, 性質ルールとシステムルールの同期積によって遷移可能な全状態(or遷移)をベクタに積む */
void mc_gen_successors_with_property(State         *s,
                                     LmnMembrane   *mem,
                                     AutomataState p_s,
                                     LmnReactCxt   *rc,
                                     Vector        *propsyms,
                                     BOOL          f)
{
  unsigned int i, j;

  /** 状態展開:
   *   性質ルールが適用される場合, global_rootに対してシステムルール適用検査を行う.
   *   システムルール適用はglobal_rootのコピーに対して行われる.
   *   状態展開にexpandが使用された場合は, 現状態から遷移可能な全ての状態が生成されるのに対し，
   *   ampleが使用された場合はPartial Order Reductionに基づき，次状態の代表のみ生成される．
   *   なお，適用可能なシステムルールが存在しない場合は，
   *   何も処理を行わない特殊なシステムルール(stutter extension rule)によるε遷移を行う.
   *   これにより, 受理頂点に次状態が存在しない場合でも受理サイクルを形成できるため,
   *   満たすべき仕様に対する反例を漏れなく検出できるようになる．
   *   (c.f. "The Spin Model Checker" pp.130-131)
   */

  for (i = 0; i < atmstate_transition_num(p_s); i++) {
    AutomataTransition p_t = atmstate_get_transition(p_s, i);
    if (eval_formula(mem, propsyms, atm_transition_get_formula(p_t))) {
      BYTE p_nxt_l = atm_transition_next(p_t);
      vec_push(RC_EXPANDED_PROPS(rc), (vec_data_t)p_nxt_l);
    }
  }

  if (vec_is_empty(RC_EXPANDED_PROPS(rc))) {
    return;
  } else {
    BYTE first_prop = (BYTE)vec_get(RC_EXPANDED_PROPS(rc), 0);
    mc_gen_successors(s, mem, first_prop, rc, f);
    if (mc_react_cxt_expanded_num(rc) == 0) {
      stutter_extension(s, mem, first_prop, rc, f);
    }
  }

  /* 階層グラフ構造は等価だが性質ラベルの異なる状態を生成する.　*/
  RC_ND_SET_ORG_SUCC_NUM(rc, mc_react_cxt_expanded_num(rc));
  for (i = 1; i < vec_num(RC_EXPANDED_PROPS(rc)); i++) {
    BYTE p_nxt_l = (BYTE)vec_get(RC_EXPANDED_PROPS(rc), i);
    for (j = 0; j < RC_ND_ORG_SUCC_NUM(rc); j++) {
      Transition src_succ_t;
      State *src_succ_s, *new_s;
      vec_data_t data;

      if (mc_has_trans(f)) {
        src_succ_t = (Transition)vec_get(RC_EXPANDED(rc), j);
        src_succ_s = transition_next_state(src_succ_t);
      } else {
        src_succ_t = NULL;
        src_succ_s = (State *)vec_get(RC_EXPANDED(rc), j);
      }

      new_s = state_copy(src_succ_s, NULL);
      state_set_parent(new_s, s);
      state_set_property_state(new_s, p_nxt_l);

      if (mc_has_trans(f)) {
        data = (vec_data_t)transition_make(new_s, transition_rule(src_succ_t, 0));
#ifdef KWBT_OPT
        transition_set_cost((Transition)data, transition_cost(src_succ_t));
#endif
        set_trans_obj(s);
      } else {
        data = (vec_data_t)new_s;
      }
      vec_push(RC_EXPANDED(rc), data);

      /* 差分オブジェクトは状態展開時のみの一時データなので,
       * 効率化のためにポインタcopyのみにしている(deep copyしない)
       * !! 開放処理は要注意 (r435でdebug) !! */
      if (RC_MC_USE_DMEM(rc)) {
        vec_push(RC_MEM_DELTAS(rc), vec_get(RC_MEM_DELTAS(rc), j));
      }
    }
  }
}


/* 状態sからStutter Extension Ruleを適用した遷移を展開する.
 * 膜memとmemに対応する状態sをコピーし, 性質ラベルnext_labelを持った状態として,
 * サクセッサ展開の一時領域(in ReactCxt)に追加する */
static inline void stutter_extension(State       *s,
                                     LmnMembrane *mem,
                                     BYTE        next_label,
                                     LmnReactCxt *rc,
                                     BOOL        f)
{
  vec_data_t data;
  State *new_s;

  /* Stutter Extension Rule:
   *
   * 性質ルールで可能な遷移が存在するにも拘らず, システムルールで可能な遷移が存在しない場合,
   * 同期積オートマトングラフ上で遷移が出現せず, 受理サイクルが形成されなくなってしまうことがある.
   * これを防ぐために同期積オートマトングラフ上でε遷移を形成させる.
   * これをStutter Extensionと呼ぶ.
   * Stutter Extensionは性質オートマトン上のみの遷移となるため,
   * 同期積オートマトングラフ上では
   *   1. self-loopとなる(遷移の前後で性質ラベルが変化しない)か
   *   2. 性質ラベルの変化のみ
   *      (状態データには変化がないため, どもっている(Stuttering)と表現するらしい)
   * となる.
   */

  if (mc_use_delta(f)) {
    /* 差分構造が存在しないstruct MemDeltaRootを登録する. */
    mc_react_cxt_add_mem_delta(rc, dmem_root_make(mem, NULL, 0), NULL);
    new_s = state_make_minimal();
  } else {
    /* 遷移元状態sをdeep copyする.
     * ただし, sに対応した階層グラフ構造はこの時点では既に破棄されているため,
     * mc_expandの時点で再構築した階層グラフ構造memを渡す.  */
    new_s = state_copy(s, mem);
  }
  state_set_property_state(new_s, next_label);
  state_set_parent(new_s, s);

  if (mc_has_trans(f)) {
    data = (vec_data_t)transition_make(new_s, lmn_intern("ε"));
    set_trans_obj(s);
  } else {
    data = (vec_data_t)new_s;
  }
  vec_push(RC_EXPANDED(rc), data);
}


static inline void mc_gen_successors_inner(LmnReactCxt *rc, LmnMembrane *cur_mem)
{
#ifdef PROFILE
  if(lmn_env.profile_level >= 3) {
    profile_start_timer(PROFILE_TIME__TRANS_RULE);
  }
#endif

  mc_expand_inner(rc, cur_mem);

#ifdef PROFILE
  if(lmn_env.profile_level >= 3) {
    profile_finish_timer(PROFILE_TIME__TRANS_RULE);
  }
#endif
}




/** ===========================================
 *  === Counter Example generator / dumper ====
 *  ===========================================
 */

/* エラーを示す頂点を登録する.
 * MT-Unsafe, but ok */
void mc_found_invalid_state(LmnWorkerGroup *wp, State *s)
{
  workers_found_error(wp);
  if (s) {
    LmnWorker *w = workers_get_my_worker(wp);
    vec_push(worker_invalid_seeds(w), (vec_data_t)s);
  }

  if (!wp->do_exhaustive) {
    workers_set_exit(wp);
  }
}


/* エラーを示すサイクルパスを載せたVectorを登録する.
 * MT-Unsafe, but ok  */
void mc_found_invalid_path(LmnWorkerGroup *wp, Vector *v)
{
  workers_found_error(wp);

  if (v) {
    LmnWorker *w = workers_get_my_worker(wp);
    vec_push(worker_cycles(w), (vec_data_t)v);
  }

  if (!wp->do_exhaustive) {
    workers_set_exit(wp);
  }
}


unsigned long mc_invalids_get_num(LmnWorkerGroup *wp)
{
  unsigned long ret;
  unsigned int i, n;

  ret = 0;
  n = lmn_env.core_num;
  for (i = 0; i < wp->worker_num; i++) {
    ret += vec_num(worker_invalid_seeds(workers_get_worker(wp, i)));
  }

  return ret;
}


/* 初期頂点から状態seedに至るパスを載せたVectorをmallocして返す */
static Vector *mc_gen_invalids_path(State *seed)
{
  Vector *path;
  State  *pred;

  path = vec_make(32);
  pred = seed;

  while (pred) { /* 初期頂点のparentはNULL */
    vec_push(path, (vec_data_t)pred);
    pred = state_get_parent(pred);
  }

  vec_reverse(path);

  return path;
}

#define MC_INSERT_INVALIDS(G, S_KEY, SUCC)                               \
  do {                                                                   \
    Vector *succs;                                                       \
    st_data_t t;                                                         \
                                                                         \
    t = 0;                                                               \
    if (st_lookup(G, (st_data_t)(S_KEY), &t)) {                          \
      succs = (Vector *)t;                                               \
      if (!vec_contains(succs, (vec_data_t)SUCC)) {                      \
        vec_push(succs, (vec_data_t)SUCC);                               \
      }                                                                  \
    } else {                                                             \
      succs = vec_make(2);                                               \
      vec_push(succs, (vec_data_t)SUCC);                                 \
      st_insert(G, (st_data_t)(S_KEY), (st_data_t)succs);                \
    }                                                                    \
  } while (0)


/* Vectorに積まれた状態を, 遷移元の状態idをkeyに, 遷移先の集合をvalueとした
 * ハッシュ表に登録する */
static void mc_store_invalids_graph(Automata a, st_table_t g, Vector *v)
{
  unsigned int i, j;

  for (i = 0, j = 1;
       i < vec_num(v) && j < vec_num(v);
       i++, j++) {

    State *s1, *s2;

    s1 = (State *)vec_get(v, i);
    s2 = (State *)vec_get(v, j);

    MC_INSERT_INVALIDS(g, s1, s2);
  }

  if (state_is_end(a, (State *)vec_peek(v))) {
    State *s = (State *)vec_peek(v);
    MC_INSERT_INVALIDS(g, s, NULL);
  }
}


static int mc_dump_invalids_f(st_data_t _key, st_data_t _v, st_data_t _arg)
{
  StateSpace ss;
  State *s;
  Vector *succs;
  unsigned int i;

  ss          = (StateSpace)_arg;
  s           = (State *)_key;
  succs       = (Vector *)_v;

  /* TODO: Rehashされていた場合には状態データが出力できない
   *       オリジナルテーブル側のdummy状態に対応するmemid状態を探索して引っ張ってくる必要がある */

  fprintf(ss->out, "%lu::", state_format_id(s, ss->is_formated));
  for (i = 0; i < vec_num(succs); i++) {
    State *succ = (State *)vec_get(succs, i);
    if (succ) {
      fprintf(ss->out, "%s%lu",
              (i > 0) ? ", " : "", state_format_id(succ, ss->is_formated));
    }
  }
  fprintf(ss->out, "\n");

  return ST_CONTINUE;
}


int mc_free_succ_vec_f(st_data_t _key, st_data_t _v, st_data_t _arg)
{
  Vector *v = (Vector *)_v;
  vec_free(v);
  return ST_CONTINUE;
}


void mc_print_vec_states(StateSpace ss, Vector *v, State *seed)
{
  unsigned int i;

  for (i = 0; i < vec_num(v); i++) {
    State *s;

    if (lmn_env.sp_dump_format != LMN_SYNTAX) {
      char *m;
      s = (State *)vec_get(v, i);
      m = (s == seed) ? "*" : " ";
      fprintf(ss->out, "%s%2lu::%s"
                     , m
                     , state_format_id(s, ss->is_formated)
                     , automata_state_name(statespace_automata(ss),
                                           state_property_state(s)));
      state_print_mem(s, (LmnWord)ss->out);
    }
    else {
      s = (State *)vec_get(v, i);
      fprintf(ss->out, "path%lu_%s"
                     , state_format_id(s, ss->is_formated)
                     , automata_state_name(statespace_automata(ss),
                                           state_property_state(s)));
      state_print_mem(s, (LmnWord)ss->out);
      fprintf(ss->out, ".\n");

      fprintf(ss->out, "path%lu_%s"
                     , state_format_id(s, ss->is_formated)
                     , automata_state_name(statespace_automata(ss),
                                           state_property_state(s)));
      state_print_mem(s, (LmnWord)ss->out);
      fprintf(ss->out, ":- ");
    }
  }
}



/* 各LmnWorkerに登録した反例を出力する.
 * 登録された反例は頂点のみであり,
 * 登録された頂点が, atmstate_is_endの場合, safety
 * その他の場合は, その頂点を起点にしたサイクルパスにon_cycle_flagが立っている */
void mc_dump_all_errors(LmnWorkerGroup *wp, FILE *f)
{
  if (!wp->error_exist) {
    fprintf(f, "%s\n", lmn_env.mc_dump_format == CUI
                      ? "No Accepting Cycle (or Invalid State) exists."
                      : "");
  }
  else {
    switch (lmn_env.mc_dump_format) {
    case LaViT:
    case CUI:
    {
      st_table_t invalids_graph;
      unsigned int i, j;
      BOOL cui_dump;

      fprintf(f, "%s\n", lmn_env.sp_dump_format == LMN_SYNTAX
                         ? "counter_exapmle."
                         : "CounterExamplePaths");

      cui_dump = (lmn_env.mc_dump_format == CUI);
      invalids_graph = cui_dump ? NULL : st_init_ptrtable();

      /* state property */
      for (i = 0; i < workers_entried_num(wp); i++) {
        LmnWorker *w;
        Vector *v;
        StateSpace ss;

        w  = workers_get_worker(wp, i);
        v  = worker_invalid_seeds(w);
        ss = worker_states(w);

        for (j = 0; j < vec_num(v); j++) {
          Vector *path = mc_gen_invalids_path((State *)vec_get(v, j));

          if (cui_dump) { /* 出力 */
            mc_print_vec_states(ss, path, NULL);
            fprintf(f, "\n");
          } else {    /* ハッシュ表に追加 */
            mc_store_invalids_graph(statespace_automata(ss), invalids_graph, path);
          }
          vec_free(path);
        }
      }

      /* path property */
      for (i = 0; i < workers_entried_num(wp); i++) {
        LmnWorker *w;
        Vector *v;
        StateSpace ss;

        w  = workers_get_worker(wp, i);
        v  = worker_cycles(w);
        ss = worker_states(w);

        for (j = 0; j < vec_num(v); j++) {
          Vector *cycle, *path;
          State *seed;

          cycle = (Vector *)vec_get(v, j);
          seed  = (State *)vec_get(cycle, 0);
          path  = mc_gen_invalids_path(seed);

          vec_push(cycle, (vec_data_t)seed); /* seed to seedのパスを取得するため */

          if (cui_dump) {
            vec_pop(path); /* cycle Vectorとpath Vectorでseedが重複して積まれているため */
            mc_print_vec_states(ss,  path, NULL);
            mc_print_vec_states(ss, cycle, seed);
            fprintf(f, "\n");
          } else {
            LMN_ASSERT(invalids_graph);
            mc_store_invalids_graph(statespace_automata(ss), invalids_graph, path);
            mc_store_invalids_graph(statespace_automata(ss), invalids_graph, cycle);
          }

          vec_free(path);
        }
      }

      if (!cui_dump) {
        StateSpace represent = worker_states(workers_get_worker(wp, LMN_PRIMARY_ID));
        st_foreach(invalids_graph, mc_dump_invalids_f, (st_data_t)represent);
        st_foreach(invalids_graph, mc_free_succ_vec_f, (st_data_t)0);
        st_free_table(invalids_graph);
      }

      break;
    }

    case Dir_DOT: /* TODO: 反例パスをサブグラフとして指定させたら分かりやすくなりそう */
    case FSM:     /* TODO: 未定. ltsviewはdotファイルを読み出せるので廃止しても良い */
      fprintf(f, "under constructions..\n");
      break;
    default:
      lmn_fatal("unexpected.");
      break;
    }
  }
}



/** =================================
 *  === Property Automata loader ====
 *  =================================
 */

enum MC_ERRORNO {
  MC_ERR_NC_ENV,
  MC_ERR_PROP_ENV,
  MC_NC_OPEN_ERROR,
  MC_NC_LOAD_ERROR,
  MC_PROP_OPEN_ERROR,
  MC_PROP_LOAD_ERROR,
};


/* 性質を表すBuchiオートマトン, 命題記号定義(ルール左辺)の集合を,
 * それぞれa, prop_defsに読み込む.
 * 成功ならば0, そうでないならば0以外を返す */
int mc_load_property(Automata *a, PVector *prop_defs)
{
  FILE *nc_fp, *prop_fp;
  int r;

  *a = NULL;
  *prop_defs = NULL;
  nc_fp = prop_fp = NULL;

  if (lmn_env.ltl_exp) {
    nc_fp = ltl2ba_str(lmn_env.ltl_exp);
  } else {
    if (!lmn_env.automata_file) goto NC_ENV;
    if (!(nc_fp = fopen(lmn_env.automata_file, "r"))) goto NC_OPEN_ERROR;
  }
  if (never_claim_load(nc_fp, a)) goto NC_LOAD_ERROR;

  if (!lmn_env.propositional_symbol) goto PROP_ENV;
  if (!(prop_fp = fopen(lmn_env.propositional_symbol, "r"))) goto PROP_OPEN_ERROR;
  if (propsym_load_file(prop_fp, *a, prop_defs)) goto PROP_LOAD_ERROR;

  r = 0;
  goto RET;

NC_ENV:        r = MC_ERR_NC_ENV;    goto FINALLY;
PROP_ENV:      r = MC_ERR_PROP_ENV;  goto FINALLY;
NC_OPEN_ERROR: r = MC_NC_OPEN_ERROR; goto FINALLY;
NC_LOAD_ERROR:
  {
    char c;
    rewind(nc_fp);
    while ((c = fgetc(nc_fp)) != EOF) {
      fputc(c, stderr);
    }
    r = MC_NC_LOAD_ERROR;
    goto FINALLY;
  }
PROP_OPEN_ERROR: r = MC_PROP_OPEN_ERROR; goto FINALLY;
PROP_LOAD_ERROR: r = MC_PROP_LOAD_ERROR; goto FINALLY;

FINALLY:
  LMN_FREE(*a);
  LMN_FREE(*prop_defs);

RET:
  if (prop_fp) fclose(prop_fp);
  if (nc_fp) fclose(nc_fp);
  return r;
}

void mc_explain_error(int error_id)
{
  lmn_report(mc_error_msg(error_id));
}

char *mc_error_msg(int error_id)
{
  switch (error_id) {
  case MC_ERR_NC_ENV:
    return "specify never claim file";
  case MC_ERR_PROP_ENV:
    return "specify propositional symbol definition file";
  case MC_NC_OPEN_ERROR:
    return "cannot open never claim file";
  case  MC_NC_LOAD_ERROR:
    return "error while parsing never claim file";
  case MC_PROP_OPEN_ERROR:
    return "cannot open propositional symbol definition file";
  case MC_PROP_LOAD_ERROR:
    return "error while parsing propositional symbol definition file";
  default:
    lmn_fatal("implementation error\n");
    return NULL;
  }
}
