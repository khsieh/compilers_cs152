/*Mark De Ruyter*/
/*861068723*/
/*flex calc.lex; gcc lex.yy.c -lfl*/

%{   
  #include "y.tab.h"
  #include <string>
  extern int yylex();
  int currLine = 1, currPos = 1;
  int numNumbers = 0;
  int numOperators = 0;
  int numParens = 0;
  int numEquals = 0;
%}

DIGIT    [0-9]
%x LEXING_ERROR
%%

"program" {currPos += yyleng; return PROGRAM;}
"beginprogram" {currPos += yyleng; return BEGIN_PROGRAM;}
"endprogram" {currPos += yyleng; return END_PROGRAM;}
"integer" {currPos += yyleng; return INTEGER;}
"array" {currPos += yyleng; return ARRAY;}
"of" {currPos += yyleng; return OF;}
"if" {currPos += yyleng; return IF;}
"then" {currPos += yyleng; return THEN;}
"endif" {currPos += yyleng; return ENDIF;}
"else" {currPos += yyleng; return ELSE;}
"while" {currPos += yyleng; return WHILE;}
"do" {currPos += yyleng; return DO;}

"beginloop" {currPos += yyleng; return BEGINLOOP;}
"endloop" {currPos += yyleng; return ENDLOOP;}
"continue" {currPos += yyleng; return CONTINUE;}
"read" {currPos += yyleng; return READ;}
"write" {currPos += yyleng; return WRITE;}
"and" {currPos += yyleng; return AND;}
"or" {currPos += yyleng; return OR;}
"not" {currPos += yyleng; return NOT;}
"true" {currPos += yyleng; return TRUE;}
"false" {currPos += yyleng; return FALSE;}

"-" {currPos += yyleng; return SUB;}
"+" {currPos += yyleng; return ADD;}
"*" {currPos += yyleng; return MULT;}
"/" {currPos += yyleng; return DIV;}
"%" {currPos += yyleng; return MOD;}

"==" {currPos += yyleng; return EQ;}
"<>" {currPos += yyleng; return NEQ;}
"<"  {currPos += yyleng; return LT;}
">"  {currPos += yyleng; return GT;}
"<=" {currPos += yyleng; return LTE;}
">=" {currPos += yyleng; return GTE;}

[A-Za-z]|([A-Za-z][A-Za-z0-9_]*[A-Za-z0-9]) { yylval.sval = new std::string(yytext); return IDENT;}
{DIGIT}+ { yylval.sval = new std::string(yytext); currPos += yyleng; return NUMBER;}

";" {currPos += yyleng; return SEMICOLON;}
":" {currPos += yyleng; return COLON;}
"," {currPos += yyleng; return COMMA;}
"(" {currPos += yyleng; return L_PAREN;}
")" {currPos += yyleng; return R_PAREN;}
":=" {currPos += yyleng; return ASSIGN;}
"##".*"\n" {currPos = 1; currLine++;}


[ \t]+ {/* ignore spaces */ currPos += yyleng;}

"\n" {currLine++; currPos = 1;}

.                 { BEGIN(LEXING_ERROR); yyless(1); }
<LEXING_ERROR>.+  { fprintf(stderr,
                            "Invalid character '%c' found at line %d,"
                            " just before '%s'\n",
                            *yytext, currLine, yytext+1);
                    exit(1);
                  }

%%

/*int main(int argc, char ** argv)
{
  if(argc >= 2)
    {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL)
	{
	  yyin = stdin;
	}
    }
  else
    {
      yyin = stdin;
    }
   
  yylex();
}*/
