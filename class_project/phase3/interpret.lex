/*Mark De Ruyter*/
/*861068723*/
/*flex calc.lex; gcc lex.yy.c -lfl*/

%{   
  int currLine = 1, currPos = 1;
  int numNumbers = 0;
  int numOperators = 0;
  int numParens = 0;
  int numEquals = 0;
%}

DIGIT    [0-9]
%x LEXING_ERROR
%%

"program" {printf("PROGRAM\n"); currPos += yyleng;}
"beginprogram" {printf("BEGIN_PROGRAM\n"); currPos += yyleng;}
"endprogram" {printf("END_PROGRAM\n"); currPos += yyleng;}
"integer" {printf("INTEGER\n"); currPos += yyleng;}
"array" {printf("ARRAY\n"); currPos += yyleng;}
"of" {printf("OF\n"); currPos += yyleng;}
"if" {printf("IF\n"); currPos += yyleng;}
"then" {printf("THEN\n"); currPos += yyleng;}
"endif" {printf("ENDIF\n"); currPos += yyleng;}
"else" {printf("ELSE\n"); currPos += yyleng;}
"while" {printf("WHILE\n"); currPos += yyleng;}
"do" {printf("DO\n"); currPos += yyleng;}

"beginloop" {printf("BEGINLOOP\n"); currPos += yyleng;}
"endloop" {printf("ENDLOOP\n"); currPos += yyleng;}
"continue" {printf("CONTINUE\n"); currPos += yyleng;}
"read" {printf("READ\n"); currPos += yyleng;}
"write" {printf("WRITE\n"); currPos += yyleng;}
"and" {printf("AND\n"); currPos += yyleng;}
"or" {printf("OR\n"); currPos += yyleng;}
"not" {printf("NOT\n"); currPos += yyleng;}
"true" {printf("TRUE\n"); currPos += yyleng;}
"false" {printf("FALSE\n"); currPos += yyleng;}

"-" {printf("SUB\n"); currPos += yyleng;}
"+" {printf("ADD\n"); currPos += yyleng;}
"*" {printf("MULT\n"); currPos += yyleng;}
"/" {printf("DIV\n"); currPos += yyleng;}
"%" {printf("MOD\n"); currPos += yyleng;}

"==" {printf("EQ\n"); currPos += yyleng;}
"<>" {printf("NEQ\n"); currPos += yyleng;}
"<" {printf("LT\n"); currPos += yyleng;}
">" {printf("GT\n"); currPos += yyleng;}
"<=" {printf("LTE\n"); currPos += yyleng;}
">=" {printf("GTE\n"); currPos += yyleng;}

[A-Za-z][A-Za-z0-9_]* {printf("IDENT %s\n", yytext); currPos += yyleng;}
{DIGIT}+ {printf("NUMBER %s\n", yytext); currPos += yyleng;}

";" {printf("SEMICOLON\n"); currPos += yyleng;}
":" {printf("COLON\n"); currPos += yyleng;}
"," {printf("COMMA\n"); currPos += yyleng;}
"(" {printf("L_PAREN\n"); currPos += yyleng;}
")" {printf("R_PAREN\n"); currPos += yyleng;}
":=" {printf("ASSIGN\n"); currPos += yyleng;}


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

int main(int argc, char ** argv)
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
   
  printf("# Numbers: %d\n", numNumbers);
  printf("# Operators: %d\n", numOperators);
  printf("# Parentheses: %d\n", numParens);
  printf("# Equal Signs: %d\n", numEquals);
}
