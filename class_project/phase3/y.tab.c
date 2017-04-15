
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "part3.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <vector>
	#include <iostream>
	#include <sstream>
	#include <list>
	#include <string>
	#include <fstream>

	using namespace std;
	void yyerror(const char *msg);

	bool fromDec = true;

	extern int currLine;
	extern int currPos;
	extern char* yytext;
    extern int yylex();

	extern FILE * yyin;
	int prodNum = 0;

	vector<string*> varNames;
	vector<string*> varArraySize;
	vector<string*> tempVars;
	int labelCount = 0;
	int numConsecutiveInits = 0;
	string* nextTemp();
	void ValidateIdent(string* ident, bool checkingArray);

	struct OperationReturn;
	struct StateSemiReturn;
	struct AssignVarReturn;
	struct CodeAndVar;

	OperationReturn* OperationFunction(string* input1, CodeAndVar* input2, OperationReturn* input3);
	void DefineVarsAsArrays(string* length);
	void PrintAll(list<string*>* code);
	StateSemiReturn* IOStatement(string opType, AssignVarReturn* avr, StateSemiReturn* nextIOStatement);
	StateSemiReturn* WhileFunction(StateSemiReturn* stateRet, CodeAndVar* boolExp);
	StateSemiReturn* DoWhileFunction(StateSemiReturn* stateRet, CodeAndVar* boolExp);
	StateSemiReturn* StateSemiFunction(StateSemiReturn* statement, StateSemiReturn* prev);

	StateSemiReturn* AssignStatement(AssignVarReturn* avr, CodeAndVar* expr);
	StateSemiReturn* IfStatement(CodeAndVar* boolExp, StateSemiReturn* statements );
	StateSemiReturn* IfElseStatement(CodeAndVar* boolExp, StateSemiReturn* ifStatements, StateSemiReturn* elseStatements );
	void CreateFile(string* filename, StateSemiReturn* statements);
	string nextLabel();

	/*struct OperationReturn
	{
		char* opType;
		char* var;
	};*/




/* Line 189 of yacc.c  */
#line 133 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
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



/* Line 209 of yacc.c  */
#line 188 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 90 "part3.y"

  std::string* sval;
  int ival;
  listchar CodeBlock;
  StateSemiReturn* CodeNCont;
  OperationReturn* OpRet;
  AssignVarReturn* AVRet;
  CodeAndVar* cav;
 


