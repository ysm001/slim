/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse ilparse
#define yylex   illex
#define yyerror ilerror
#define yylval  illval
#define yychar  ilchar
#define yydebug ildebug
#define yynerrs ilnerrs
#define yylloc illloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _EOF = 0,
     INT = 258,
     FLOAT = 259,
     ID = 260,
     INST_NAME = 261,
     LABEL = 262,
     DQUOTED_STRING = 263,
     SQUOTED_STRING = 264,
     RULESET_ID = 265,
     COMMA = 266,
     PERIOD = 267,
     COLON = 268,
     UNDERBAR = 269,
     LBRACE = 270,
     RBRACE = 271,
     LBRACKET = 272,
     RBRACKET = 273,
     INSIDE_PROXY = 274,
     OUTSIDE_PROXY = 275,
     KW_COMPILED_RULESET = 276,
     KW_COMPILED_SYSTEM_RULESET = 277,
     KW_COMPILED_UNIQ_RULE = 278,
     KW_COMPILED_RULE = 279,
     KW_ATOMMATCH = 280,
     KW_MEMMATCH = 281,
     KW_GUARD = 282,
     KW_BODY = 283,
     KW_INLINE = 284,
     KW_MODULE = 285,
     INST_TK_LOOP = 286,
     INST_TK_RUN = 287,
     INST_TK_NOT = 288,
     INST_TK_GROUP = 289,
     INST_TK_BRANCH = 290
   };
#endif
/* Tokens.  */
#define _EOF 0
#define INT 258
#define FLOAT 259
#define ID 260
#define INST_NAME 261
#define LABEL 262
#define DQUOTED_STRING 263
#define SQUOTED_STRING 264
#define RULESET_ID 265
#define COMMA 266
#define PERIOD 267
#define COLON 268
#define UNDERBAR 269
#define LBRACE 270
#define RBRACE 271
#define LBRACKET 272
#define RBRACKET 273
#define INSIDE_PROXY 274
#define OUTSIDE_PROXY 275
#define KW_COMPILED_RULESET 276
#define KW_COMPILED_SYSTEM_RULESET 277
#define KW_COMPILED_UNIQ_RULE 278
#define KW_COMPILED_RULE 279
#define KW_ATOMMATCH 280
#define KW_MEMMATCH 281
#define KW_GUARD 282
#define KW_BODY 283
#define KW_INLINE 284
#define KW_MODULE 285
#define INST_TK_LOOP 286
#define INST_TK_RUN 287
#define INST_TK_NOT 288
#define INST_TK_GROUP 289
#define INST_TK_BRANCH 290




/* Copy the first part of user declarations.  */
#line 39 "il_parser.y"

#include <math.h>
#include <stdio.h>
#include "syntax.h"
#include "st.h"
#include "symbol.h"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 56 "il_parser.y"
{              /* define stack type */
  double _float;
  int _int;
  lmn_interned_str id;
  lmn_interned_str str;
  RuleSet ruleset;
  IL il;
  RuleSets rulesets;
  RuleList rules;
  Rule rule;
  InstBlock inst_block;
  InstList instructions;
  Instruction instruction;
  InstrArg arg;
  VarList inst_vars;
  Functor functor;
  ModuleList module_list;
  ArgList args;
  InlineList inline_list;
}
/* Line 193 of yacc.c.  */
#line 206 "il_parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */
#line 123 "il_parser.y"

#include "il_lexer.h"
void ilerror (YYLTYPE*, yyscan_t, IL *, Rule *, char *);



