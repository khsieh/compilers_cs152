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
     NUMBER = 258,
     PROGRAM = 259,
     BEGIN_PROGRAM = 260,
     END_PROGRAM = 261,
     INTEGER = 262,
     ARRAY = 263,
     OF = 264,
     IF = 265,
     THEN = 266,
     END_IF = 267,
     ELSE = 268,
     WHILE = 269,
     BEGIN_LOOP = 270,
     END_LOOP = 271,
     READ = 272,
     WRITE = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     TRUE = 277,
     FALSE = 278,
     EXIT = 279,
     CONTINUE = 280,
     TERM = 281,
     STATE = 282,
     R_AND_EXPR = 283,
     R_EXPR = 284,
     MULT_EXPR = 285,
     IDENT_LIST = 286,
     EXPR = 287,
     BOOL_EXPR = 288,
     BLOCK = 289,
     ELSE_STATE = 290,
     COMP = 291,
     DO = 292,
     DECLARATION = 293,
     VAR = 294,
     VAR_LOOP = 295,
     IDENT = 296,
     SUB = 297,
     ADD = 298,
     MULT = 299,
     DIV = 300,
     MOD = 301,
     QUESTION = 302,
     EQ = 303,
     NEQ = 304,
     LT = 305,
     GT = 306,
     LTE = 307,
     GTE = 308,
     SEMICOLON = 309,
     COLON = 310,
     COMMA = 311,
     L_PAREN = 312,
     R_PAREN = 313,
     L_BRACKET = 314,
     R_BRACKET = 315,
     ASSIGN = 316
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define PROGRAM 259
#define BEGIN_PROGRAM 260
#define END_PROGRAM 261
#define INTEGER 262
#define ARRAY 263
#define OF 264
#define IF 265
#define THEN 266
#define END_IF 267
#define ELSE 268
#define WHILE 269
#define BEGIN_LOOP 270
#define END_LOOP 271
#define READ 272
#define WRITE 273
#define AND 274
#define OR 275
#define NOT 276
#define TRUE 277
#define FALSE 278
#define EXIT 279
#define CONTINUE 280
#define TERM 281
#define STATE 282
#define R_AND_EXPR 283
#define R_EXPR 284
#define MULT_EXPR 285
#define IDENT_LIST 286
#define EXPR 287
#define BOOL_EXPR 288
#define BLOCK 289
#define ELSE_STATE 290
#define COMP 291
#define DO 292
#define DECLARATION 293
#define VAR 294
#define VAR_LOOP 295
#define IDENT 296
#define SUB 297
#define ADD 298
#define MULT 299
#define DIV 300
#define MOD 301
#define QUESTION 302
#define EQ 303
#define NEQ 304
#define LT 305
#define GT 306
#define LTE 307
#define GTE 308
#define SEMICOLON 309
#define COLON 310
#define COMMA 311
#define L_PAREN 312
#define R_PAREN 313
#define L_BRACKET 314
#define R_BRACKET 315
#define ASSIGN 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "mini_l.y"
{
  int     int_val;
  char*   string_val;
 }
/* Line 1529 of yacc.c.  */
#line 176 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

