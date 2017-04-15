/* calculator. */
%{
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


%}

%code requires {
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
}

%union{
  std::string* sval;
  int ival;
  listchar CodeBlock;
  StateSemiReturn* CodeNCont;
  OperationReturn* OpRet;
  AssignVarReturn* AVRet;
  CodeAndVar* cav;
 }

%type<CodeNCont> StateSemiP StateSemi Statement RComVar WComVar Block
%type<cav> RelationExp BoolExp Expression RelationAndExp Term Var MultExp
%type<OpRet> MultTerm AddMultExp AndRelExp OrRelExp
%type<sval> _PROGRAM _BEGIN_PROGRAM _END_PROGRAM _INTEGER _ARRAY _OF _IF _THEN _ENDIF _ELSE _WHILE _DO _BEGINLOOP _ENDLOOP _CONTINUE _READ _WRITE _AND _OR _NOT _TRUE _FALSE  _SUB _ADD _MULT _DIV _MOD _EQ _NEQ _LT _GT _LTE _GTE _SEMICOLON _COLON _COMMA _L_PAREN _R_PAREN _ASSIGN _NUMBER _IDENT Comp 
%type<AVRet> AssignVar

%error-verbose
%start Program
%token PROGRAM BEGIN_PROGRAM END_PROGRAM INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
%token <sval> IDENT
%token <ival> NUMBER
%left LT GT NEQ EQ GTE LTE
%left PLUS MINUS
%left MULT DIV

%%

Program:	_PROGRAM _IDENT _SEMICOLON Block _END_PROGRAM	{ CreateFile($2, $4); }//{printf("%i: program -> program ident semicolon block endprogram\n", ++prodNum);}
		;

Block:		Declaration _SEMICOLON DecSemi _BEGIN_PROGRAM StateSemiP	{$$ = $5;}//{printf("%i: declaration -> declaration semicolon beginprogram statement semicolon\n", ++prodNum);}
		;

StateSemiP:	Statement _SEMICOLON StateSemi	{$$ = StateSemiFunction($1, $3);}//{ $1->splice($1->end(), (*$3), $3->begin(), $3->end()); $$ = $1; /*printf("%i: statesemi -> statement semicolon statement\n", ++prodNum);*/}
		; 

StateSemi:	Statement _SEMICOLON StateSemi	{$$ = StateSemiFunction($1, $3);}
		| 									{StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = new list<string*>(); $$ = ret;}
		;

DecSemi:	Declaration _SEMICOLON DecSemi 	//{printf("%i: declaration -> declaration semicolon declaration\n", ++prodNum);}
		|									//{printf("%i: declaration -> declaration semicolon declaration\n", ++prodNum);}
		;

Declaration:	_IDENT Comm_IDENT _COLON _INTEGER									{*$1 = "_" + *$1; varNames.push_back($1);numConsecutiveInits++; DefineVarsAsArrays(NULL);}
		| 	_IDENT Comm_IDENT _COLON _ARRAY _L_PAREN _NUMBER _R_PAREN _OF _INTEGER	{*$1 = "_" + *$1; varNames.push_back($1);numConsecutiveInits++; DefineVarsAsArrays($6);}
		;

Comm_IDENT:	_COMMA _IDENT Comm_IDENT							{*$2 = "_" + *$2; varNames.push_back($2); numConsecutiveInits++;}
		|								
		;


Statement:	AssignVar _ASSIGN Expression						{ $$ = AssignStatement($1, $3);}
		| _IF BoolExp _THEN StateSemiP _ENDIF					{ $$ = IfStatement($2, $4); }
		| _IF BoolExp _THEN StateSemiP _ELSE StateSemiP _ENDIF	{ $$ = IfElseStatement($2, $4, $6); }
		| _WHILE BoolExp _BEGINLOOP StateSemiP _ENDLOOP			{ $$ = WhileFunction($4, $2); }
		| _DO _BEGINLOOP StateSemiP _ENDLOOP _WHILE BoolExp		{ $$ = DoWhileFunction($3, $6); }
		| _READ AssignVar RComVar								{
																	$$ = IOStatement("< ",  $2, $3);
																}
		| _WRITE AssignVar WComVar								{
																	$$ = IOStatement("< ",  $2, $3);
																}
		| _CONTINUE												{$$ = NULL;}
		;

