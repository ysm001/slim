/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 142 "il_parser.h"
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


