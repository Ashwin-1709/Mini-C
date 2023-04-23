%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    int iconst;
    float dconst;
}

%token BREAK CASE CHAR CONTINUE DEFAULT ELSE FLOAT FOR IF RETURN INT SWITCH VOID WHILE MAIN_FUNCTION
%token IDENTIFIER STRING_LITERAL
%token<iconst>I_CONSTANT 
%token<dconst>F_CONSTANT
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP EQUAL_SIGN
%token SEMICOLON LEFT_CURLY RIGHT_CURLY COMMA COLON LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE DOT
%token AMPERSAND PLUS STAR SLASH LT_OP GT_OP PERCENT
%token PRINTF_TOKEN SCANF_TOKEN
%token<iconst> EXCLAMATION
%token<iconst> HYPHEN
%type<iconst>expression_statement
%type<iconst>unary_expr

%right EQUAL_SIGN
%left OR_OP
%left AND_OP
%left EQ_OP NE_OP
%left GT_OP LT_OP GE_OP LE_OP
%left PLUS HYPHEN
%left STAR SLASH PERCENT
%right EXCLAMATION
%%
/* Functional declarations */
s : main_func | functional_declaration s
;

functional_declaration : func_type func_declarator compound_statement
;

var_type : INT | CHAR | FLOAT
;

func_type : var_type | VOID
;

func_declarator : IDENTIFIER LEFT_ROUND RIGHT_ROUND | IDENTIFIER LEFT_ROUND param_list RIGHT_ROUND
;

param_list : declare_var | declare_var COMMA param_list
;

declare_var : var_type IDENTIFIER
;

/* Main Function Starts below */
main_func : MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement 
            | INT MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement
            | VOID MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement
;

compound_statement : LEFT_CURLY RIGHT_CURLY 
            | LEFT_CURLY statement_list RIGHT_CURLY
;

statement_list : single_statement
            | single_statement statement_list 
;
single_statement : switch_statment 
                | expr 
                | if_statement 
                | print_statement 
                | scanf_statement 
                | for_statement 
                | return_statement 
                | while_statement  
                | jump_statement  
                | declaration
                | compound_statement
;

jump_statement : BREAK SEMICOLON 
                | CONTINUE SEMICOLON
;

return_statement : RETURN expr
;
/* Expression */
expr : SEMICOLON 
        | expression_statement SEMICOLON  {printf("---parsed expression---- %d\n", $1);}
        | expr COMMA expr SEMICOLON
      
;
expression_statement : expression_statement OR_OP expression_statement {printf("expr || expr reduced\n"); $$ = $1 || $3; printf("here = %d\n", $$);}| 
				       expression_statement AND_OP expression_statement {printf("expr && expr reduced\n"); $$ = $1 && $3; printf("here = %d\n", $$);}|
				       expression_statement GT_OP expression_statement  {printf("expr > expr reduced\n"); $$ = $1 > $3; printf("here = %d\n", $$);}|
			           expression_statement LT_OP expression_statement {printf("expr < expr reduced\n"); $$ = $1 < $3; printf("here = %d\n", $$);}|
				       expression_statement GE_OP expression_statement {printf("expr >= expr reduced\n"); $$ = $1 >= $3; printf("here = %d\n", $$);}|
				       expression_statement LE_OP expression_statement {printf("expr <= expr reduced\n"); $$ = $1 <= $3; printf("here = %d\n", $$);}| 
				       expression_statement PLUS expression_statement {printf("expr + expr reduced\n"); $$ = $1 + $3; printf("here = %d\n", $$);}|
				       expression_statement HYPHEN expression_statement {printf("expr - expr reduced\n"); $$ = $1 - $3; printf("here = %d\n", $$);}|
				       expression_statement STAR expression_statement {printf("expr * expr reduced\n"); $$ = $1 * $3; printf("here = %d\n", $$);}|
				       expression_statement SLASH expression_statement {printf("expr / expr reduced\n"); $$ = $1 / $3; printf("here = %d\n", $$);}|
				       expression_statement PERCENT expression_statement {printf("expr mod expr reduced\n"); $$ = $1 % $3; printf("here = %d\n", $$);}|
                       expression_statement EQ_OP expression_statement {printf("expr == expr reduced\n"); $$ = $1 == $3; printf("here = %d\n", $$);}|
                       expression_statement NE_OP expression_statement {printf("expr != expr reduced\n"); $$ = $1 != $3; printf("here = %d\n", $$);}|
				       unary_expr {printf("unary reduced\n"); $$ = $1; printf("here = %d\n", $$);} |
                       /* assignment_statement  |
				       functional_call | */
				       LEFT_ROUND expression_statement RIGHT_ROUND {$$ = $2;}|
				        I_CONSTANT {;} //| F_CONSTANT | STRING_LITERAL | arr_element | IDENTIFIER