BoolExp:	RelationAndExp OrRelExp					{
														if($2 == NULL){$$ = $1;} 
														else
														{ 
															CodeAndVar* ret = $1; 
															OperationReturn* opRet = OperationFunction(NULL, $1, $2); 
															ret->code = opRet->code; 
															ret->var = opRet->var; 
															$$ = ret;
														}
													}
		;

OrRelExp:	_OR RelationAndExp OrRelExp				{$$ = OperationFunction($1, $2, $3);}
		|											{$$ = NULL;}
		;

RelationAndExp:	RelationExp AndRelExp				{
														if($2 == NULL){$$ = $1;} 
														else
														{ 
															CodeAndVar* ret = $1; 
															OperationReturn* opRet = OperationFunction(NULL, $1, $2); 
															ret->code = opRet->code; 
															ret->var = opRet->var; 
															$$ = ret;
														}
													}
		|											{$$ = NULL;}
		;

AndRelExp:	_AND RelationExp AndRelExp				{$$ = OperationFunction($1, $2, $3);}
		|											{$$ = NULL;}
		;

RelationExp:	_NOT Expression Comp Expression		{
														CodeAndVar* ret = $4; ret->code->splice($4->code->begin(), *$2->code); 
														string* temp = nextTemp(); 
														ret->code->push_back(new string(*$3 + " " + *temp + ", " + *$2->var + ", " + *$4->var) ); 
														ret->code->push_back(new string("! " + *temp + ", " + *temp) ); 
														ret->var = temp;
														$$ = ret;
													}
		| _NOT _TRUE								{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); delete($1); *$2 = "false"; ret->var = $2; $$ = ret; }
		| _NOT _FALSE								{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); delete($1); *$2 = "true";  ret->var = $2; $$ = ret; }
		| _NOT _L_PAREN BoolExp _R_PAREN			{ CodeAndVar* ret = $3; string* temp = nextTemp(); ret->code->push_back(new string("! " + *temp + ", " + *$3->var)); ret->var = temp;  $$ = ret;}

		| Expression Comp Expression				{ 
														CodeAndVar* ret = $3; ret->code->splice($3->code->begin(), *$1->code); 
														string* temp = nextTemp(); 
														ret->code->push_back(new string(*$2 + " " + *temp + ", " + *$1->var + ", " + *$3->var) ); 
														ret->var = temp;
														$$ = ret;
													}
		| _TRUE										{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = $1;  $$ = ret; }
		| _FALSE									{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = $1;  $$ = ret; }
		| _L_PAREN BoolExp _R_PAREN					{$$ = $2;}
		;

Comp:		_EQ										{$$ = $1;}
		| _NEQ										{$$ = $1;}
		| _LT										{$$ = $1;}
		| _GT										{$$ = $1;}
		| _LTE										{$$ = $1;}
		| _GTE										{$$ = $1;}
		;

RComVar:	_COMMA AssignVar RComVar				{ $$ = IOStatement("< ",  $2, $3);}
		|											{ StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = NULL; $$ = ret; }
		;

WComVar:	_COMMA AssignVar WComVar				{ $$ = IOStatement("> ",  $2, $3);}
		|											{ StateSemiReturn* ret = new StateSemiReturn(); ret->code = new list<string*>(); ret->continues = NULL; $$ = ret; }
		;

Expression:	MultExp AddMultExp						{ 
														CodeAndVar* ret = $1; 
														OperationReturn* opRet = OperationFunction(NULL, $1, $2); 
														ret->code = opRet->code; 
														ret->var = opRet->var; 
														$$ = ret;
													}
		;

