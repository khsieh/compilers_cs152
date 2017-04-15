/* calculator. */
%{
 #include <stdio.h>
 #include <stdlib.h>
  void yyerror(const char *msg);
  extern int currLine;
  extern int currPos;
  extern char* yytext;
  FILE * yyin;
  int prodNum = 0;
  %}

%union{
  char* sval;
  int ival;
 }

%error-verbose
%start Program
%token PROGRAM BEGIN_PROGRAM END_PROGRAM INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
%token <sval> IDENT
%token <ival> NUMBER
%left LT GT NEQ EQ GTE LTE
%left PLUS MINUS
%left MULT DIV

%%

Program:	_PROGRAM _IDENT _SEMICOLON Block _END_PROGRAM	{printf("%i: program -> program ident semicolon block endprogram\n", ++prodNum);}
		;

Block:		Declaration _SEMICOLON DecSemi _BEGIN_PROGRAM StateSemiP	{printf("%i: declaration -> declaration semicolon beginprogram statement semicolon\n", ++prodNum);}
		;

StateSemiP:	Statement _SEMICOLON StateSemi	{printf("%i: statesemi -> statement semicolon statement\n", ++prodNum);}
		; 

StateSemi:	Statement _SEMICOLON StateSemi {printf("%i: statesemi -> statement semicolon statement\n", ++prodNum);}
		| {printf("%i: statement -> \n", ++prodNum);}
		;

DecSemi:	Declaration _SEMICOLON DecSemi 	{printf("%i: declaration -> declaration semicolon declaration\n", ++prodNum);}
		|				{printf("%i: declaration -> declaration semicolon declaration\n", ++prodNum);}
		;

Declaration:	_IDENT Comm_IDENT _COLON _INTEGER						{printf("%i: declaration -> identifier commaident colon integer\n", ++prodNum);}
		| _IDENT Comm_IDENT _COLON _ARRAY _L_PAREN _NUMBER _R_PAREN _OF _INTEGER	{printf("%i: declaration -> identifier commaident colon array lparen number rparen of integer\n", ++prodNum);}
		;

Comm_IDENT:	_COMMA _IDENT Comm_IDENT	{printf("%i: commaident -> comma identifier commaident\n", ++prodNum);}
		|				{printf("%i: commaident -> \n", ++prodNum);}
		;

Statement:	Var _ASSIGN Expression						{printf("%i: statement -> var assign expression\n", ++prodNum);}
		| _IF BoolExp _THEN StateSemiP _ENDIF				{printf("%i: statement -> if boolexp then statesemi endif\n", ++prodNum);}
		| _IF BoolExp _THEN StateSemiP _ELSE StateSemiP _ENDIF		{printf("%i: statement -> if boolexp then statesemi else statesemi endif\n", ++prodNum);}
		| _WHILE BoolExp _BEGINLOOP StateSemiP _ENDLOOP			{printf("%i: statement -> while boolexp beginloop statesemi endloop\n", ++prodNum);}
		| _DO _BEGINLOOP StateSemiP _ENDLOOP _WHILE BoolExp		{printf("%i: statement -> do beginloop statesemi endloop while boolexp\n", ++prodNum);}
		| _READ Var ComVar						{printf("%i: statement -> read var comvar\n", ++prodNum);}
		| _WRITE Var ComVar						{printf("%i: statement -> write var comvar\n", ++prodNum);}
		| _CONTINUE							{printf("%i: statement -> continue\n", ++prodNum);}
		;

BoolExp:	RelationAndExp OrRelExp						{printf("%i: boolexp -> relandexp orrelexp\n", ++prodNum);}
		;

OrRelExp:	_OR RelationAndExp OrRelExp					{printf("%i: orrelexp -> or relandexp orrelexp\n", ++prodNum);}
		|								{printf("%i: orrelexp -> \n", ++prodNum);}
		;

RelationAndExp:	RelationExp AndRelExp						{printf("%i: relandexp -> relationexp andrelexp\n", ++prodNum);}
		|
		;

