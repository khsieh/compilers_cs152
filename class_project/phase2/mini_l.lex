/* cs152-winter16 */
/* Class project Phase 2 */
/* Kevin Hsieh, khsie003 */
/* 861054367 */

%{
  /* Definitions */
  #include "y.tab.h"
  int currLine = 1, currPos = 1;
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*
COMMENT  [^A-Z0-9a-z\n]

%%

"program"      {printf("PROGRAM\n"); currPos += yyleng; return PROGRAM;}
"beginprogram" {printf("BEGIN_PROGRAM\n"); currPos += yyleng; return BEGIN_PROGRAM;}
"endprogram"   {printf("END_PROGRAM\n"); currPos += yyleng; return END_PROGRAM;}
"integer"      {printf("INTEGER\n"); currPos += yyleng; return INTEGER;}
"array"        {printf("ARRAY\n"); currPos += yyleng; return ARRAY;}
"of"           {printf("OF\n"); currPos += yyleng; return OF;}
"if"           {printf("IF\n"); currPos += yyleng; return IF;}
"then"         {printf("THEN\n"); currPos += yyleng; return THEN;}
"endif"        {printf("ENDIF\n"); currPos += yyleng; return END_IF;}
"else"         {printf("ELSE\n"); currPos += yyleng; return ELSE;}
"while"        {printf("WHILE\n"); currPos += yyleng; return WHILE;}
"beginloop"    {printf("BEGINLOOP\n"); currPos += yyleng; return BEGIN_LOOP;}
"endloop"      {printf("ENDLOOP\n"); currPos += yyleng; return END_LOOP;}
"read"         {printf("READ\n"); currPos += yyleng; return READ;}
"write"        {printf("WRITE\n"); currPos += yyleng; return WRITE;}
"and"          {printf("AND\n"); currPos += yyleng; return AND;}
"or"           {printf("OR\n"); currPos += yyleng; return OR;}
"not"          {printf("NOT\n"); currPos += yyleng; return NOT;}
"true"         {printf("TRUE\n"); currPos += yyleng; return TRUE;}
"false"        {printf("FALSE\n"); currPos += yyleng; return FALSE;}
"continue"     {printf("CONTINUE\n"); currPos += yyleng; return CONTINUE;}
"exit"         {printf("EXIT\n"); currPos += yyleng; return EXIT;}

"-"            {printf("SUB\n"); currPos += yyleng; return SUB;}
"+"            {printf("ADD\n"); currPos += yyleng; return ADD;}
"*"            {printf("MULT\n"); currPos += yyleng; return MULT;}
"/"            {printf("DIV\n"); currPos += yyleng; return DIV;}
"%"            {printf("MOD\n"); currPos += yyleng; return MOD;}
"?"            {printf("QUESTION\n"); currPos+= yyleng; return QUESTION;}

"="            {printf("EQ\n"); currPos += yyleng; return EQ;}
"<>"           {printf("NEQ\n"); currPos += yyleng; return NEQ;}
"<"            {printf("LT\n"); currPos += yyleng; return LT;}
">"            {printf("GT\n"); currPos += yyleng; return GT;}
"<="           {printf("LTE\n"); currPos += yyleng; return LTE;}
">="           {printf("GTE\n"); currPos += yyleng; return GTE;}

";"            {printf("SEMICOLON\n"); currPos += yyleng; return SEMICOLON;}
":"            {printf("COLON\n"); currPos += yyleng; return COLON;}
","            {printf("COMMA\n"); currPos += yyleng; return COMMA; }
"("            {printf("L_PAREN\n"); currPos += yyleng; return L_PAREN;}
")"            {printf("R_PAREN\n"); currPos += yyleng; return R_PAREN;}
"["            {printf("L_BRACKET\n"); currPos += yyleng; return L_BRACKET;}
"]"            {printf("R_BRACKET\n"); currPos += yyleng; return R_BRACKET;}
":="           {printf("ASSIGN\n"); currPos += yyleng; return ASSIGN;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?) {currPos += yyleng; return NUMBER;}

{ID}           {printf("IDENT %s\n", yytext); currPos += yyleng; return IDENT;} 

"##".*        {/* one line comments */}

[ \t]+         {/* ignore spaces */ currPos += yyleng;}

"\n"           {currLine++; currPos = 1;}

.              {printf("Error at line %d, column %d: unrecongized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%