AddMultExp:	_ADD MultExp AddMultExp					{$$ = OperationFunction($1, $2, $3);}
		| _SUB MultExp AddMultExp					{$$ = OperationFunction($1, $2, $3);}
		|											{ OperationReturn* ret = NULL; $$ = ret; }
		;

MultExp:	Term MultTerm							{ 
														CodeAndVar* ret = $1; 
														OperationReturn* opRet = OperationFunction(NULL, $1, $2); 
														ret->code = opRet->code; 
														ret->var = opRet->var; 
														$$ = ret;
													}
		;

MultTerm:	_MULT Term MultTerm						{$$ = OperationFunction($1, $2, $3);}
		| _DIV Term MultTerm						{$$ = OperationFunction($1, $2, $3);}
		| _MOD Term MultTerm						{$$ = OperationFunction($1, $2, $3);}
		|											{ OperationReturn* ret = NULL; $$ = ret; }
		;

Term:		_SUB Var								{ CodeAndVar* ret = $2; string* temp = nextTemp(); ret->code->push_back( new string("- " + *temp + ", 0, " + *$2->var) ); ret->var = temp; $$ = ret; }
		| _SUB _NUMBER								{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); *$2 = "-" + *$2; ret->var = $2; $$ = ret; }
		| _SUB _L_PAREN Expression _R_PAREN			{ CodeAndVar* ret = $3; string* temp = nextTemp(); ret->code->push_back( new string("- " + *temp + ", 0, " + *$3->var) ); ret->var = temp; $$ = ret; }
		| Var										{ $$ = $1; }
		| _NUMBER									{ CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = $1;  $$ = ret; }
		| _L_PAREN Expression _R_PAREN				{ $$ = $2;  }
		;

Var:		_IDENT									{*$1 = "_" + *$1;ValidateIdent($1, false); CodeAndVar* ret = new CodeAndVar(); ret->code = new list<string*>(); ret->var = $1;  $$ = ret; }
		| _IDENT _L_PAREN Expression _R_PAREN		{*$1 = "_" + *$1;ValidateIdent($1, true);  string* temp = nextTemp(); $3->code->push_back(new string("=[] " + (*temp) + ", "+ *$1 + ", " + *$3->var)); $3->var = temp; $$ = $3; }
		;

AssignVar:	_IDENT									{*$1 = "_" + *$1;ValidateIdent($1, false); AssignVarReturn* ret = new AssignVarReturn(); ret->var = $1; ret->index = NULL;    ret->code = new list<string*>(); $$ = ret;}
		| _IDENT _L_PAREN Expression _R_PAREN		{*$1 = "_" + *$1;ValidateIdent($1, true);  AssignVarReturn* ret = new AssignVarReturn(); ret->var = $1; ret->index = $3->var; ret->code = $3->code;            $$ = ret;}
		;