;

unary_expr : EXCLAMATION expression_statement %prec EXCLAMATION {printf("!(expr) reduced\n"); $$ = !$1;printf("here = %d\n", $$);}
            | HYPHEN expression_statement %prec HYPHEN {printf("-(expr) reduced\n"); $$ = -$1;printf("here = %d\n", $$);}
;

functional_call : IDENTIFIER LEFT_ROUND RIGHT_ROUND 
                 | IDENTIFIER LEFT_ROUND arg_list RIGHT_ROUND
;
arg_list : arg | arg COMMA arg_list
;
arg : F_CONSTANT | I_CONSTANT | IDENTIFIER | STRING_LITERAL
;
arr_element : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE
             | IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE
;

/* Assignment */
assignment_statement : IDENTIFIER EQUAL_SIGN expression_statement %prec EQUAL_SIGN
                       | arr_element EQUAL_SIGN expression_statement %prec EQUAL_SIGN
;

/* Switch-case */
switch_statment : SWITCH LEFT_ROUND expression_statement RIGHT_ROUND LEFT_CURLY case_list_def RIGHT_CURLY
;
case_list_def : case_list 
                | case_list default_stmt
                |
;
case_list :  case | case_list case
;
case : CASE expression_statement COLON statement_list 
       | CASE expression_statement COLON
;
default_stmt : DEFAULT COLON statement_list
              | DEFAULT COLON
;

/* if else */
if_statement: IF LEFT_ROUND expression_statement RIGHT_ROUND single_statement else_clause
;
else_clause : ELSE single_statement
            |
;
/* For loop */ 
for_loop_assignment : assignment_statement 
                     | assignment_statement COMMA for_loop_assignment 
                     |
;
for_loop_declaration : declaration 
                       | SEMICOLON
;
for_statement : FOR LEFT_ROUND for_loop_declaration expr for_loop_assignment RIGHT_ROUND statement_list 
;

/* declaration */
declaration : var_type init_declarator_list SEMICOLON
;
init_declarator_list : init_declarator_list COMMA init_declarator | init_declarator
;
init_declarator : declarator_var EQUAL_SIGN expression_statement 
                 | declarator_var
                 | declarator_arr
;
declarator_var : IDENTIFIER
;
declarator_arr : IDENTIFIER LEFT_SQUARE expression_statement RIGHT_SQUARE
                | IDENTIFIER LEFT_SQUARE expression_statement RIGHT_SQUARE LEFT_SQUARE expression_statement RIGHT_SQUARE
;
/* While */
while_statement : WHILE LEFT_ROUND expression_statement RIGHT_ROUND statement_list
;

/* Printf and scanf */
print_statement : PRINTF_TOKEN LEFT_ROUND STRING_LITERAL RIGHT_ROUND SEMICOLON
                 | PRINTF_TOKEN LEFT_ROUND STRING_LITERAL COMMA print_params RIGHT_ROUND SEMICOLON
;
print_params : IDENTIFIER | IDENTIFIER COMMA print_params
;
scanf_statement : SCANF_TOKEN LEFT_ROUND STRING_LITERAL COMMA addr_list RIGHT_ROUND SEMICOLON
;
addr_list : addr | addr COMMA addr_list
;
addr : AMPERSAND IDENTIFIER
;
%%

int main() {
    yyparse();
    printf("Lexical Analysis done......\n");
    printf("Syntax Analysis done......\nProgram is Syntactically correct\n");
    printf("Initiating simulation and semantic analysis.........\n");
}

int yyerror() {
    printf("Syntax error\n");
    exit(0);
}