/* Line 214 of yacc.c  */
#line 262 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 274 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    15,    19,    23,    24,    28,    29,
      34,    44,    48,    49,    53,    59,    67,    73,    80,    84,
      88,    90,    93,    97,    98,   101,   102,   106,   107,   112,
     115,   118,   123,   127,   129,   131,   135,   137,   139,   141,
     143,   145,   147,   151,   152,   156,   157,   160,   164,   168,
     169,   172,   176,   180,   184,   185,   188,   191,   196,   198,
     200,   204,   206,   211,   213,   218,   220,   222,   224,   226,
     228,   230,   232,   234,   236,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   258,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   298
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    70,   110,   103,    48,    72,    -1,    52,
     103,    51,    71,    49,    -1,    54,   103,    50,    -1,    54,
     103,    50,    -1,    -1,    52,   103,    51,    -1,    -1,   110,
      53,   104,    73,    -1,   110,    53,   104,    74,   106,   109,
     107,    75,    73,    -1,   105,   110,    53,    -1,    -1,    69,
     108,    63,    -1,    76,    55,    77,    49,    78,    -1,    76,
      55,    77,    49,    79,    49,    78,    -1,    80,    55,    82,
      49,    83,    -1,    81,    82,    49,    83,    80,    55,    -1,
      85,    69,    61,    -1,    86,    69,    62,    -1,    84,    -1,
      57,    56,    -1,    88,    57,    56,    -1,    -1,    59,    58,
      -1,    -1,    87,    59,    58,    -1,    -1,    89,    63,    60,
      63,    -1,    89,    90,    -1,    89,    91,    -1,    89,   106,
      55,   107,    -1,    63,    60,    63,    -1,    90,    -1,    91,
      -1,   106,    55,   107,    -1,    97,    -1,    98,    -1,    99,
      -1,   100,    -1,   101,    -1,   102,    -1,   105,    69,    61,
      -1,    -1,   105,    69,    62,    -1,    -1,    65,    64,    -1,
      93,    65,    64,    -1,    92,    65,    64,    -1,    -1,    67,
      66,    -1,    94,    67,    66,    -1,    95,    67,    66,    -1,
      96,    67,    66,    -1,    -1,    92,    68,    -1,    92,   109,
      -1,    92,   106,    63,   107,    -1,    68,    -1,   109,    -1,
     106,    63,   107,    -1,   110,    -1,   110,   106,    63,   107,
      -1,   110,    -1,   110,   106,    63,   107,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,
      19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    43,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   120,   123,   126,   127,   130,   131,   134,
     135,   138,   139,   143,   144,   145,   146,   147,   148,   151,
     154,   157,   170,   171,   174,   185,   188,   189,   192,   200,
     201,   202,   204,   211,   212,   213,   216,   217,   218,   219,
     220,   221,   224,   225,   228,   229,   232,   241,   242,   243,
     246,   255,   256,   257,   258,   261,   262,   263,   264,   265,
     266,   269,   270,   273,   274,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGIN_PROGRAM",
  "END_PROGRAM", "INTEGER", "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE",
  "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE",
  "AND", "OR", "NOT", "TRUE", "FALSE", "SUB", "ADD", "MULT", "DIV", "MOD",
  "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA",
  "L_PAREN", "R_PAREN", "ASSIGN", "IDENT", "NUMBER", "MINUS", "PLUS",
  "$accept", "Program", "Block", "StateSemiP", "StateSemi", "DecSemi",
  "Declaration", "Comm_IDENT", "Statement", "BoolExp", "OrRelExp",
  "RelationAndExp", "AndRelExp", "RelationExp", "Comp", "RComVar",
  "WComVar", "Expression", "AddMultExp", "MultExp", "MultTerm", "Term",
  "Var", "AssignVar", "_PROGRAM", "_BEGIN_PROGRAM", "_END_PROGRAM",
  "_INTEGER", "_ARRAY", "_OF", "_IF", "_THEN", "_ENDIF", "_ELSE", "_WHILE",
  "_DO", "_BEGINLOOP", "_ENDLOOP", "_CONTINUE", "_READ", "_WRITE", "_AND",
  "_OR", "_NOT", "_TRUE", "_FALSE", "_SUB", "_ADD", "_MULT", "_DIV",
  "_MOD", "_EQ", "_NEQ", "_LT", "_GT", "_LTE", "_GTE", "_SEMICOLON",
  "_COLON", "_COMMA", "_L_PAREN", "_R_PAREN", "_ASSIGN", "_NUMBER",
  "_IDENT", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    64,    64,    64,
      65,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     5,     3,     3,     0,     3,     0,     4,
       9,     3,     0,     3,     5,     7,     5,     6,     3,     3,
       1,     2,     3,     0,     2,     0,     3,     0,     4,     2,
       2,     4,     3,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     0,     3,     0,     2,     3,     3,     0,
       2,     3,     3,     3,     0,     2,     2,     4,     1,     1,
       3,     1,     4,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,     0,     0,     1,   105,     0,    98,     0,     0,
       0,    12,    67,     2,     8,   100,     0,     0,     0,     0,
      99,     0,    12,    66,     0,     8,    68,    69,     9,     0,
      11,    71,    75,    76,    79,    80,    81,     3,     0,     0,
      25,    25,     0,    20,     0,     0,    63,     7,   101,     0,
       6,   103,     0,    84,    85,    86,    87,   104,     0,    23,
      27,     0,    49,    54,    58,     0,    33,    34,     0,    25,
      59,    61,     0,    77,     0,    43,    45,     0,     0,     4,
       0,    13,     0,    72,     0,    83,    21,    25,    82,    24,
       0,    92,    93,    94,    95,    96,    97,     0,    36,    37,
      38,    39,    40,    41,    88,    46,     0,     0,    89,    90,
      91,    50,     0,     0,     0,     0,    29,    30,    25,    55,
       0,    56,     0,     0,     0,     0,     0,    18,     0,    19,
       0,     0,   102,     0,     6,     0,     0,    23,    27,    32,
      49,    49,    54,    54,    54,     0,     0,     0,    35,    60,
       0,     0,    78,     0,    43,    45,    64,    70,     0,     5,
      73,    74,    14,     0,    22,    26,    48,    47,    51,    52,
      53,    28,    31,    57,    62,    16,    25,    42,    44,    10,
       0,    17,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    37,    79,    18,    19,    16,    38,    58,
      86,    59,    89,    60,    97,   127,   129,    61,   105,    62,
     111,    63,    64,    39,     3,    24,    13,    28,    29,   158,
      40,    84,   162,   163,    41,    42,    74,   153,    43,    44,
      45,    90,    87,    65,    66,    67,    68,   107,   112,   113,
     114,    98,    99,   100,   101,   102,   103,     8,    21,    17,
      82,   149,    52,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
       0,   -77,     1,   -35,   -77,   -77,   -26,   -77,   -35,     8,
     -26,   -10,   -77,   -77,   -35,   -77,    -6,   -35,    29,   -26,
     -77,    49,   -10,   -77,    97,   -35,   -77,   -77,   -77,     4,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -26,    -1,
     111,   111,    35,   -77,   -35,   -35,     4,   -77,   -77,    10,
      97,   -77,    20,   -77,   -77,   -77,   -77,   -77,    48,    40,
      60,   144,    52,    -2,   -77,   119,   -77,   -77,    -4,   111,
     -77,     4,    35,   -77,    97,   -10,   -10,    20,    32,   -77,
     -26,   -77,    20,   -77,    97,   -77,   -77,   111,   -77,   -77,
     111,   -77,   -77,   -77,   -77,   -77,   -77,    20,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,    20,    20,   -77,   -77,
     -77,   -77,    20,    20,    20,   144,   -77,   -77,   111,   -77,
      20,   -77,    32,   133,    20,    97,    53,   -77,   -35,   -77,
     -35,    32,   -77,    76,    97,    32,    71,    40,    60,   -77,
      52,    52,    -2,    -2,    -2,    20,    32,    32,   -77,   -77,
      32,    53,   -77,    73,   -10,   -10,   -77,   -77,    87,   -77,
     -77,   -77,   -77,    97,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   111,   -77,   -77,   -77,
      89,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -68,   -32,    78,   109,    83,   -46,   -39,
     -19,    33,   -15,    31,     9,   -28,   -25,   -33,   -51,     2,
     -76,   -38,    51,   -36,   -77,   -77,   -77,   -20,   -77,   -77,
     -77,   -77,   -40,   -77,   -12,   -77,    74,     5,   -77,   -77,
     -77,   -77,   -77,   -77,    80,    82,   -42,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,    27,   -77,   -58,
     -17,   -18,   -77,   -34,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       6,     4,    72,     1,    80,    11,   126,     5,    75,    76,
       7,    11,    49,    12,    22,    78,   136,   128,   130,    81,
     106,    46,    11,    69,    69,   108,   109,   110,    15,    77,
     122,    20,   115,    23,   121,    48,   123,    14,     5,    57,
      51,    46,    46,    48,   131,    56,    25,    46,   118,   135,
      73,   120,    69,    57,   124,    26,    27,   151,    83,    48,
     133,    85,     5,    57,   139,    50,   168,   169,   170,   152,
      69,    46,   132,    69,   142,   143,   144,    56,   104,   146,
      88,    46,   160,   161,   157,   123,    32,   147,    80,   166,
     167,   150,   154,    26,   155,   180,   128,   130,   106,   106,
     160,    69,   159,    47,   148,    30,    31,   134,   140,   141,
      32,    33,   171,   156,    34,    35,    36,    10,   164,   119,
     137,   138,    46,   165,   145,    46,   177,    46,   172,   173,
     178,    46,   174,    53,    54,    55,    56,   181,   179,     5,
     182,   176,    54,    55,    56,   116,   125,   117,     0,     0,
      48,     0,     0,     5,    57,     0,   175,     0,    48,    69,
      46,     5,    57,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,   132,    91,    92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
       3,     0,    41,     3,    50,     8,    74,    42,    44,    45,
      36,    14,    29,     5,    17,    49,    84,    75,    76,    52,
      62,    24,    25,    40,    41,    27,    28,    29,    38,    46,
      69,    37,    65,     4,    68,    39,    69,    10,    42,    43,
      41,    44,    45,    39,    77,    25,    19,    50,    65,    82,
      15,    68,    69,    43,    71,     6,     7,   125,    10,    39,
      78,    21,    42,    43,    97,    38,   142,   143,   144,    16,
      87,    74,    40,    90,   112,   113,   114,    25,    26,   118,
      20,    84,    11,    12,     8,   118,    13,   120,   134,   140,
     141,   124,   128,     6,   130,   163,   154,   155,   140,   141,
      11,   118,   134,    25,   122,    22,     9,    80,   106,   107,
      13,    14,   145,   131,    17,    18,    19,     8,   137,    68,
      87,    90,   125,   138,   115,   128,   154,   130,   146,   147,
     155,   134,   150,    22,    23,    24,    25,   176,   158,    42,
     180,   153,    23,    24,    25,    65,    72,    65,    -1,    -1,
      39,    -1,    -1,    42,    43,    -1,   151,    -1,    39,   176,
     163,    42,    43,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    70,     0,    42,   110,    36,   103,    48,
      52,   110,     5,    72,   103,    38,    53,   105,    51,    52,
      37,   104,   110,     4,    71,   103,     6,     7,    73,    74,
      53,     9,    13,    14,    17,    18,    19,    49,    54,    69,
      76,    80,    81,    84,    85,    86,   110,    51,    39,   106,
     103,    41,   108,    22,    23,    24,    25,    43,    55,    57,
      59,    63,    65,    67,    68,    89,    90,    91,    92,   106,
     109,   110,    55,    15,    82,    69,    69,   106,   109,    50,
      54,    63,   106,    10,    77,    21,    56,    88,    20,    58,
      87,    30,    31,    32,    33,    34,    35,    60,    97,    98,
      99,   100,   101,   102,    26,    64,    92,    93,    27,    28,
      29,    66,    94,    95,    96,    63,    90,    91,   106,    68,
     106,   109,    55,    63,   106,    82,    49,    61,   105,    62,
     105,    63,    40,   107,   103,    63,    49,    57,    59,    63,
      65,    65,    67,    67,    67,    60,    55,    63,   107,   107,
      63,    49,    16,    83,    69,    69,   107,     8,    75,    50,
      11,    12,    78,    79,    56,    58,    64,    64,    66,    66,
      66,    63,   107,   107,   107,    83,    80,    61,    62,    73,
      49,    55,    78
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 117 "part3.y"
    { CreateFile((yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].CodeNCont)); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 120 "part3.y"
    {(yyval.CodeNCont) = (yyvsp[(5) - (5)].CodeNCont);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 123 "part3.y"
    {(yyval.CodeNCont) = StateSemiFunction((yyvsp[(1) - (3)].CodeNCont), (yyvsp[(3) - (3)].CodeNCont));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 126 "part3.y"
    {(yyval.CodeNCont) = StateSemiFunction((yyvsp[(1) - (3)].CodeNCont), (yyvsp[(3) - (3)].CodeNCont));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 127 "part3.y"
    {StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = new list<string*>(); (yyval.CodeNCont) = ret;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 134 "part3.y"
    {*(yyvsp[(1) - (4)].sval) = "_" + *(yyvsp[(1) - (4)].sval); varNames.push_back((yyvsp[(1) - (4)].sval));numConsecutiveInits++; DefineVarsAsArrays(NULL);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 135 "part3.y"
    {*(yyvsp[(1) - (9)].sval) = "_" + *(yyvsp[(1) - (9)].sval); varNames.push_back((yyvsp[(1) - (9)].sval));numConsecutiveInits++; DefineVarsAsArrays((yyvsp[(6) - (9)].sval));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 138 "part3.y"
    {*(yyvsp[(2) - (3)].sval) = "_" + *(yyvsp[(2) - (3)].sval); varNames.push_back((yyvsp[(2) - (3)].sval)); numConsecutiveInits++;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 143 "part3.y"
    { (yyval.CodeNCont) = AssignStatement((yyvsp[(1) - (3)].AVRet), (yyvsp[(3) - (3)].cav));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 144 "part3.y"
    { (yyval.CodeNCont) = IfStatement((yyvsp[(2) - (5)].cav), (yyvsp[(4) - (5)].CodeNCont)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 145 "part3.y"
    { (yyval.CodeNCont) = IfElseStatement((yyvsp[(2) - (7)].cav), (yyvsp[(4) - (7)].CodeNCont), (yyvsp[(6) - (7)].CodeNCont)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 146 "part3.y"
    { (yyval.CodeNCont) = WhileFunction((yyvsp[(4) - (5)].CodeNCont), (yyvsp[(2) - (5)].cav)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 147 "part3.y"
    { (yyval.CodeNCont) = DoWhileFunction((yyvsp[(3) - (6)].CodeNCont), (yyvsp[(6) - (6)].cav)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 148 "part3.y"
    {
																	(yyval.CodeNCont) = IOStatement("< ",  (yyvsp[(2) - (3)].AVRet), (yyvsp[(3) - (3)].CodeNCont));
																;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 151 "part3.y"
    {
																	(yyval.CodeNCont) = IOStatement("< ",  (yyvsp[(2) - (3)].AVRet), (yyvsp[(3) - (3)].CodeNCont));
																;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 154 "part3.y"
    {(yyval.CodeNCont) = NULL;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 157 "part3.y"
    {
														if((yyvsp[(2) - (2)].OpRet) == NULL){(yyval.cav) = (yyvsp[(1) - (2)].cav);} 
														else
														{ 
															CodeAndVar* ret = (yyvsp[(1) - (2)].cav); 
															OperationReturn* opRet = OperationFunction(NULL, (yyvsp[(1) - (2)].cav), (yyvsp[(2) - (2)].OpRet)); 
															ret->code = opRet->code; 
															ret->var = opRet->var; 
															(yyval.cav) = ret;
														}
													;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 170 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 171 "part3.y"
    {(yyval.OpRet) = NULL;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 174 "part3.y"
    {
														if((yyvsp[(2) - (2)].OpRet) == NULL){(yyval.cav) = (yyvsp[(1) - (2)].cav);} 
														else
														{ 
															CodeAndVar* ret = (yyvsp[(1) - (2)].cav); 
															OperationReturn* opRet = OperationFunction(NULL, (yyvsp[(1) - (2)].cav), (yyvsp[(2) - (2)].OpRet)); 
															ret->code = opRet->code; 
															ret->var = opRet->var; 
															(yyval.cav) = ret;
														}
													;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 185 "part3.y"
    {(yyval.cav) = NULL;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 188 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 189 "part3.y"
    {(yyval.OpRet) = NULL;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 192 "part3.y"
    {
														CodeAndVar* ret = (yyvsp[(4) - (4)].cav); ret->code->splice((yyvsp[(4) - (4)].cav)->code->begin(), *(yyvsp[(2) - (4)].cav)->code); 
														string* temp = nextTemp(); 
														ret->code->push_back(new string(*(yyvsp[(3) - (4)].sval) + " " + *temp + ", " + *(yyvsp[(2) - (4)].cav)->var + ", " + *(yyvsp[(4) - (4)].cav)->var) ); 
														ret->code->push_back(new string("! " + *temp + ", " + *temp) ); 
														ret->var = temp;
														(yyval.cav) = ret;
													;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 200 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); delete((yyvsp[(1) - (2)].sval)); *(yyvsp[(2) - (2)].sval) = "false"; ret->var = (yyvsp[(2) - (2)].sval); (yyval.cav) = ret; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 201 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); delete((yyvsp[(1) - (2)].sval)); *(yyvsp[(2) - (2)].sval) = "true";  ret->var = (yyvsp[(2) - (2)].sval); (yyval.cav) = ret; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 202 "part3.y"
    { CodeAndVar* ret = (yyvsp[(3) - (4)].cav); string* temp = nextTemp(); ret->code->push_back(new string("! " + *temp + ", " + *(yyvsp[(3) - (4)].cav)->var)); ret->var = temp;  (yyval.cav) = ret;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 204 "part3.y"
    { 
														CodeAndVar* ret = (yyvsp[(3) - (3)].cav); ret->code->splice((yyvsp[(3) - (3)].cav)->code->begin(), *(yyvsp[(1) - (3)].cav)->code); 
														string* temp = nextTemp(); 
														ret->code->push_back(new string(*(yyvsp[(2) - (3)].sval) + " " + *temp + ", " + *(yyvsp[(1) - (3)].cav)->var + ", " + *(yyvsp[(3) - (3)].cav)->var) ); 
														ret->var = temp;
														(yyval.cav) = ret;
													;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 211 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = (yyvsp[(1) - (1)].sval);  (yyval.cav) = ret; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 212 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = (yyvsp[(1) - (1)].sval);  (yyval.cav) = ret; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 213 "part3.y"
    {(yyval.cav) = (yyvsp[(2) - (3)].cav);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 216 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 217 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 218 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 219 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 220 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 221 "part3.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 224 "part3.y"
    { (yyval.CodeNCont) = IOStatement("< ",  (yyvsp[(2) - (3)].AVRet), (yyvsp[(3) - (3)].CodeNCont));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 225 "part3.y"
    { StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = NULL; (yyval.CodeNCont) = ret; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 228 "part3.y"
    { (yyval.CodeNCont) = IOStatement("> ",  (yyvsp[(2) - (3)].AVRet), (yyvsp[(3) - (3)].CodeNCont));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 229 "part3.y"
    { StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = NULL; (yyval.CodeNCont) = ret; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 232 "part3.y"
    { 
														CodeAndVar* ret = (yyvsp[(1) - (2)].cav); 
														OperationReturn* opRet = OperationFunction(NULL, (yyvsp[(1) - (2)].cav), (yyvsp[(2) - (2)].OpRet)); 
														ret->code = opRet->code; 
														ret->var = opRet->var; 
														(yyval.cav) = ret;
													;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 241 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 242 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 243 "part3.y"
    { OperationReturn* ret = NULL; (yyval.OpRet) = ret; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 246 "part3.y"
    { 
														CodeAndVar* ret = (yyvsp[(1) - (2)].cav); 
														OperationReturn* opRet = OperationFunction(NULL, (yyvsp[(1) - (2)].cav), (yyvsp[(2) - (2)].OpRet)); 
														ret->code = opRet->code; 
														ret->var = opRet->var; 
														(yyval.cav) = ret;
													;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 255 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 256 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 257 "part3.y"
    {(yyval.OpRet) = OperationFunction((yyvsp[(1) - (3)].sval), (yyvsp[(2) - (3)].cav), (yyvsp[(3) - (3)].OpRet));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 258 "part3.y"
    { OperationReturn* ret = NULL; (yyval.OpRet) = ret; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 261 "part3.y"
    { CodeAndVar* ret = (yyvsp[(2) - (2)].cav); string* temp = nextTemp(); ret->code->push_back( new string("- " + *temp + ", 0, " + *(yyvsp[(2) - (2)].cav)->var) ); ret->var = temp; (yyval.cav) = ret; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 262 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); *(yyvsp[(2) - (2)].sval) = "-" + *(yyvsp[(2) - (2)].sval); ret->var = (yyvsp[(2) - (2)].sval); (yyval.cav) = ret; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 263 "part3.y"
    { CodeAndVar* ret = (yyvsp[(3) - (4)].cav); string* temp = nextTemp(); ret->code->push_back( new string("- " + *temp + ", 0, " + *(yyvsp[(3) - (4)].cav)->var) ); ret->var = temp; (yyval.cav) = ret; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 264 "part3.y"
    { (yyval.cav) = (yyvsp[(1) - (1)].cav); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 265 "part3.y"
    { CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = (yyvsp[(1) - (1)].sval);  (yyval.cav) = ret; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 266 "part3.y"
    { (yyval.cav) = (yyvsp[(2) - (3)].cav);  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 269 "part3.y"
    {*(yyvsp[(1) - (1)].sval) = "_" + *(yyvsp[(1) - (1)].sval);ValidateIdent((yyvsp[(1) - (1)].sval), false); CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = (yyvsp[(1) - (1)].sval);  (yyval.cav) = ret; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 270 "part3.y"
    {*(yyvsp[(1) - (4)].sval) = "_" + *(yyvsp[(1) - (4)].sval);ValidateIdent((yyvsp[(1) - (4)].sval), true);  string* temp = nextTemp(); (yyvsp[(3) - (4)].cav)->code->push_back(new string("=[] " + (*temp) + ", "+ *(yyvsp[(1) - (4)].sval) + ", " + *(yyvsp[(3) - (4)].cav)->var)); (yyvsp[(3) - (4)].cav)->var = temp; (yyval.cav) = (yyvsp[(3) - (4)].cav); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 273 "part3.y"
    {*(yyvsp[(1) - (1)].sval) = "_" + *(yyvsp[(1) - (1)].sval);ValidateIdent((yyvsp[(1) - (1)].sval), false); AssignVarReturn* ret = new AssignVarReturn(); ret->var = (yyvsp[(1) - (1)].sval); ret->index = NULL;    ret->code = new list<string*>(); (yyval.AVRet) = ret;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 274 "part3.y"
    {*(yyvsp[(1) - (4)].sval) = "_" + *(yyvsp[(1) - (4)].sval);ValidateIdent((yyvsp[(1) - (4)].sval), true);  AssignVarReturn* ret = new AssignVarReturn(); ret->var = (yyvsp[(1) - (4)].sval); ret->index = (yyvsp[(3) - (4)].cav)->var; ret->code = (yyvsp[(3) - (4)].cav)->code;            (yyval.AVRet) = ret;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 277 "part3.y"
    {(yyval.sval) = new string("program");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 278 "part3.y"
    {(yyval.sval) = new string("beginprogram");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 279 "part3.y"
    {(yyval.sval) = new string("endprogram");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 280 "part3.y"
    {(yyval.sval) = new string("integer");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 281 "part3.y"
    {(yyval.sval) = new string("array");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 282 "part3.y"
    {(yyval.sval) = new string("of");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 283 "part3.y"
    {(yyval.sval) = new string("if");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 284 "part3.y"
    {(yyval.sval) = new string("then");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 285 "part3.y"
    {(yyval.sval) = new string("endif");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 286 "part3.y"
    {(yyval.sval) = new string("else");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 287 "part3.y"
    {(yyval.sval) = new string("while");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 288 "part3.y"
    {(yyval.sval) = new string("do");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 289 "part3.y"
    {(yyval.sval) = new string("beginloop");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 290 "part3.y"
    {(yyval.sval) = new string("endloop");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 291 "part3.y"
    {(yyval.sval) = new string("continue");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 292 "part3.y"
    {(yyval.sval) = new string("read");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 293 "part3.y"
    {(yyval.sval) = new string("write");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 294 "part3.y"
    {(yyval.sval) = new string("&&");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 295 "part3.y"
    {(yyval.sval) = new string("||");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 296 "part3.y"
    {(yyval.sval) = new string("not");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 297 "part3.y"
    {(yyval.sval) = new string("true");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 298 "part3.y"
    {(yyval.sval) = new string("false");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 299 "part3.y"
    {(yyval.sval) = new string("-");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 300 "part3.y"
    {(yyval.sval) = new string("+");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 301 "part3.y"
    {(yyval.sval) = new string("*");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 302 "part3.y"
    {(yyval.sval) = new string("/");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 303 "part3.y"
    {(yyval.sval) = new string("%");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 304 "part3.y"
    {(yyval.sval) = new string("==");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 305 "part3.y"
    {(yyval.sval) = new string("!=");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 306 "part3.y"
    {(yyval.sval) = new string("<");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 307 "part3.y"
    {(yyval.sval) = new string(">");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 308 "part3.y"
    {(yyval.sval) = new string("<=");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 309 "part3.y"
    {(yyval.sval) = new string(">=");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 310 "part3.y"
    {(yyval.sval) = new string(";");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 311 "part3.y"
    {(yyval.sval) = new string(":");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 312 "part3.y"
    {(yyval.sval) = new string(",");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 313 "part3.y"
    {(yyval.sval) = new string("(");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 314 "part3.y"
    {(yyval.sval) = new string(")");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 315 "part3.y"
    {(yyval.sval) = new string(":=");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 316 "part3.y"
    {(yyval.sval) = yyval.sval;;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 317 "part3.y"
    {(yyval.sval) = yyval.sval;;}
    break;



/* Line 1455 of yacc.c  */
#line 2400 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 320 "part3.y"


string* nextTemp()
{
	stringstream ss;
	ss << "t" << tempVars.size();
	string* retMe = new string(ss.str());
	tempVars.push_back(retMe);
	return retMe;
}

string nextLabel()
{
	stringstream ss;
	ss << "L" << labelCount++;
	string retMe = ss.str();
	return retMe;
}

void DefineVarsAsArrays(string* length)
{
	for(int i = 0; i < numConsecutiveInits; i++)
	{
		varArraySize.push_back(length);
	}
	numConsecutiveInits = 0;
}

void ValidateIdent(string* ident, bool checkingArray)
{
	for(int i = 0; i < varNames.size(); i++)
	{
		if((*varNames[i]) == (*ident))
		{
			if(!checkingArray )
			{
				return;
			}
			else if(!varArraySize[i])
			{
				cout << "var " << *ident << " is not an array! "<< endl;
				exit(1);
			}
			else{return;}
		}
	}
	cout << "Invalid var " << *ident << endl;
	exit(1);
}

StateSemiReturn* StateSemiFunction(StateSemiReturn* statement, StateSemiReturn* prev)
{
	StateSemiReturn* ret = prev;
	//If the last statement was a continue statement
	if(prev == NULL)
	{
		string* cont = new string("");
		if(statement == NULL)
		{
			ret = new StateSemiReturn();
			ret->code = new list<string*>();
			ret->continues = new list<string*>();
			ret->code->push_back(cont);
			ret->continues->push_back(cont);
			cont = new string("");
		}
		else
		{
			ret = statement;
		}
		ret->code->push_back(cont);
		ret->continues->push_back(cont);
	}
	//If Statement was a CONTINUE statement
	else if(statement == NULL)
	{
		//Add a blank string for now, in both the code and the vector of continues
		string* cont = new string("");
		ret->continues->push_back(cont);
		ret->code->push_front(cont);
	}
	else
	{
		//If not a continue, just copy over the list of strings (code)
		//Statement
		ret->code->splice(ret->code->begin(), *statement->code);
		/*cout << "===================================\n";
		PrintAll(ret->code);
		cout << "-----------------------------------\n";*/
	}
	return ret;
}

StateSemiReturn* IOStatement(string opType, AssignVarReturn* avr, StateSemiReturn* nextIOStatement)
{
	StateSemiReturn* ret = nextIOStatement;
	string* lineOfCode;
	if(avr->index)
	{
		ret->code->splice(ret->code->begin(), *avr->code);
		ret->code->push_back( new string(".[]" + opType + " " + *(avr->var) + ", " + *(avr->index)) );
	}
	else
	{
		ret->code->push_back( new string("." + opType + " " + *(avr->var)) );
	}

	return ret;
}

void CreateFile(string* filename, StateSemiReturn* statements)
{
	std::filebuf fb;
	fb.open ((*filename + ".mil").c_str(),std::ios::out);
	std::ostream outputFile(&fb);

	for(int i = 0; i < varNames.size(); i++)
	{

		if(varArraySize[i]){ outputFile << "\t.[] " << *varNames[i] << ", " << *varArraySize[i];}
		else{outputFile << "\t. " << *varNames[i];}
		
		outputFile << endl;
	}
	outputFile << ": START\n";
	for(list<string*>::iterator i = statements->code->begin(); i != statements->code->end(); i++)
	{
		if(! ( ((*i)->length() > 3) && ((**i)[0] == ':') && ((**i)[1] == ' ') && ((**i)[2] == 'L') ) )
		{
			outputFile << "\t";
		}
		outputFile << **i << endl;
	}
	fb.close();
}

StateSemiReturn* AssignStatement(AssignVarReturn* avr, CodeAndVar* expr)
{
	StateSemiReturn* ret = new StateSemiReturn();
	ret->code = avr->code;
	ret->continues = NULL;
	ret->code->splice(ret->code->begin(), *(expr->code));
	if(avr->index)
	{
		ret->code->push_back( new string("[]= " + *avr->var + ", " + *avr->index + ", " + *expr->var) );
	}
	else
	{
		ret->code->push_back( new string("= " + *avr->var + ", " + *expr->var) );
	}
	return ret;
}

StateSemiReturn* IfStatement(CodeAndVar* boolExp, StateSemiReturn* statements )
{
	StateSemiReturn* ret = statements;
	string* temp = nextTemp();
	string label = nextLabel();
	ret->code->push_front(new string("?:= " + label + ", " + *temp)); 
	ret->code->push_front(new string("! " + *temp + ", " + *boolExp->var) );
	ret->code->splice(ret->code->begin(), *boolExp->code);
	ret->code->push_back(new string(": " + label)); 
	return ret;
}

StateSemiReturn* IfElseStatement(CodeAndVar* boolExp, StateSemiReturn* ifStatements, StateSemiReturn* elseStatements)
{
	StateSemiReturn* ret = ifStatements;
	string* temp = nextTemp();
	string labelIf = nextLabel();
	string labelElse = nextLabel();
	ret->code->push_front(new string("?:= " + labelElse + ", " + *temp)); 
	ret->code->push_front(new string("! " + *temp + ", " + *boolExp->var) );
	ret->code->splice(ret->code->begin(), *boolExp->code);
	ret->code->push_back(new string(":= " + labelIf));
	ret->code->push_back(new string(": " + labelElse));
	ret->code->splice(ret->code->begin(), *elseStatements->code);
	ret->code->push_back(new string(": " + labelIf));
	ret->continues->splice(ret->continues->end(), *elseStatements->continues);
	
	return ret;
}

StateSemiReturn* DoWhileFunction(StateSemiReturn* stateRet, CodeAndVar* boolExp)
{
	StateSemiReturn* ret = stateRet;
	string topLabel = nextLabel();
	string condLabel = nextLabel();
	ret->code->push_front(new string(": " + topLabel));
	for(list<string*>::iterator i = ret->continues->begin(); i != ret->continues->end(); i++)
	{
		(**i) = ":= " + condLabel;
	}
	ret->code->push_back(new string(": " + condLabel));
	ret->code->splice(ret->code->end(), *boolExp->code);
	ret->code->push_back(new string("?: " + topLabel + ", " + *boolExp->var));

	delete ret->continues;
	ret->continues = NULL;
	return ret;
}

StateSemiReturn* WhileFunction(StateSemiReturn* stateRet, CodeAndVar* boolExp)
{
	StateSemiReturn* ret = stateRet;
	string topLabel = nextLabel();
	string botLabel = nextLabel();
	string* temp = nextTemp();
	//This segment is read bottom to top
	ret->code->push_front( new string(":?= " + botLabel + ", " + *temp));
	ret->code->push_front(new string("! " + *temp + ", " + *boolExp->var));
	ret->code->splice(ret->code->begin(), *boolExp->code);
	ret->code->push_front(new string(": " + topLabel));
	
	ret->code->push_back(new string(":= " + topLabel));
	ret->code->push_back(new string(": " + botLabel));

	
	for(list<string*>::iterator i = ret->continues->begin(); i != ret->continues->end(); i++)
	{
		(**i) = ":= " + topLabel;
	}
	delete ret->continues;
	ret->continues = NULL;
	return ret;
}

void PrintAll(list<string*>* code)
{
	for(list<string*>::iterator i = code->begin(); i != code->end(); i++)
	{
		if(! ( ((*i)->length() > 3) && ((**i)[0] == ':') && ((**i)[1] == ' ') && ((**i)[2] == 'L') ) )
		{
			cout << "\t";
		}
		cout << **i << endl;
	}
}

OperationReturn* OperationFunction(string* input1, CodeAndVar* input2, OperationReturn* input3)
{
	OperationReturn* ret = input3;
	if(input3 != NULL)
	{
		string* temp = nextTemp();
		ret->code->splice(ret->code->end(), *input2->code);
		ret->code->push_back( new string(*(input3->opType) + " " + *(temp) + ", " + (*input2->var) +", " + *(input3->var)) );
		*(ret->var) = *temp;
	}
	else
	{
		ret = new OperationReturn();
		ret->code = input2->code;
		ret->var = input2->var;
	}
	ret->opType = input1;
	return ret;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
    if (yyin == NULL){
      printf("syntax: %s filename\n", argv[0]);
    }//end if
  }//end if
  yyparse(); // Calls yylex() for tokens.
  return 0;
}

void yyerror(const char *msg) {
  printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}


