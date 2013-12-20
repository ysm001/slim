/*
 * mc_generator.h
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

#ifndef LMN_MC_GEN_H
#define LMN_MC_GEN_H

#include "lmntal.h"
#include "mc_worker.h"


/** prototypes
 */
void dfs_env_set(LmnWorker *w);
void dfs_start(LmnWorker *w);
void dfs_worker_init(LmnWorker *w);
void dfs_worker_finalize(LmnWorker *w);
BOOL dfs_worker_check(LmnWorker *w);

void mcdfs_start(LmnWorker *w);

void bfs_env_set(LmnWorker *w);
void bfs_start(LmnWorker *w);
void bfs_worker_init(LmnWorker *w);
void bfs_worker_finalize(LmnWorker *w);
BOOL bfs_worker_check(LmnWorker *w);

#ifdef PROFILE
# define pop_stack(List)                                                       \
  do {                                                                         \
    State *pop = (State *)vec_pop(List);                                       \
    if (is_on_stack(pop)) unset_on_stack(pop);                                 \
    if (lmn_env.profile_level >= 3) {                                          \
      profile_remove_space(PROFILE_SPACE__OPEN_LIST, sizeof(LmnWord));         \
    }                                                                          \
  } while (0)
# define put_stack(List, St)                                                   \
  do {                                                                         \
    if (lmn_env.profile_level >= 3) {                                          \
      profile_add_space(PROFILE_SPACE__OPEN_LIST, sizeof(LmnWord));            \
    }                                                                          \
    vec_push((List), (vec_data_t)(St));                                        \
  } while (0)
# define pop_deq(Deq, Dir)                                                     \
  do {                                                                         \
    if (Dir) {                                                                  \
      deq_pop_tail(Deq);                                                       \
    } else {                                                                   \
      deq_pop_head(Deq);                                                       \
    }                                                                          \
    if (lmn_env.profile_level >= 3) {                                          \
      profile_remove_space(PROFILE_SPACE__OPEN_LIST, sizeof(LmnWord));         \
    }                                                                          \
  } while (0)
# define push_deq(List, St, Dir)                                               \
  do {                                                                         \
    if (lmn_env.profile_level >= 3) {                                          \
      profile_add_space(PROFILE_SPACE__OPEN_LIST, sizeof(LmnWord));            \
    }                                                                          \
    if (Dir) {                                                                 \
      deq_push_tail((List), (vec_data_t)(St));                                 \
    } else {                                                                   \
      deq_push_head((List), (vec_data_t)(St));                                 \
    }                                                                          \
} while (0)
# define EXECUTE_PROFILE_START()                                               \
  if (lmn_env.profile_level >= 3) {                                            \
    profile_remove_space(PROFILE_SPACE__OPEN_LIST, sizeof(Node));              \
    profile_start_timer(PROFILE_TIME__ACTIVE_FOR_IDLE_PROF);                   \
  }
# define EXECUTE_PROFILE_FINISH()                                              \
  if (lmn_env.profile_level >= 3) {                                            \
    profile_finish_timer(PROFILE_TIME__ACTIVE_FOR_IDLE_PROF);                  \
  }
# define ADD_OPEN_PROFILE(M)                                                   \
  if (lmn_env.profile_level >= 3) {                                            \
    profile_add_space(PROFILE_SPACE__OPEN_LIST, M);                            \
  }
#else
# define EXECUTE_PROFILE_START()
# define EXECUTE_PROFILE_FINISH()
# define ADD_OPEN_PROFILE(M)
# define pop_stack(List)                                                       \
  do {                                                                         \
    State *pop = (State *)vec_pop(List);                                       \
    if (is_on_stack(pop)) unset_on_stack(pop);                                 \
  } while (0)
# define put_stack(List, St)  vec_push((List), (vec_data_t)(St))
# define pop_deq(Deq, Dir)                                                     \
  do {                                                                         \
    if (Dir) {                                                                 \
      deq_pop_tail(Deq);                                                       \
    } else {                                                                   \
      (State *)deq_pop_head(Deq);                                              \
    }                                                                          \
  } while (0)
# define push_deq(List, St, Dir)                                               \
  do {                                                                         \
    if (Dir) {                                                                 \
      deq_push_tail((List), (vec_data_t)(St));                                 \
    } else {                                                                   \
      deq_push_head((List), (vec_data_t)(St));                                 \
    }                                                                          \
} while (0)

#endif


#endif