AndRelExp:	_AND RelationExp AndRelExp					{printf("%i: andrelexp -> and relationexp andrelexp\n", ++prodNum);}
		|								{printf("%i: andrelexp -> \n", ++prodNum);}
		;

RelationExp:	_NOT Expression Comp Expression					{printf("%i: relationexp -> not expression comp expression\n", ++prodNum);}
		| _NOT _TRUE							{printf("%i: relationexp -> not true\n", ++prodNum);}
		| _NOT _FALSE							{printf("%i: relationexp -> not false\n", ++prodNum);}
		| _NOT _L_PAREN BoolExp _R_PAREN				{printf("%i: relationexp -> not lparen boolexp rparen\n", ++prodNum);}
		| Expression Comp Expression					{printf("%i: relationexp -> expression comp expression\n", ++prodNum);}
		| _TRUE								{printf("%i: relationexp -> true\n", ++prodNum);}
		| _FALSE							{printf("%i: relationexp -> false\n", ++prodNum);}
		| _L_PAREN BoolExp _R_PAREN					{printf("%i: relationexp -> lparen boolexp rparen\n", ++prodNum);}
		;

Comp:		_EQ								{printf("%i: comp -> eq\n", ++prodNum);}
		| _NEQ								{printf("%i: comp -> neq\n", ++prodNum);}
		| _LT								{printf("%i: comp -> lt\n", ++prodNum);}
		| _GT								{printf("%i: comp -> gt\n", ++prodNum);}
		| _LTE								{printf("%i: comp -> lte\n", ++prodNum);}
		| _GTE								{printf("%i: comp -> gte\n", ++prodNum);}
		;

ComVar:		_COMMA Var ComVar						{printf("%i: comvar -> comma var comvar\n", ++prodNum);}
		|								{printf("%i: comvar -> \n", ++prodNum);}
		;

Expression:	MultExp AddMultExp						{printf("%i: expression -> multexp addmultexp\n", ++prodNum);}
		;

AddMultExp:	_ADD MultExp AddMultExp						{printf("%i: addmultexp -> add multexp\n", ++prodNum);}
		| _SUB MultExp AddMultExp					{printf("%i: addmultexp -> sub multexp\n", ++prodNum);}
		|								{printf("%i: addmultexp -> \n", ++prodNum);}
		;

MultExp:	Term MultTerm							{printf("%i: multexp -> term multterm\n", ++prodNum);}
		;

MultTerm:	_MULT Term MultTerm						{printf("%i: multterm -> mult term multterm\n", ++prodNum);}
		| _DIV Term MultTerm						{printf("%i: multterm -> div term multterm\n", ++prodNum);}
		| _MOD Term MultTerm						{printf("%i: multterm -> mod term multterm\n", ++prodNum);}
		|								{printf("%i: multterm -> \n", ++prodNum);}
		;

Term:		_SUB Var							{printf("%i: term -> sub var\n", ++prodNum);}
		| _SUB _NUMBER							{printf("%i: term -> sub number\n", ++prodNum);}
		| _SUB _L_PAREN Expression _R_PAREN				{printf("%i: term -> sub lparen expression rparen\n", ++prodNum);}
		| Var								{printf("%i: term -> var\n", ++prodNum);}
		| _NUMBER							{printf("%i: term -> number\n", ++prodNum);}
		| _L_PAREN Expression _R_PAREN					{printf("%i: term -> lparen expression rparen\n", ++prodNum);}
		;

Var:		_IDENT								{printf("%i: var -> ident\n", ++prodNum);}
		| _IDENT _L_PAREN Expression _R_PAREN				{printf("%i: var -> ident lparen expression rparen\n", ++prodNum);}
		;