/* Line 216 of yacc.c.  */
#line 236 "il_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    18,    22,    25,
      26,    31,    37,    38,    41,    43,    46,    50,    54,    56,
      59,    65,    71,    75,    79,    80,    86,    87,    93,    95,
      96,    99,   104,   109,   114,   119,   124,   129,   131,   133,
     135,   137,   139,   141,   142,   145,   146,   150,   154,   155,
     158,   159,   163,   167,   169,   171,   175,   179,   185,   189
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,     0,    -1,    45,    -1,    42,    -1,
      42,    39,    -1,    42,    39,    29,    41,    -1,    42,    29,
      41,    -1,    30,    40,    -1,    -1,    40,     9,    15,    16,
      -1,    40,     9,    15,    10,    16,    -1,    -1,    41,     8,
      -1,    43,    -1,    42,    43,    -1,    22,    10,    44,    -1,
      21,    10,    44,    -1,    45,    -1,    44,    45,    -1,    23,
      46,    47,    48,    49,    -1,    24,    46,    47,    48,    49,
      -1,    25,    13,    51,    -1,    26,    13,    51,    -1,    -1,
      27,    13,    50,    13,    51,    -1,    -1,    28,    13,    50,
      13,    51,    -1,     7,    -1,    -1,    51,    52,    -1,     6,
      17,    54,    18,    -1,    31,    17,    59,    18,    -1,    32,
      17,    59,    18,    -1,    33,    17,    59,    18,    -1,    34,
      17,    59,    18,    -1,    35,    17,    59,    18,    -1,     3,
      -1,    60,    -1,    10,    -1,     8,    -1,    50,    -1,    56,
      -1,    -1,    55,    53,    -1,    -1,    55,    53,    11,    -1,
      17,    57,    18,    -1,    -1,    58,     3,    -1,    -1,    58,
       3,    11,    -1,    17,    51,    18,    -1,    19,    -1,    20,
      -1,     9,    14,     3,    -1,     8,    14,     3,    -1,     9,
      12,     9,    14,     3,    -1,     3,    14,     3,    -1,     4,
      14,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   137,   138,   139,   140,   144,   148,
     149,   150,   157,   158,   162,   163,   167,   168,   172,   173,
     177,   180,   186,   190,   194,   195,   199,   200,   204,   208,
     209,   214,   218,   219,   220,   221,   222,   226,   227,   228,
     229,   230,   231,   235,   236,   240,   241,   245,   249,   250,
     254,   255,   259,   267,   268,   269,   270,   271,   274,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "_EOF", "error", "$undefined", "INT", "FLOAT", "ID", "INST_NAME",
  "LABEL", "DQUOTED_STRING", "SQUOTED_STRING", "RULESET_ID", "COMMA",
  "PERIOD", "COLON", "UNDERBAR", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "INSIDE_PROXY", "OUTSIDE_PROXY", "KW_COMPILED_RULESET",
  "KW_COMPILED_SYSTEM_RULESET", "KW_COMPILED_UNIQ_RULE",
  "KW_COMPILED_RULE", "KW_ATOMMATCH", "KW_MEMMATCH", "KW_GUARD", "KW_BODY",
  "KW_INLINE", "KW_MODULE", "INST_TK_LOOP", "INST_TK_RUN", "INST_TK_NOT",
  "INST_TK_GROUP", "INST_TK_BRANCH", "$accept", "start", "world",
  "module_def", "modules", "inlines", "ruleSetList", "ruleSet", "ruleList",
  "rule", "atommatch", "memmatch", "guard", "body", "label",
  "instructions", "instruction", "arg", "args", "args_", "var_list_arg",
  "var_list", "var_list_", "inst_list_arg", "functor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    40,
      40,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    60,    60,    60,    60,    60,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     4,     3,     2,     0,
       4,     5,     0,     2,     1,     2,     3,     3,     1,     2,
       5,     5,     3,     3,     0,     5,     0,     5,     1,     0,
       2,     4,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     3,     3,     0,     2,
       0,     3,     3,     1,     1,     3,     3,     5,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     4,    14,     3,
       0,     0,     0,     0,     0,     1,     2,    12,     9,     5,
      15,    17,    18,    16,    29,     0,    24,    24,     7,     8,
      12,    19,    22,    29,     0,    26,    26,    13,     0,     6,
       0,     0,     0,     0,     0,     0,    30,    23,     0,     0,
      20,    21,     0,    45,     0,     0,     0,     0,     0,    28,
       0,     0,     0,    10,     0,     0,    29,     0,     0,     0,
       0,     0,    29,     0,    11,    31,    37,     0,    40,     0,
      39,    48,    53,    54,    41,    44,    42,    38,     0,    32,
      33,    34,    35,    36,    25,    29,     0,     0,     0,     0,
       0,     0,     0,    46,    52,    27,    58,    59,    56,     0,
      55,    47,    49,     0,    51,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,    19,    29,    28,     7,     8,    21,    22,
      13,    26,    35,    50,    60,    32,    46,    85,    64,    65,
      86,   101,   102,    67,    87
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int8 yypact[] =
{
      -6,    14,    32,    18,    18,    48,    49,   -18,   -56,   -56,
       8,     8,    38,    24,    24,   -56,   -56,   -56,   -56,    23,
     -56,     8,   -56,     8,   -56,    40,    28,    28,    50,    51,
     -56,   -56,     3,   -56,    46,    33,    33,   -56,    52,    50,
      47,    53,    54,    55,    56,    57,   -56,     3,    58,    62,
     -56,   -56,    -2,    45,    59,    59,    59,    59,    59,   -56,
      64,    58,    63,   -56,    60,    37,   -56,    65,    66,    67,
      68,    69,   -56,    75,   -56,   -56,    76,    77,    78,    -7,
     -56,    79,   -56,   -56,   -56,    70,   -56,   -56,    -5,   -56,
     -56,   -56,   -56,   -56,     3,   -56,    86,    90,    91,    71,
      92,    80,    93,   -56,   -56,     3,   -56,   -56,   -56,    83,
     -56,   -56,    88,    97,   -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,    36,   -56,    61,    94,     2,
      98,    87,    42,    72,   -55,   -33,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -36,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int8 yytable[] =
{
      47,    40,     9,     1,     2,    99,    73,   100,    62,    40,
      84,    17,    18,   104,    63,     1,     2,     3,     4,    68,
      69,    70,    71,    31,    10,    31,    41,    42,    43,    44,
      45,     3,     4,    88,    41,    42,    43,    44,    45,    94,
      76,    77,    11,    12,    59,    78,    79,    80,    15,    16,
      25,    24,    30,    33,    81,    34,    82,    83,    37,    48,
      38,    49,   105,   -43,    53,    59,    39,    52,    20,    36,
      54,    55,    56,    57,    58,    61,    66,    72,    75,    74,
     109,   103,   -50,    89,    90,    91,    92,    93,    95,   106,
      96,    97,    98,   107,   108,   110,   112,   113,   111,   114,
     115,    27,    14,     0,     0,    23,     0,     0,    51
};

static const yytype_int8 yycheck[] =
{
      33,     6,     0,    21,    22,    12,    61,    14,    10,     6,
      65,    29,    30,    18,    16,    21,    22,    23,    24,    55,
      56,    57,    58,    21,    10,    23,    31,    32,    33,    34,
      35,    23,    24,    66,    31,    32,    33,    34,    35,    72,
       3,     4,    10,    25,     7,     8,     9,    10,     0,     0,
      26,    13,    29,    13,    17,    27,    19,    20,     8,    13,
       9,    28,    95,    18,    17,     7,    30,    15,     7,    27,
      17,    17,    17,    17,    17,    13,    17,    13,    18,    16,
       9,    11,     3,    18,    18,    18,    18,    18,    13,     3,
      14,    14,    14,     3,     3,     3,     3,    14,    18,    11,
       3,    14,     4,    -1,    -1,    11,    -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    24,    37,    38,    42,    43,    45,
      10,    10,    25,    46,    46,     0,     0,    29,    30,    39,
      43,    44,    45,    44,    13,    26,    47,    47,    41,    40,
      29,    45,    51,    13,    27,    48,    48,     8,     9,    41,
       6,    31,    32,    33,    34,    35,    52,    51,    13,    28,
      49,    49,    15,    17,    17,    17,    17,    17,    17,     7,
      50,    13,    10,    16,    54,    55,    17,    59,    59,    59,
      59,    59,    13,    50,    16,    18,     3,     4,     8,     9,
      10,    17,    19,    20,    50,    53,    56,    60,    51,    18,
      18,    18,    18,    18,    51,    13,    14,    14,    14,    12,
      14,    57,    58,    11,    18,    51,     3,     3,     3,     9,
       3,    18,     3,    14,    11,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, scanner, ret_il, ret_rule, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, scanner, ret_il, ret_rule); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, IL* ret_il, Rule* ret_rule)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, ret_il, ret_rule)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
    IL* ret_il;
    Rule* ret_rule;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ret_il);
  YYUSE (ret_rule);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, IL* ret_il, Rule* ret_rule)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, ret_il, ret_rule)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    yyscan_t scanner;
    IL* ret_il;
    Rule* ret_rule;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, ret_il, ret_rule);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, IL* ret_il, Rule* ret_rule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, scanner, ret_il, ret_rule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    yyscan_t scanner;
    IL* ret_il;
    Rule* ret_rule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , scanner, ret_il, ret_rule);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, scanner, ret_il, ret_rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, IL* ret_il, Rule* ret_rule)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, scanner, ret_il, ret_rule)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    yyscan_t scanner;
    IL* ret_il;
    Rule* ret_rule;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (ret_il);
  YYUSE (ret_rule);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (yyscan_t scanner, IL* ret_il, Rule* ret_rule);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (yyscan_t scanner, IL* ret_il, Rule* ret_rule)