_PROGRAM:	PROGRAM 	{$$ = new string("program");}//{printf("%i: program -> PROGRAM\n", ++prodNum);}
_BEGIN_PROGRAM:	BEGIN_PROGRAM	{$$ = new string("beginprogram");}//{printf("%i: beginprogram -> BEGIN_PROGRAM\n", ++prodNum);}
_END_PROGRAM:	END_PROGRAM	{$$ = new string("endprogram");}//{printf("%i: endprogram -> END_PROGRAM\n", ++prodNum);}
_INTEGER:	INTEGER		{$$ = new string("integer");}//{printf("%i: integer -> INTEGER\n", ++prodNum);}
_ARRAY:		ARRAY		{$$ = new string("array");}//{printf("%i: array -> ARRAY\n", ++prodNum);}
_OF:		OF			{$$ = new string("of");}//{printf("%i: of -> OF\n", ++prodNum);}
_IF:		IF			{$$ = new string("if");}//{printf("%i: if -> IF\n", ++prodNum);}
_THEN:		THEN		{$$ = new string("then");}//{printf("%i: then -> THEN\n", ++prodNum);}
_ENDIF:		ENDIF		{$$ = new string("endif");}//{printf("%i: endif -> ENDIF\n", ++prodNum);}
_ELSE:		ELSE		{$$ = new string("else");}//{printf("%i: else -> ELSE\n", ++prodNum);}
_WHILE:		WHILE		{$$ = new string("while");}//{printf("%i: while -> WHILE\n", ++prodNum);}
_DO:		DO			{$$ = new string("do");}//{printf("%i: do -> DO\n", ++prodNum);}
_BEGINLOOP:	BEGINLOOP	{$$ = new string("beginloop");}//{printf("%i: beginloop -> BEGINLOOP\n", ++prodNum);}
_ENDLOOP:	ENDLOOP		{$$ = new string("endloop");}//{printf("%i: endloop -> ENDLOOP\n", ++prodNum);}
_CONTINUE:	CONTINUE	{$$ = new string("continue");}//{printf("%i: continue -> CONTINUE\n", ++prodNum);}
_READ:		READ		{$$ = new string("read");}//{printf("%i: read -> READ\n", ++prodNum);}
_WRITE:		WRITE		{$$ = new string("write");}//{printf("%i: write -> WRITE\n", ++prodNum);}
_AND:		AND			{$$ = new string("&&");}//{printf("%i: and -> AND\n", ++prodNum);}
_OR:		OR			{$$ = new string("||");}//{printf("%i: or -> OR\n", ++prodNum);}
_NOT:		NOT			{$$ = new string("not");}//{printf("%i: not -> NOT\n", ++prodNum);}
_TRUE:		TRUE		{$$ = new string("true");}//{printf("%i: true -> TRUE\n", ++prodNum);}
_FALSE:		FALSE		{$$ = new string("false");}//{printf("%i: false -> FALSE\n", ++prodNum);}
_SUB:		SUB			{$$ = new string("-");}//{printf("%i: - -> SUB\n", ++prodNum);}
_ADD:		ADD			{$$ = new string("+");}//{printf("%i: + -> ADD\n", ++prodNum);}
_MULT:		MULT		{$$ = new string("*");}//{printf("%i: * -> MULT\n", ++prodNum);}
_DIV:		DIV			{$$ = new string("/");}//{printf("%i: / -> DIV\n", ++prodNum);}
_MOD:		MOD			{$$ = new string("%");}//{printf("%i: % -> MOD\n", ++prodNum);}
_EQ:		EQ			{$$ = new string("==");}//{printf("%i: == -> EQ\n", ++prodNum);}
_NEQ:		NEQ			{$$ = new string("!=");}//{printf("%i: <> -> NEQ\n", ++prodNum);}
_LT:		LT			{$$ = new string("<");}//{printf("%i: < -> LT\n", ++prodNum);}
_GT:		GT			{$$ = new string(">");}//{printf("%i: > -> GT\n", ++prodNum);}
_LTE:		LTE			{$$ = new string("<=");}//{printf("%i: <= -> LTE\n", ++prodNum);}
_GTE:		GTE			{$$ = new string(">=");}//{printf("%i: >= -> GTE\n", ++prodNum);}
_SEMICOLON:	SEMICOLON	{$$ = new string(";");}//{printf("%i: ; -> SEMICOLON\n", ++prodNum);}
_COLON:		COLON		{$$ = new string(":");}//{printf("%i: : -> COLON\n", ++prodNum);}
_COMMA:		COMMA		{$$ = new string(",");}//{printf("%i: , -> COMMA\n", ++prodNum);}
_L_PAREN:	L_PAREN		{$$ = new string("(");}//{printf("%i: ( -> L_PAREN\n", ++prodNum);}
_R_PAREN:	R_PAREN		{$$ = new string(")");}//{printf("%i: ) -> R_PAREN\n", ++prodNum);}
_ASSIGN:	ASSIGN		{$$ = new string(":=");}//{printf("%i: := -> ASSIGN\n", ++prodNum);}
_NUMBER:	NUMBER		{$$ = yyval.sval;}//{printf("%i: %s -> NUMBER(%s)\n", ++prodNum, yytext, yytext);}
_IDENT:		IDENT		{$$ = yyval.sval;}


%%

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