_PROGRAM:	PROGRAM 	{printf("%i: program -> PROGRAM\n", ++prodNum);}
_BEGIN_PROGRAM:	BEGIN_PROGRAM	{printf("%i: beginprogram -> BEGIN_PROGRAM\n", ++prodNum);}
_END_PROGRAM:	END_PROGRAM	{printf("%i: endprogram -> END_PROGRAM\n", ++prodNum);}
_INTEGER:	INTEGER		{printf("%i: integer -> INTEGER\n", ++prodNum);}
_ARRAY:		ARRAY		{printf("%i: array -> ARRAY\n", ++prodNum);}
_OF:		OF		{printf("%i: of -> OF\n", ++prodNum);}
_IF:		IF		{printf("%i: if -> IF\n", ++prodNum);}
_THEN:		THEN		{printf("%i: then -> THEN\n", ++prodNum);}
_ENDIF:		ENDIF		{printf("%i: endif -> ENDIF\n", ++prodNum);}
_ELSE:		ELSE		{printf("%i: else -> ELSE\n", ++prodNum);}
_WHILE:		WHILE		{printf("%i: while -> WHILE\n", ++prodNum);}
_DO:		DO		{printf("%i: do -> DO\n", ++prodNum);}
_BEGINLOOP:	BEGINLOOP	{printf("%i: beginloop -> BEGINLOOP\n", ++prodNum);}
_ENDLOOP:	ENDLOOP		{printf("%i: endloop -> ENDLOOP\n", ++prodNum);}
_CONTINUE:	CONTINUE	{printf("%i: continue -> CONTINUE\n", ++prodNum);}
_READ:		READ		{printf("%i: read -> READ\n", ++prodNum);}
_WRITE:		WRITE		{printf("%i: write -> WRITE\n", ++prodNum);}
_AND:		AND		{printf("%i: and -> AND\n", ++prodNum);}
_OR:		OR		{printf("%i: or -> OR\n", ++prodNum);}
_NOT:		NOT		{printf("%i: not -> NOT\n", ++prodNum);}
_TRUE:		TRUE		{printf("%i: true -> TRUE\n", ++prodNum);}
_FALSE:		FALSE		{printf("%i: false -> FALSE\n", ++prodNum);}
_SUB:		SUB		{printf("%i: - -> SUB\n", ++prodNum);}
_ADD:		ADD		{printf("%i: + -> ADD\n", ++prodNum);}
_MULT:		MULT		{printf("%i: * -> MULT\n", ++prodNum);}
_DIV:		DIV		{printf("%i: / -> DIV\n", ++prodNum);}
_MOD:		MOD		{printf("%i: % -> MOD\n", ++prodNum);}
_EQ:		EQ		{printf("%i: == -> EQ\n", ++prodNum);}
_NEQ:		NEQ		{printf("%i: <> -> NEQ\n", ++prodNum);}
_LT:		LT		{printf("%i: < -> LT\n", ++prodNum);}
_GT:		GT		{printf("%i: > -> GT\n", ++prodNum);}
_LTE:		LTE		{printf("%i: <= -> LTE\n", ++prodNum);}
_GTE:		GTE		{printf("%i: >= -> GTE\n", ++prodNum);}
_SEMICOLON:	SEMICOLON	{printf("%i: ; -> SEMICOLON\n", ++prodNum);}
_COLON:		COLON		{printf("%i: : -> COLON\n", ++prodNum);}
_COMMA:		COMMA		{printf("%i: , -> COMMA\n", ++prodNum);}
_L_PAREN:	L_PAREN		{printf("%i: ( -> L_PAREN\n", ++prodNum);}
_R_PAREN:	R_PAREN		{printf("%i: ) -> R_PAREN\n", ++prodNum);}
_ASSIGN:	ASSIGN		{printf("%i: := -> ASSIGN\n", ++prodNum);}
_NUMBER:	NUMBER		{printf("%i: %s -> NUMBER(%s)\n", ++prodNum, yytext, yytext);}
_IDENT:		IDENT		{printf("%i: %s -> IDENT(%s)\n", ++prodNum, yytext, yytext);}


%%

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

