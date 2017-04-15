/* cs152-winter16 */
/* Class project phase 2 */ 
/* Kevin Hsieh, khsie003 */
/* 861054367 */
/* mini_l.y   */

%{
  #include <stdio.h>
  #include <stdlib.h>

  int yylex(void);
  extern int curr_line;
  extern int curr_pos;
  extern char* yytext;
  FILE * yyin;
  %}

%union{
  int     int_val;
  char*   string_val;
 }

%start  init

%token  <int_val> NUMBER 
%token  PROGRAM
%token  BEGIN_PROGRAM
%token  END_PROGRAM
%token  INTEGER
%token  ARRAY
%token  OF
%token  IF
%token  THEN
%token  END_IF
%token  ELSE
%token  WHILE
%token  BEGIN_LOOP
%token  END_LOOP
%token  READ
%token  WRITE
%token  AND
%token  OR
%token  NOT
%token  TRUE
%token  FALSE
%token  EXIT
%token  CONTINUE
%token  TERM
%token  STATE
%token  R_AND_EXPR
%token  R_EXPR
%token  MULT_EXPR
%token  IDENT_LIST
%token  EXPR
%token  BOOL_EXPR
%token  BLOCK
%token  ELSE_STATE
%token  COMP
%token  DO
%token  DECLARATION
%token  VAR
%token  VAR_LOOP
%token  <string_val> IDENT

%token  SUB 
%token  ADD
%token  MULT
%token  DIV
%token  MOD
%token  QUESTION
%token  EQ
%token  NEQ
%token  LT
%token  GT
%token  LTE
%token  GTE

%token  SEMICOLON
%token  COLON
%token  COMMA
%token  L_PAREN
%token  R_PAREN
%token  L_BRACKET
%token  R_BRACKET
%token  ASSIGN

%%

init:
   program IDENT SEMICOLON block END_PROGRAM { printf("program -> PROGRAM IDENT SEMICOLON BEGIN_PROGRAM END_PROGRAM\n");}
|  
;

program: 
   PROGRAM {printf("program -> PROGRAM");}
;

block:
   declaration BEGIN_PROGRAM state {printf("block -> DELECARATION SEMICOLON BEGIN_PROGRAM STATEMENT\n");}
;

declaration:
  ident_list COLON term  {printf("declaration -> ident colon term\n");}
;

ident_list:
   ident_list COMMA IDENT {printf("ident_list -> ident_list comma ident\n");}
|  IDENT {printf("ident_list -> ident(%s)\n", yytext)}
;

state:
   var_loop ASSIGN expr {printf("statement -> var_loop assign expression\n");}
|  IF bool_expr THEN state SEMICOLON state END_IF {printf("statement -> if bool_exp then statement semicolon state_loop end_loop\n");}
|  WHILE bool_expr BEGIN_LOOP state END_LOOP WHILE bool_expr {printf("statement -> while bool_exp begin_loop state_loop end_loop while bool_exp\n");}
|  ELSE state {printf("statement -> else statement");}
|  state SEMICOLON {printf("statement -> statement semicolon");}
|  DO BEGIN_LOOP state END_LOOP WHILE bool_expr {printf("statement -> do begin_loop state_loop while bool_exp\n");}
|  READ var_loop {printf("statement -> read var_loop\n");}
|  WRITE var_loop {printf("statement -> write var_loop\n");}
|  CONTINUE {printf("statement -> continue\n");}
;

var_loop:
   var_loop COMMA var {printf("var_loop -> var_loop comma var\n");}
|  var {printf("var_loop -> var\n");}
;

var:
   IDENT {printf("var -> ident\n");}
|  var L_PAREN EXPR R_PAREN {printf("var -> var l_paren expr r_paren\n");}

expr:
   mult_expr {printf("expression -> mult_expr\n");}
|  IDENT ADD mult_expr {printf("expression -> ident add mult_expr\n");}
|  IDENT SUB mult_expr {printf("expression -> ident sub mult_expr\n");}
;

mult_expr:
   term {printf("mult_expr -> term\n");}
|  term MULT term {printf("mult_expr -> term mult term\n");}
|  term DIV term {printf("mult_expr -> term div term\n");}
|  term MOD term {printf("mult_expr -> term mod term\n");}
;

term:
   SUB term {printf("term -> sub term\n");}
|  VAR {printf("term -> var\n");}
|  NUMBER {printf("term -> number\n");}
|  L_PAREN expr R_PAREN {printf("term -> l_paren expression r_paren\n");}
;

bool_expr:
   r_and_expr {printf("bool_exp -> relation_and_exp\n");}
|  r_and_expr OR r_and_expr {printf("bool_exp -> relation_and_exp or relation_and_exp\n");}
|
;

r_and_expr:
   r_expr {printf("relation_and_exp -> relation_exp\n");}
|  r_expr AND r_expr {printf("relation_and_exp -> relation_exp and relation_exp\n");}
|
;

r_expr:
   NOT r_expr {printf("relation_exp -> not r_exp\n");}
|  expr comp expr {printf("relation_exp -> expression comp expression\n");}
|  TRUE {printf("relation_exp -> true\n");}
|  FALSE {printf("relation_exp -> false\n");}
|  L_PAREN bool_expr R_PAREN {printf("relation_exp -> l_paren bool_exp r_paren\n");}
;

comp:
   EQ {printf("comp -> EQ\n");}
|  NEQ {printf("comp -> NEQ\n");}
|  LT {printf("comp -> LT\n");}
|  GT {printf("comp -> GT\n");}
|  LTE {printf("comp -> LTE\n");}
|  GTE {printf("comp -> GTE\n");}
;

%%
int main(int argc, char ** argv){
  if(argc > 1){
    yyin = fopen(argv[1], "r");
    if (yyin == NULL){
      printf("Error"); 
    }
  }
  yyparse();
  return 0;

}

void yyerror(const char *msg) {
  printf("** Line %d, position %d: %s\n", curr_line, curr_pos, msg);
}