#else
int
yyparse (scanner, ret_il, ret_rule)
    yyscan_t scanner;
    IL* ret_il;
    Rule* ret_rule;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 132 "il_parser.y"
    { *ret_il = (yyvsp[(1) - (2)].il); }
    break;

  case 3:
#line 133 "il_parser.y"
    { *ret_rule = (yyvsp[(1) - (1)].rule); }
    break;

  case 4:
#line 137 "il_parser.y"
    { (yyval.il) = il_make((yyvsp[(1) - (1)].rulesets), module_list_make(), inline_list_make()); }
    break;

  case 5:
#line 138 "il_parser.y"
    { (yyval.il) = il_make((yyvsp[(1) - (2)].rulesets), (yyvsp[(2) - (2)].module_list), inline_list_make()); }
    break;

  case 6:
#line 139 "il_parser.y"
    { (yyval.il) = il_make((yyvsp[(1) - (4)].rulesets), (yyvsp[(2) - (4)].module_list), (yyvsp[(4) - (4)].inline_list)); }
    break;

  case 7:
#line 140 "il_parser.y"
    { (yyval.il) = il_make((yyvsp[(1) - (3)].rulesets), module_list_make(), (yyvsp[(3) - (3)].inline_list)); }
    break;

  case 8:
#line 144 "il_parser.y"
    { (yyval.module_list) = (yyvsp[(2) - (2)].module_list); }
    break;

  case 9:
#line 148 "il_parser.y"
    { (yyval.module_list) = module_list_make(); }
    break;

  case 10:
#line 149 "il_parser.y"
    { (yyval.module_list) = (yyvsp[(1) - (4)].module_list); }
    break;

  case 11:
#line 150 "il_parser.y"
    {
  module_list_push((yyvsp[(1) - (5)].module_list), module_make((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)]._int)));
  (yyval.module_list) = (yyvsp[(1) - (5)].module_list);
}
    break;

  case 12:
#line 157 "il_parser.y"
    { (yyval.inline_list) = inline_list_make(); }
    break;

  case 13:
#line 158 "il_parser.y"
    { inline_list_push((yyvsp[(1) - (2)].inline_list), (yyvsp[(2) - (2)].str)); (yyval.inline_list) = (yyvsp[(1) - (2)].inline_list); }
    break;

  case 14:
#line 162 "il_parser.y"
    { (yyval.rulesets) = rulesets_make(); rulesets_push((yyval.rulesets), (yyvsp[(1) - (1)].ruleset)); }
    break;

  case 15:
#line 163 "il_parser.y"
    { rulesets_push((yyvsp[(1) - (2)].rulesets), (yyvsp[(2) - (2)].ruleset)); (yyval.rulesets) = (yyvsp[(1) - (2)].rulesets); }
    break;

  case 16:
#line 167 "il_parser.y"
    { (yyval.ruleset) = ruleset_make((yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)].rules), TRUE); }
    break;

  case 17:
#line 168 "il_parser.y"
    { (yyval.ruleset) = ruleset_make((yyvsp[(2) - (3)]._int), (yyvsp[(3) - (3)].rules), FALSE); }
    break;

  case 18:
#line 172 "il_parser.y"
    { (yyval.rules) = rulelist_make(); rulelist_push((yyval.rules), (yyvsp[(1) - (1)].rule)); }
    break;

  case 19:
#line 173 "il_parser.y"
    { rulelist_push((yyvsp[(1) - (2)].rules), (yyvsp[(2) - (2)].rule)); (yyval.rules) = (yyvsp[(1) - (2)].rules); }
    break;

  case 20:
#line 177 "il_parser.y"
    {
    (yyval.rule) = rule_make_anonymous(TRUE, (yyvsp[(2) - (5)].inst_block), (yyvsp[(3) - (5)].inst_block), (yyvsp[(4) - (5)].inst_block), (yyvsp[(5) - (5)].inst_block));
  }
    break;

  case 21:
#line 180 "il_parser.y"
    {
    (yyval.rule) = rule_make_anonymous(FALSE, (yyvsp[(2) - (5)].inst_block), (yyvsp[(3) - (5)].inst_block), (yyvsp[(4) - (5)].inst_block), (yyvsp[(5) - (5)].inst_block));
  }
    break;

  case 22:
#line 186 "il_parser.y"
    { (yyval.inst_block) = inst_block_make_without_label((yyvsp[(3) - (3)].instructions)); }
    break;

  case 23:
#line 190 "il_parser.y"
    { (yyval.inst_block) = inst_block_make_without_label((yyvsp[(3) - (3)].instructions)); }
    break;

  case 24:
#line 194 "il_parser.y"
    { (yyval.inst_block) = inst_block_make_without_label(inst_list_make()); }
    break;

  case 25:
#line 195 "il_parser.y"
    { (yyval.inst_block) = inst_block_make((yyvsp[(3) - (5)]._int), (yyvsp[(5) - (5)].instructions)); }
    break;

  case 26:
#line 199 "il_parser.y"
    { (yyval.inst_block) = inst_block_make_without_label(inst_list_make()); }
    break;

  case 27:
#line 200 "il_parser.y"
    { (yyval.inst_block) = inst_block_make((yyvsp[(3) - (5)]._int), (yyvsp[(5) - (5)].instructions)); }
    break;

  case 28:
#line 204 "il_parser.y"
    { (yyval._int) = (yyvsp[(1) - (1)]._int); }
    break;

  case 29:
#line 208 "il_parser.y"
    { (yyval.instructions) = inst_list_make(); }
    break;

  case 30:
#line 209 "il_parser.y"
    { inst_list_push((yyvsp[(1) - (2)].instructions), (yyvsp[(2) - (2)].instruction)); (yyval.instructions) = (yyvsp[(1) - (2)].instructions); }
    break;

  case 31:
#line 214 "il_parser.y"
    {
  (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args));
}
    break;

  case 32:
#line 218 "il_parser.y"
    { (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args)); }
    break;

  case 33:
#line 219 "il_parser.y"
    { (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args)); }
    break;

  case 34:
#line 220 "il_parser.y"
    { (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args)); }
    break;

  case 35:
#line 221 "il_parser.y"
    { (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args)); }
    break;

  case 36:
#line 222 "il_parser.y"
    { (yyval.instruction) = inst_make((yyvsp[(1) - (4)]._int), (yyvsp[(3) - (4)].args)); }
    break;

  case 37:
#line 226 "il_parser.y"
    { (yyval.arg) = instr_var_arg_make((yyvsp[(1) - (1)]._int)); }
    break;

  case 38:
#line 227 "il_parser.y"
    { (yyval.arg) = functor_arg_make((yyvsp[(1) - (1)].functor)); }
    break;

  case 39:
#line 228 "il_parser.y"
    { (yyval.arg) = ruleset_arg_make((yyvsp[(1) - (1)]._int)); }
    break;

  case 40:
