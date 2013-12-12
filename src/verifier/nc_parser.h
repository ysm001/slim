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
     SYMBOL = 258,
     NUMBER = 259,
     COLON = 260,
     COLON_COLON = 261,
     SEMI_COLON = 262,
     LBRACE = 263,
     RBRACE = 264,
     LPAREN = 265,
     RPAREN = 266,
     AND = 267,
     OR = 268,
     IMPLICATION = 269,
     NEGATION = 270,
     EQUIVALENCE = 271,
     ALWAYS = 272,
     EVENTUALLY = 273,
     UNTIL = 274,
     RELEASE = 275,
     NEXT = 276,
     KW_GOTO = 277,
     KW_IF = 278,
     KW_FI = 279,
     KW_SKIP = 280,
     KW_TRUE = 281,
     KW_FALSE = 282
   };
#endif
/* Tokens.  */
#define _EOF 0
#define SYMBOL 258
#define NUMBER 259
#define COLON 260
#define COLON_COLON 261
#define SEMI_COLON 262
#define LBRACE 263
#define RBRACE 264
#define LPAREN 265
#define RPAREN 266
#define AND 267
#define OR 268
#define IMPLICATION 269
#define NEGATION 270
#define EQUIVALENCE 271
#define ALWAYS 272
#define EVENTUALLY 273
#define UNTIL 274
#define RELEASE 275
#define NEXT 276
#define KW_GOTO 277
#define KW_IF 278
#define KW_FI 279
#define KW_SKIP 280
#define KW_TRUE 281
#define KW_FALSE 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 54 "nc_parser.y"
{
  int _int;
  char *str;
  struct AutomataState *state;
  struct AutomataTransition *transition;
  struct Vector *vector;
  struct PLFormula *PLFormula;
}
/* Line 1529 of yacc.c.  */
#line 114 "nc_parser.h"
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


