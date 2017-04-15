
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 61 "part3.y"

	#include <list>
	#include <string>
	#include <vector>
	typedef std::list<std::string*>* listchar;
    struct OperationReturn
	{
		std::string* opType;
		std::string* var;
		std::list<std::string*>* code;
	};
	struct AssignVarReturn
	{
		std::string* var;
		std::list<std::string*>* code;
		std::string* index;
	};
	struct StateSemiReturn
	{
		std::list<std::string*>* continues;
		std::list<std::string*>* code;
	};
	struct CodeAndVar
	{
		std::string* var;
		std::list<std::string*>* code;
	};



/* Line 1676 of yacc.c  */
#line 71 "y.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     BEGIN_PROGRAM = 259,
     END_PROGRAM = 260,
     INTEGER = 261,
     ARRAY = 262,
     OF = 263,
     IF = 264,
     THEN = 265,
     ENDIF = 266,
     ELSE = 267,
     WHILE = 268,
     DO = 269,
     BEGINLOOP = 270,
     ENDLOOP = 271,
     CONTINUE = 272,
     READ = 273,
     WRITE = 274,
     AND = 275,
     OR = 276,
     NOT = 277,
     TRUE = 278,
     FALSE = 279,
     SUB = 280,
     ADD = 281,
     MULT = 282,
     DIV = 283,
     MOD = 284,
     EQ = 285,
     NEQ = 286,
     LT = 287,
     GT = 288,
     LTE = 289,
     GTE = 290,
     SEMICOLON = 291,
     COLON = 292,
     COMMA = 293,
     L_PAREN = 294,
     R_PAREN = 295,
     ASSIGN = 296,
     IDENT = 297,
     NUMBER = 298,
     MINUS = 299,
     PLUS = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 90 "part3.y"

  std::string* sval;
  int ival;
  listchar CodeBlock;
  StateSemiReturn* CodeNCont;
  OperationReturn* OpRet;
  AssignVarReturn* AVRet;
  CodeAndVar* cav;
 


/* Line 1676 of yacc.c  */
#line 145 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


