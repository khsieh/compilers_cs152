/* cs152-winter16 */
/* Class project Phase 1 */
/* Kevin Hsieh, khsie003 */
/* 861054367 */

%{
  /* Definitions */
  int currLine = 1, currPos = 1;
  int numNumbers = 0;
  int numOperators = 0;
  int numReserved = 0;
  int numComparisons = 0;
  int numSpecials = 0;
  int numID = 0;
  int numComments = 0;
%}

DIGIT    [0-9]
ID       [a-z][a-z0-9]*

%%
  /* RULES */
  /* RESERVED WORDS */
"program"      {printf("PROGRAM\n"); currPos += yyleng; numReserved++;}
"beginprogram" {printf("BEGIN_PROGRAM\n"); currPos += yyleng; numReserved++;}
"endprogram"   {printf("END_PROGRAM\n"); currPos += yyleng; numReserved++;}
"integer"      {printf("INTEGER\n"); currPos += yyleng; numReserved++;}
"array"        {printf("ARRAY\n"); currPos += yyleng; numReserved++;}
"of"           {printf("OF\n"); currPos += yyleng; numReserved++;}
"if"           {printf("IF\n"); currPos += yyleng; numReserved++;}
"then"         {printf("THEN\n"); currPos += yyleng; numReserved++;}
"endif"        {printf("ENDIF\n"); currPos += yyleng; numReserved++;}
"else"         {printf("ELSE\n"); currPos += yyleng; numReserved++;}
"while"        {printf("WHILE\n"); currPos += yyleng; numReserved++;}
"beginloop"    {printf("BEGINLOOP\n"); currPos += yyleng; numReserved++;}
"endloop"      {printf("ENDLOOP\n"); currPos += yyleng; numReserved++;}
"read"         {printf("READ\n"); currPos += yyleng; numReserved++;}
"write"        {printf("WRITE\n"); currPos += yyleng; numReserved++;}
"and"          {printf("AND\n"); currPos += yyleng; numReserved++;}
"or"           {printf("OR\n"); currPos += yyleng; numReserved++;}
"not"          {printf("NOT\n"); currPos += yyleng; numReserved++;}
"true"         {printf("TRUE\n"); currPos += yyleng; numReserved++;}
"false"        {printf("FALSE\n"); currPos += yyleng; numReserved++;}
"continue"     {printf("CONTINUE\n"); currPos += yyleng; numReserved++;}
"exit"         {printf("EXIT\n"); currPos += yyleng; numReserved++;}

   /* ARITHMETIC OPERATORS */
"-"            {printf("SUB\n"); currPos += yyleng; numOperators++;}
"+"            {printf("ADD\n"); currPos += yyleng; numOperators++;}
"*"            {printf("MULT\n"); currPos += yyleng; numOperators++;}
"/"            {printf("DIV\n"); currPos += yyleng; numOperators++;}
"%"            {printf("MOD\n"); currPos += yyleng; numOperators++;}
"?"            {printf("QUESTION\n"); currPos+= yyleng; numOperators++;}

  /* COMPARISON OPERATORS */
"=="            {printf("EQ\n"); currPos += yyleng; numComparisons++;}
"<>"           {printf("NEQ\n"); currPos += yyleng; numComparisons++;}
"<"            {printf("LT\n"); currPos += yyleng; numComparisons++;}
">"            {printf("GT\n"); currPos += yyleng; numComparisons++;}
"<="           {printf("LTE\n"); currPos += yyleng; numComparisons++;}
">="           {printf("GTE\n"); currPos += yyleng; numComparisons++;}

  /* SPECIAL SYMBOLS */
";"            {printf("SEMICOLON\n"); currPos += yyleng; numSpecials++;}
":"            {printf("COLON\n"); currPos += yyleng; numSpecials++;}
","            {printf("COMMA\n"); currPos += yyleng; numSpecials++;}
"("            {printf("L_PAREN\n"); currPos += yyleng; numSpecials++;}
")"            {printf("R_PAREN\n"); currPos += yyleng; numSpecials++;}
"["            {printf("L_BRACKET\n"); currPos += yyleng; numSpecials++;}
"]"            {printf("R_BRACKET\n"); currPos += yyleng; numSpecials++;}
":="           {printf("ASSIGN\n"); currPos += yyleng; numSpecials++;}

  /* DIGITS */
(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?) {printf("NUMBER %s\n", yytext); currPos += yyleng; numNumbers++;}

  /* IDENTIFIERS */
{ID}|{ID}*\_?{ID}           {printf("IDENT %s\n", yytext); currPos += yyleng; numID++;}

  /* COMMENTS */
"##".*        {/* one line comments */ numComments++;}

  /* TABS */
[ \t]+         {/* ignore spaces */ currPos += yyleng;}

  /* LINE FEED */
"\n"           {currLine++; currPos = 1;}

  /* ERROR MESSAGE */
.              {printf("Error at line %d, column %d: unrecongized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%

   /* USER CODE */
int main(int argc, char ** argv)
{
  if(argc>=2)
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
  /*
  printf("# Numbers: %d\n", numNumbers);
  printf("# Operators: %d\n", numOperators);
  printf("# Parentheses: %d\n", numParens);
  printf("# Reserved Words: %d\n", numReserved);
  printf("# Equal Signs: %d\n", numComparisons);
  */
}
