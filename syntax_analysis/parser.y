%{
    #include "stdio.h"
    #include "stdlib.h"
%}


%token BREAK CASE CHAR CONTINUE DEFAULT ELSE FLOAT FOR IF RETURN INT SWITCH VOID WHILE MAIN_FUNCTION
%token IDENTIFIER STRING_LITERAL CHAR_CONST
%token I_CONSTANT 
%token F_CONSTANT
%token  AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP EQUAL_SIGN
%token  SEMICOLON LEFT_CURLY RIGHT_CURLY COMMA COLON LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE
%token  EXCLAMATION HYPHEN PLUS STAR SLASH LT_OP GT_OP PERCENT UNARY_MINUS
%token  PRINTF_TOKEN


%type  s main_func functional_declaration P var_type func_type func_declarator param_list declare_var
%type  compound_statement statement_list single_statement switch_statment for_statement if_statement while_statement declaration jump_statement print_statement expr return_statement 
%type  expression_statement unary_expr functional_call arr_element assignment_statement
%type  arg_list arg case_list_def case_list default_stmt case
%type  else_clause for_loop_assignment for_loop_declaration 
%type  init_declarator init_declarator_list declarator_arr declarator_var print_params


%right EQUAL_SIGN
%left OR_OP
%left AND_OP
%left EQ_OP NE_OP
%left GT_OP LT_OP GE_OP LE_OP
%left PLUS HYPHEN
%left STAR SLASH PERCENT
%right EXCLAMATION UNARY_MINUS
%%
/* Functional declarations */
s : P  
;

P : main_func  
   | functional_declaration P 
;

functional_declaration : func_type func_declarator compound_statement 
;

var_type : INT  
          | CHAR 
          | FLOAT 
;

func_type : var_type  
            | VOID 
;

func_declarator : IDENTIFIER LEFT_ROUND RIGHT_ROUND  
                | IDENTIFIER LEFT_ROUND param_list RIGHT_ROUND 
;

param_list : declare_var  
            | declare_var COMMA param_list 
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
        | expression_statement SEMICOLON 
        | expr COMMA expr SEMICOLON 
      
;
expression_statement : expression_statement OR_OP expression_statement  
				      | expression_statement AND_OP expression_statement 
				      | expression_statement GT_OP expression_statement  
			          | expression_statement LT_OP expression_statement 
				      | expression_statement GE_OP expression_statement 
				      | expression_statement LE_OP expression_statement 
				      | expression_statement PLUS expression_statement 
				      | expression_statement HYPHEN expression_statement 
				      | expression_statement STAR expression_statement 
				      | expression_statement SLASH expression_statement 
				      | expression_statement PERCENT expression_statement 
                      | expression_statement EQ_OP expression_statement 
                      | expression_statement NE_OP expression_statement 
				      | unary_expr 
                      | assignment_statement 
				      | functional_call 
				      | LEFT_ROUND expression_statement RIGHT_ROUND 
				      |  I_CONSTANT 
                      | F_CONSTANT 
                      | STRING_LITERAL
                      | CHAR_CONST 
                      | arr_element 
                      | IDENTIFIER 
;

unary_expr : EXCLAMATION expression_statement %prec EXCLAMATION
            | HYPHEN expression_statement %prec UNARY_MINUS 

functional_call : IDENTIFIER LEFT_ROUND RIGHT_ROUND 
                 | IDENTIFIER LEFT_ROUND arg_list RIGHT_ROUND 
;
arg_list : arg 
           | arg COMMA arg_list 
;
arg : expression_statement 
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
case : CASE I_CONSTANT COLON statement_list 
       | CASE I_CONSTANT COLON 
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
                       | for_loop_assignment SEMICOLON 
;
for_statement : FOR LEFT_ROUND for_loop_declaration expr for_loop_assignment RIGHT_ROUND single_statement
;

/* declaration */
declaration : var_type init_declarator_list SEMICOLON
;
init_declarator_list : init_declarator_list COMMA init_declarator 
                    | init_declarator
;
init_declarator : declarator_var EQUAL_SIGN expression_statement 
                 | declarator_var 
                 | declarator_arr 
;
declarator_var : IDENTIFIER 
;
declarator_arr : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE
                | IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE
;
/* While */
while_statement : WHILE LEFT_ROUND expression_statement RIGHT_ROUND single_statement
;

/* Printf and scanf */
print_statement : PRINTF_TOKEN LEFT_ROUND STRING_LITERAL RIGHT_ROUND SEMICOLON
                 | PRINTF_TOKEN LEFT_ROUND STRING_LITERAL COMMA print_params RIGHT_ROUND SEMICOLON
print_params : IDENTIFIER 
            | IDENTIFIER COMMA print_params 
;
%%

int main() {
    yyparse();
    printf("Syntax analysis done\n");
}

int yyerror() {
    printf("Syntax error\n");
    exit(0);
}