#line 229 "il_parser.y"
    { (yyval.arg) = string_arg_make((yyvsp[(1) - (1)].str)); }
    break;

  case 41:
#line 230 "il_parser.y"
    { (yyval.arg) = label_arg_make((yyvsp[(1) - (1)]._int)); }
    break;

  case 42:
#line 231 "il_parser.y"
    { (yyval.arg) = (yyvsp[(1) - (1)].arg); }
    break;

  case 43:
#line 235 "il_parser.y"
    { (yyval.args) = arg_list_make(); }
    break;

  case 44:
#line 236 "il_parser.y"
    { arg_list_push((yyvsp[(1) - (2)].args), (yyvsp[(2) - (2)].arg)); (yyval.args) = (yyval.args) = (yyvsp[(1) - (2)].args); }
    break;

  case 45:
#line 240 "il_parser.y"
    { (yyval.args) = arg_list_make(); }
    break;

  case 46:
#line 241 "il_parser.y"
    { arg_list_push((yyvsp[(1) - (3)].args), (yyvsp[(2) - (3)].arg)) ; (yyval.args) = (yyvsp[(1) - (3)].args); }
    break;

  case 47:
#line 245 "il_parser.y"
    { (yyval.arg) = var_list_arg_make((yyvsp[(2) - (3)].inst_vars)); }
    break;

  case 48:
#line 249 "il_parser.y"
    { (yyval.inst_vars) = var_list_make(); }
    break;

  case 49:
#line 250 "il_parser.y"
    { var_list_push((yyvsp[(1) - (2)].inst_vars), (yyvsp[(2) - (2)]._int)); (yyval.inst_vars) = (yyvsp[(1) - (2)].inst_vars); }
    break;

  case 50:
#line 254 "il_parser.y"
    { (yyval.inst_vars) = var_list_make(); }
    break;

  case 51:
#line 255 "il_parser.y"
    { var_list_push((yyvsp[(1) - (3)].inst_vars), (yyvsp[(2) - (3)]._int)); (yyval.inst_vars) = (yyvsp[(1) - (3)].inst_vars); }
    break;

  case 52:
#line 259 "il_parser.y"
    {
  ArgList l = arg_list_make();
  arg_list_push(l, inst_list_arg_make((yyvsp[(2) - (3)].instructions)));
  (yyval.args) = l;
}
    break;

  case 53:
#line 267 "il_parser.y"
    { (yyval.functor) = functor_make(STX_IN_PROXY); }
    break;

  case 54:
#line 268 "il_parser.y"
    { (yyval.functor) = functor_make(STX_OUT_PROXY); }
    break;

  case 55:
#line 269 "il_parser.y"
    {(yyval.functor) = symbol_functor_make((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)]._int)); }
    break;

  case 56:
#line 270 "il_parser.y"
    {(yyval.functor) = string_functor_make((yyvsp[(1) - (3)].str)); }
    break;

  case 57:
#line 271 "il_parser.y"
    {
    (yyval.functor) = module_symbol_functor_make((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)]._int));
  }
    break;

  case 58:
#line 274 "il_parser.y"
    {
    (yyval.functor) = int_functor_make((yyvsp[(1) - (3)]._int));
  }
    break;

  case 59:
#line 277 "il_parser.y"
    {
    (yyval.functor) = float_functor_make((yyvsp[(1) - (3)]._float));
  }
    break;


/* Line 1267 of yacc.c.  */
#line 1881 "il_parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, ret_il, ret_rule, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, scanner, ret_il, ret_rule, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, scanner, ret_il, ret_rule, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, scanner, ret_il, ret_rule);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, scanner, ret_il, ret_rule);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, ret_il, ret_rule, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, scanner, ret_il, ret_rule);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, scanner, ret_il, ret_rule);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 283 "il_parser.y"


#include "st.h"

/* Called by yyparse on error.  */
void ilerror (YYLTYPE *loc, yyscan_t scanner, IL *il, Rule *rule, char *s)
{
  fprintf (stderr, "il parser: error %s line: %d\n", s, ilget_lineno(scanner));
  exit(1);
}

