%{
    #include "ast.h"
    #include "symboltable.h"

    void declerr(char *id) {
        printf("Error : \"%s\" redeclared\n", id);
        exit(0);
    }

    void assignError(char *id , char *type , char *exprtype) {
        printf("Error : Expected type of expression for %s is %s but %s found\n", id , type , exprtype);
        exit(0);
    }

    void undecerr(char *id) {
        printf("Error : \"%s\" used before declaration\n", id);
        exit(0);
    }

    table* cur_table;
    table* globalfuncs;
    astNode* semantic_stack[50];
    int cur_st = 0;

    void push(astNode* node) {
        semantic_stack[cur_st++] = node;
    }

    astNode* pop() {
        cur_st--;
        return semantic_stack[cur_st];
    }
%}


%union {
    int ival;
    float fval;
    char label[200];
    astNode* node;
}

%token BREAK CASE CHAR CONTINUE DEFAULT ELSE FLOAT FOR IF RETURN INT SWITCH VOID WHILE MAIN_FUNCTION
%token <label> IDENTIFIER STRING_LITERAL
%token <ival> I_CONSTANT 
%token <fval> F_CONSTANT
%token <node> AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP EQUAL_SIGN
%token <node> SEMICOLON LEFT_CURLY RIGHT_CURLY COMMA COLON LEFT_ROUND RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE
%token <node> EXCLAMATION HYPHEN PLUS STAR SLASH LT_OP GT_OP PERCENT UNARY_MINUS
%token <node> PRINTF_TOKEN


%type <node> s main_func functional_declaration P var_type func_type func_declarator param_list declare_var
%type <node> compound_statement statement_list single_statement switch_statment for_statement if_statement while_statement declaration jump_statement print_statement expr return_statement
%type <node> expression_statement unary_expr functional_call arr_element assignment_statement
%type <node> arg_list arg case_list_def case_list default_stmt case
%type <node> else_clause for_loop_assignment for_loop_declaration 
%type <node> init_declarator init_declarator_list declarator_arr declarator_var print_params


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
s : P  {$$ = createNodeByLabel("S"); addNode($$, $1); push($$);}
;

P : main_func {$$ = $1;}  
   | functional_declaration P {$$ = passNode("P", 2 , $1 , $2);}
;

functional_declaration : func_type func_declarator compound_statement { 
                    $$ = passNode("func_declaration", 3 , $1 , $2 , $3); 
                }
;

var_type : INT {$$ = passNode("int" , 0); $$->type = TY_INT;} 
          | CHAR {$$ = passNode("char" , 0); $$->type = TY_CHAR;}
          | FLOAT {$$ = passNode("float" , 0); $$->type = TY_FLOAT;}
;

func_type : var_type {$$ = passNode("var_type" , 1 , $1); $$->type = $1->type;} 
            | VOID {$$ = passNode("void" , 0); $$->type = TY_VOID;}
;

func_declarator : IDENTIFIER LEFT_ROUND RIGHT_ROUND  {
                    astNode* identifier = createNodeByLabel("id");
                    astNode* actual_id = createNodeByLabel($1);
                    addNode(identifier, actual_id);
                    astNode* left = createNodeByLabel("(");
                    astNode* right = createNodeByLabel(")");
                    $$ = passNode("func_declarator", 3 , identifier, left , right);
                }
                | IDENTIFIER LEFT_ROUND param_list RIGHT_ROUND {
                    astNode* identifier = createNodeByLabel("id");
                    astNode* actual_id = createNodeByLabel($1);
                    addNode(identifier, actual_id);
                    astNode* left = createNodeByLabel("(");
                    astNode* right = createNodeByLabel(")");
                    $$ = passNode("func_declarator", 4 , identifier, left , $3 ,right);
                }
;

param_list : declare_var {$$ = passNode("param_list", 1 , $1);} 
            | declare_var COMMA param_list {
                astNode* c = createNodeByLabel(",");
                $$ = passNode("param_list", 3 , $1 , c , $3);
            }
;

declare_var : var_type IDENTIFIER {
        astNode* identifier = createNodeByLabel("id");
        astNode* actual_id = createNodeByLabel($2);
        addNode(identifier, actual_id);
        $$ = passNode("declare_var", 2 , $1 , identifier);
}
;

/* Main Function Starts below */
main_func : MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement {
                astNode* main = createNodeByLabel("main");
                astNode* left = createNodeByLabel("(");
                astNode* right = createNodeByLabel(")");
                $$ = passNode("main_func", 4 , main, left, right , $4);
            }
            | INT MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement {
                astNode* type = createNodeByLabel("int");
                astNode* main = createNodeByLabel("main");
                astNode* left = createNodeByLabel("(");
                astNode* right = createNodeByLabel(")");
                $$ = passNode("main_func", 5 ,type ,  main, left, right , $5);
            }
            | VOID MAIN_FUNCTION LEFT_ROUND RIGHT_ROUND compound_statement {
                astNode* type = createNodeByLabel("void");
                astNode* main = createNodeByLabel("main");
                astNode* left = createNodeByLabel("(");
                astNode* right = createNodeByLabel(")");
                $$ = passNode("main_func", 5 , type , main, left, right , $5);
            }
;

compound_statement : LEFT_CURLY RIGHT_CURLY {
                        astNode* left = createNodeByLabel("{");
                        astNode* right = createNodeByLabel("}");
                        $$ = passNode("compound_stmt", 2 , left , right);
                    }
            | LEFT_CURLY statement_list RIGHT_CURLY {
                        astNode* left = createNodeByLabel("{");
                        astNode* right = createNodeByLabel("}");
                        $$ = passNode("compound_stmt", 3 , left , $2 , right);
            }
;

statement_list : single_statement {$$ = passNode("stmt_list" , 1 , $1);}
            | single_statement statement_list {$$ = passNode("stmt_list" , 2 , $1 , $2);}
;
single_statement : switch_statment {$$ = passNode("single_stmt" , 1 , $1);}
                | expr {$$ = passNode("single_stmt" , 1 , $1);}
                | if_statement {$$ = passNode("single_stmt" , 1 , $1);}
                | print_statement {$$ = passNode("single_stmt" , 1 , $1);}
                | for_statement {$$ = passNode("single_stmt" , 1 , $1);}
                | return_statement {$$ = passNode("single_stmt" , 1 , $1);}
                | while_statement  {$$ = passNode("single_stmt" , 1 , $1);}
                | jump_statement  {$$ = passNode("single_stmt" , 1 , $1);}
                | declaration {$$ = passNode("single_stmt" , 1 , $1);}
                | compound_statement {$$ = passNode("single_stmt" , 1 , $1);}
;

jump_statement : BREAK SEMICOLON {
                    astNode* breakNode = createNodeByLabel("break");
                    astNode* semicolon = createNodeByLabel(";");
                    $$ = passNode("jump_stmt", 2 , breakNode, semicolon);
                }
                | CONTINUE SEMICOLON {
                    astNode* continueNode = createNodeByLabel("continue");
                    astNode* semicolon = createNodeByLabel(";");
                    $$ = passNode("jump_stmt", 2 , continueNode, semicolon);
                }
;

return_statement : RETURN expr {
                        astNode* returnNode = createNodeByLabel("return");
                        $$ = passNode("return_stmt", 2 , returnNode, $2);
                    }
;
/* Expression */
expr : SEMICOLON {$$ = passNode("expr", 1 , createNodeByLabel(";"));}
        | expression_statement SEMICOLON {$$ = passNode("expr", 2 , $1 , createNodeByLabel(";"));}
        | expr COMMA expr SEMICOLON {$$ = passNode("expr", 4 , $1 , createNodeByLabel(",") , $3 , createNodeByLabel(";"));}
      
;
expression_statement : expression_statement OR_OP expression_statement  {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("||") , $3);}
				      | expression_statement AND_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("&&") , $3);}
				      | expression_statement GT_OP expression_statement  {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel(">") , $3);}
			          | expression_statement LT_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("<") , $3);}
				      | expression_statement GE_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel(">=") , $3);}
				      | expression_statement LE_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("<=") , $3);}
				      | expression_statement PLUS expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("+") , $3);}
				      | expression_statement HYPHEN expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("-") , $3);}
				      | expression_statement STAR expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("*") , $3);}
				      | expression_statement SLASH expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("/") , $3);}
				      | expression_statement PERCENT expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("%") , $3);}
                      | expression_statement EQ_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("==") , $3);}
                      | expression_statement NE_OP expression_statement {$$ = passNode("expression_stmt" , 3 , $1 , createNodeByLabel("!=") , $3);}
				      | unary_expr {$$ = passNode("expression_stmt" , 1 , $1);}
                      | assignment_statement {$$ = passNode("expression_stmt" , 1 , $1);}
				      | functional_call {$$ = passNode("expression_stmt" , 1 , $1);}
				      | LEFT_ROUND expression_statement RIGHT_ROUND {
                            astNode* left = createNodeByLabel("(");
                            astNode* right = createNodeByLabel(")");
                            $$ = passNode("expression_stmt", 3 , left , $2 , right);
                      }
				      |  I_CONSTANT {
                            astNode* iconst = createNodeByLabel("I_CONST");
                            astNode* val = createNodeByIntVal($1);
                            addNode(iconst, val);
                            $$ = passNode("expression_stmt", 1 , iconst);
                      }
                      | F_CONSTANT {
                            astNode* fconst = createNodeByLabel("F_CONST");
                            astNode* fval = createNodeByVal($1);
                            addNode(fconst, fval);
                            $$ = passNode("expression_stmt", 1 , fconst);
                      } 
                      | STRING_LITERAL {
                            astNode* string_literal = createNodeByLabel("STRING_LITERAL");
                            astNode* sval = createNodeByLabel($1);
                            addNode(string_literal, sval);
                            $$ = passNode("expression_stmt", 1 , string_literal);                            
                      } 
                      | arr_element {$$ = passNode("expression_stmt" , 1 , $1);} 
                      | IDENTIFIER {
                        astNode* identifier = createNodeByLabel("id");
                        astNode* actual_id = createNodeByLabel($1);
                        addNode(identifier, actual_id);
                        $$ = passNode("expression_stmt", 1 , identifier);
                      }
;

unary_expr : EXCLAMATION expression_statement %prec EXCLAMATION {$$ = passNode("unary", 2 , createNodeByLabel("!") , $2);} 
            | HYPHEN expression_statement %prec UNARY_MINUS {$$ = passNode("unary", 2 , createNodeByLabel("-") , $2);}

functional_call : IDENTIFIER LEFT_ROUND RIGHT_ROUND {
                    astNode* identifier = createNodeByLabel("id");
                    astNode* actual_id = createNodeByLabel($1);
                    addNode(identifier, actual_id);
                    astNode* left = createNodeByLabel("(");
                    astNode* right = createNodeByLabel(")");
                    $$ = passNode("functional_call", 3 , identifier, left , right);
                }
                 | IDENTIFIER LEFT_ROUND arg_list RIGHT_ROUND {
                    astNode* identifier = createNodeByLabel("id");
                    astNode* actual_id = createNodeByLabel($1);
                    addNode(identifier, actual_id);
                    astNode* left = createNodeByLabel("(");
                    astNode* right = createNodeByLabel(")");
                    $$ = passNode("functional_call", 4 , identifier, left , $3 ,right);
                 }
;
arg_list : arg {$$ = passNode("arg_list", 1 , $1);}
           | arg COMMA arg_list {
                astNode* c = createNodeByLabel(",");
                $$ = passNode("arg_list", 3 , $1 , c , $3);
           }
;
arg : expression_statement {$$ = passNode("arg" , 1 , $1);}
;
arr_element : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE {
                astNode* identifier = createNodeByLabel("id");
                astNode* actual_id = createNodeByLabel($1);
                astNode* iconst = createNodeByLabel("I_CONST");
                astNode* val = createNodeByIntVal($3);
                addNode(iconst, val);
                addNode(identifier, actual_id);
                astNode* left = createNodeByLabel("[");
                astNode* right = createNodeByLabel("]");
                $$ = passNode("arr_element", 4 , identifier, left , iconst , right);
            }
             | IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE {
                astNode* identifier = createNodeByLabel("id");
                astNode* actual_id = createNodeByLabel($1);
                astNode* iconst = createNodeByLabel("I_CONST");
                astNode* val = createNodeByIntVal($3);
                addNode(iconst, val);
                addNode(identifier, actual_id);
                astNode* left = createNodeByLabel("[");
                astNode* right = createNodeByLabel("]");
                astNode* left_2 = createNodeByLabel("[");
                astNode* right_2 = createNodeByLabel("]");
                astNode* iconst_2 = createNodeByLabel("I_CONST");
                astNode* val_2 = createNodeByIntVal($6);
                addNode(iconst_2, val_2);
                $$ = passNode("arr_element", 7 , identifier, left , iconst , right , left_2 , iconst_2 , right_2);
             }
;

/* Assignment */
assignment_statement : IDENTIFIER EQUAL_SIGN expression_statement %prec EQUAL_SIGN{
                            astNode* identifier = createNodeByLabel("id");
                            astNode* actual_id = createNodeByLabel($1);
                            addNode(identifier, actual_id);
                            astNode* equalto = createNodeByLabel("=");
                            $$ = passNode("assign_stmt", 3, identifier, equalto, $3);
                        }
                       | arr_element EQUAL_SIGN expression_statement %prec EQUAL_SIGN{
                            astNode* equalto = createNodeByLabel("=");
                            $$ = passNode("assign_stmt", 3, $1, equalto, $3);
                        }
;

/* Switch-case */
switch_statment : SWITCH LEFT_ROUND expression_statement RIGHT_ROUND LEFT_CURLY case_list_def RIGHT_CURLY{
                            astNode* switch_terminal = createNodeByLabel("switch");
                            astNode* left_round = createNodeByLabel("(");
                            astNode* right_round = createNodeByLabel(")");
                            astNode* left_curly = createNodeByLabel("{");
                            astNode* right_curly = createNodeByLabel("}");
                            $$ = passNode("switch_stmt", 7, switch_terminal, left_round, $3, right_round, left_curly, $6, right_curly);
                        }
;
case_list_def : case_list {$$ = passNode("case_list_def", 1, $1);}
                | case_list default_stmt {$$ = passNode("case_list_def", 2, $1, $2);}
                | {$$ = passNode("case_list_def", 0);}
;
case_list :  case {$$ = passNode("case_list", 1, $1);} | case_list case {$$ = passNode("case_list", 2, $1, $2);}
;
case : CASE expression_statement COLON statement_list {
                            astNode* case_st = createNodeByLabel("case");
                            astNode* colon = createNodeByLabel(":");
                            $$ = passNode("case_st", 4, case_st, $2, colon, $4);
                        }
       | CASE expression_statement COLON {
                            astNode* case_st = createNodeByLabel("case");
                            astNode* colon = createNodeByLabel(":");
                            $$ = passNode("case_st", 3, case_st, $2, colon);
                        }
;
default_stmt : DEFAULT COLON statement_list {
                            astNode* default_st = createNodeByLabel("default");
                            astNode* colon = createNodeByLabel(":");
                            $$ = passNode("default_stmt", 3, default_st, colon, $3);
                        }
              | DEFAULT COLON {
                            astNode* default_st = createNodeByLabel("default");
                            astNode* colon = createNodeByLabel(":");
                            $$ = passNode("default_stmt", 2, default_st, colon);
                        }
;

/* if else */
if_statement: IF LEFT_ROUND expression_statement RIGHT_ROUND single_statement else_clause {
                            astNode* if_st = createNodeByLabel("if");
                            astNode* left_round = createNodeByLabel("(");
                            astNode* right_round = createNodeByLabel(")");
                            $$ = passNode("if_stmt", 6, if_st, left_round, $3, right_round, $5, $6);
                        }
;
else_clause : ELSE single_statement {
                            astNode* else_st = createNodeByLabel("else");
                            $$ = passNode("else_clause", 2, else_st, $2);
                        }
            | {$$ = passNode("else_clause", 0);}
;
/* For loop */ 
for_loop_assignment : assignment_statement {$$ = passNode("for_assign", 1, $1);}
                    | assignment_statement COMMA for_loop_assignment{
                            astNode* comma = createNodeByLabel(",");
                            $$ = passNode("for_assign", 3, $1, comma, $3);        
                        }
                    | {$$ = passNode("for_assign", 0);}
;
for_loop_declaration : declaration {$$ = passNode("for_declare", 1, $1);}
                       | SEMICOLON {astNode* semicolon = createNodeByLabel(";"); $$ = passNode("for_declare", 1, semicolon);}
                       | for_loop_assignment SEMICOLON {astNode* semicolon = createNodeByLabel(";"); $$ = passNode("for_declare", 2 , $1, semicolon);}
;
for_statement : FOR LEFT_ROUND for_loop_declaration expr for_loop_assignment RIGHT_ROUND statement_list{
                        astNode* for_st = createNodeByLabel("for");
                        astNode* left_round = createNodeByLabel("(");
                        astNode* right_round = createNodeByLabel(")");
                        $$ = passNode("for_stmt", 7, for_st, left_round, $3, $4, $5, right_round, $7);
                    }
;

/* declaration */
declaration : var_type init_declarator_list SEMICOLON{
                        astNode* semicolon = createNodeByLabel(";");
                        $$ = passNode("declaration", 3, $1, $2, semicolon);
                    }
;
init_declarator_list : init_declarator_list COMMA init_declarator {
                        astNode* comma = createNodeByLabel(",");
                        $$ = passNode("init_dec_list", 3, $1, comma, $3);
                    }
                    | init_declarator {$$ = passNode("init_dec_list", 1, $1);}
;
init_declarator : declarator_var EQUAL_SIGN expression_statement {
                        astNode* equalto = createNodeByLabel("=");
                        $$ = passNode("init_dec", 3, $1, equalto, $3);
                    }
                 | declarator_var {$$ = passNode("init_dec", 1, $1);}
                 | declarator_arr {$$ = passNode("init_dec", 1, $1);}
;
declarator_var : IDENTIFIER {
                        astNode* identifier = createNodeByLabel("id");
                        astNode* actual_id = createNodeByLabel($1);
                        addNode(identifier, actual_id);
                        $$ = passNode("dec_var", 1, identifier);
                    }
;
declarator_arr : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE{
                        astNode* identifier = createNodeByLabel("id");
                        astNode* actual_id = createNodeByLabel($1);
                        addNode(identifier, actual_id);
                        astNode* left_square = createNodeByLabel("[");
                        astNode* right_square = createNodeByLabel("]");
                        astNode* iconst = createNodeByLabel("I_CONST");
                        astNode* val = createNodeByIntVal($3);
                        addNode(iconst, val);
                        $$ = passNode("dec_arr", 4, identifier, left_square, iconst , right_square);
                    }
                | IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE{
                        astNode* identifier = createNodeByLabel("id");
                        astNode* actual_id = createNodeByLabel($1);
                        addNode(identifier, actual_id);
                        astNode* left_square = createNodeByLabel("[");
                        astNode* right_square = createNodeByLabel("]");
                        astNode* iconst1 = createNodeByLabel("I_CONST");
                        astNode* val1 = createNodeByIntVal($3);
                        addNode(iconst1, val1);
                        astNode* iconst2 = createNodeByLabel("I_CONST");
                        astNode* val2 = createNodeByIntVal($6);
                        addNode(iconst2, val2);
                        $$ = passNode("dec_arr", 7, identifier, left_square, iconst1, right_square, left_square, iconst2, right_square);
                    }
;
/* While */
while_statement : WHILE LEFT_ROUND expression_statement RIGHT_ROUND statement_list{
                        astNode* while_st = createNodeByLabel("while");
                        astNode* left_round = createNodeByLabel("(");
                        astNode* right_round = createNodeByLabel(")");
                        $$ = passNode("while_stmt", 5, while_st, left_round, $3, right_round, $5);
                    }
;

/* Printf and scanf */
print_statement : PRINTF_TOKEN LEFT_ROUND STRING_LITERAL RIGHT_ROUND SEMICOLON{
                        astNode* printf_tk = createNodeByLabel("printf");
                        astNode* left_round = createNodeByLabel("(");
                        astNode* string_lit = createNodeByLabel("string");
                        astNode* string_lit_actual = createNodeByLabel($3);
                        addNode(string_lit, string_lit_actual);
                        astNode* right_round = createNodeByLabel(")");
                        astNode* semicolon = createNodeByLabel(";");
                        $$ = passNode("print_stmt", 5, printf_tk, left_round, string_lit, right_round, semicolon);
                    }
                 | PRINTF_TOKEN LEFT_ROUND STRING_LITERAL COMMA print_params RIGHT_ROUND SEMICOLON{
                        astNode* printf_tk = createNodeByLabel("printf");
                        astNode* left_round = createNodeByLabel("(");
                        astNode* string_lit = createNodeByLabel("string");
                        astNode* string_lit_actual = createNodeByLabel($3);
                        addNode(string_lit, string_lit_actual);
                        astNode* comma = createNodeByLabel(",");
                        astNode* right_round = createNodeByLabel(")");
                        astNode* semicolon = createNodeByLabel(";");
                        $$ = passNode("print_stmt", 7, printf_tk, left_round, string_lit, comma, $5, right_round, semicolon);
                 }
;
print_params : IDENTIFIER {
                astNode* identifier = createNodeByLabel("id");
                astNode* actual_id = createNodeByLabel($1);
                addNode(identifier, actual_id);
                $$ = passNode("print_params", 1, identifier);
            } 
            | IDENTIFIER COMMA print_params {
                astNode* identifier = createNodeByLabel("id");
                astNode* actual_id = createNodeByLabel($1);
                addNode(identifier, actual_id);
                astNode* comma = createNodeByLabel(",");
                $$ = passNode("print_params", 3, identifier, comma, $3);
            }
;
%%
void init_table(astNode* root, table* cur_scope);
void process_expression(astNode* root , table* cur);

void process_parameter_list(astNode* root, table* cur) {
    if(strcmp(root->label, "declare_var") == 0) {
        int type = root->child[0]->type;
        char *var_id = strdup(root->child[1]->child[0]->label);
        /* printf("param %d %s added\n", type,  var_id); */
        insertvar(var_id, type, NULL, -1, -1, cur);
        return;
    }
    for(int i = 0 ; i < root->childCnt ; i++)
        process_parameter_list(root->child[i], cur);
}

void process_function(astNode* root, table* cur) {
    // root is functional declaration
    /* printf("-----entered-----\n"); */
    /* printf("%s\n", root->label); */
    astNode* func_type = root->child[0];
    /* printf("%s\n", func_type->label); */
    if(strcmp(func_type->label, "var_type") == 0)
        func_type = func_type->child[0];
    Type type = func_type->type;

    astNode* func_decl = root->child[1]->child[0]->child[0];
    char *func_id = strdup(func_decl->label);
    /* printf("func_id = %s\n", func_id); */
    /* printf("hello123\n"); */
    astNode* param_list = root->child[1];
    /* printf("hello\n"); */
    /* printf("p = %s %d\n", param_list->label, param_list->childCnt); */
    if(searchTable(globalfuncs, func_id))
        declerr(func_id);
    if(param_list->childCnt == 4) {
        int *args = get_args(param_list->child[2]);
        insertfunc(func_id, type, cur, args , true , root);
        insertfunc(func_id, type, globalfuncs, args , true , root);
        process_parameter_list(param_list->child[2], cur);
        /* printf("func = %s type = %d argc = %d\n", func_id , type , argc); */
    } else{
        insertfunc(func_id , type , cur , NULL , false, root);
        insertfunc(func_id , type , globalfuncs , NULL , false, root);                                               
    }
    astNode* compound_stmt = root->child[2];
    if(compound_stmt->childCnt > 2) {
        /* printf("leaving func = %s\n", compound_stmt->child[1]->label); */
        init_table(compound_stmt->child[1], cur);
    }
}

void init_dec_list(astNode* root, table* cur, int type) {
    /* printf("in init_decl_list label = %s\n", root->label); */
    if(strcmp(root->label, "init_dec") == 0) {
        char* var_id = strdup(root->child[0]->child[0]->child[0]->label);
        /* printf("id added = %s\n", var_id); */
        if(searchTable(cur, var_id) || searchTable(globalfuncs, var_id))
            declerr(var_id);
        else {

            if (root->childCnt == 3){
                process_expression(root->child[2], cur);
            }
            if(root->child[0]->childCnt == 1)
                insertvar(var_id, type, NULL, -1, -1, cur);
            else if(root->child[0]->childCnt == 4) {
                int x_lim = atoi(root->child[0]->child[2]->child[0]->label);
                insertvar(var_id, type, NULL, x_lim, -1, cur);
            } else {
                int x_lim = atoi(root->child[0]->child[2]->child[0]->label);
                int y_lim = atoi(root->child[0]->child[5]->child[0]->label);
                insertvar(var_id, type, NULL, x_lim, y_lim, cur);
            }
        }

        /* printf("cur scope cnt = %d\n",  cur->entryCnt); */
        return;
    } 

    /* if(strcmp(root->label, "expression_stmt") == 0)
        init_table(root, cur); */
    for(int i = 0 ; i < root->childCnt; i++)
        init_dec_list(root->child[i], cur, type);
}

void process_expression(astNode* root , table* cur) {
    if(strcmp(root->label, "id") == 0) {
        char *id = strdup(root->child[0]->label);
        /* printTable(globalfuncs); */
        if(!isDeclared(id, cur) && !searchTable(globalfuncs, id))
            undecerr(id);
        return;
    }
    for(int i = 0 ; i < root->childCnt ; i++)
        process_expression(root->child[i], cur);
}

void process_declaration(astNode* root, table* cur) {
    Type type = root->child[0]->type;
    init_dec_list(root, cur, type);

}

void init_table(astNode* root, table* cur_scope) {
    /* printf("label = %s\n", root->label); */
    if(strcmp(root->label, "func_declaration") == 0) {
        /* printf("func_dec\n"); */
        table* child = changeScope(cur_scope);
        process_function(root , child);
        return;
    }

    if(strcmp(root->label, "compound_stmt") == 0 && root->childCnt > 2) {
        /* printf("compound\n"); */
        table* child = changeScope(cur_scope);
        init_table(root->child[1], child);
        return;
    }

    if(strcmp(root->label, "declaration") == 0) {
        /* printf("dec\n"); */
        process_declaration(root,  cur_scope);
        return;
    }

    if(strcmp(root->label, "assign_stmt") == 0) {
        /* printf("assgn\n"); */
        char* var_id = root->child[0]->child[0]->label;
        /* printf("checking for %s\n", var_id); */
        if(!isDeclared(var_id, cur_scope))
            undecerr(var_id);
        process_expression(root->child[2], cur_scope);
        return;
    }

    if(strcmp(root->label, "expression_stmt") == 0) {
        /* printf("expr\n"); */
        process_expression(root, cur_scope);
        return;
    }

    if(strcmp(root->label, "for_stmt") == 0) {
        /* printf("for_stmt\n"); */
        /* printTable(cur_scope); */
        table* child = changeScope(cur_scope);
        for(int i = 0 ; i < root->childCnt ; i++)
            init_table(root->child[i], child);
        return;
    }

    /* if(strcmp(root->label, "for_declare") == 0)  {
        table* child = changeScope(cur_scope);
        init_table(root->child[0], child);
    } else if(strcmp(root->label, "compound_stmt") == 0 && root->childCnt > 2) {
        table* child = changeScope(cur_scope);
        init_table(root->child[1], child);
        return;
    }
    else if(strcmp(root->label, "declaration") == 0) {
        process_declaration(root, cur_scope);
        return;
    } else if(strcmp(root->label, "expression_stmt") == 0 || strcmp(root->label, "assign_stmt") == 0) {
        process_expression(root, cur_scope);
        return;
    } */
    for(int i = 0 ; i < root->childCnt ; i++)
        init_table(root->child[i], cur_scope);
}

void printTable(table* cur) {
    printf("Childcount = %d entrycount = %d\n", cur->childCnt, cur->entryCnt);
    if(cur->entryCnt) {
        for(int i = 0 ; i < cur->entryCnt; i++)
            printf("%d. id - %s | type - %d | is function - %d\n", i + 1 , cur->entries[i]->id, cur->entries[i]->type, cur->entries[i]->isfunc);
    }
    for(int i = 0 ; i < cur->childCnt ; i++)
        printTable(cur->childTables[i]);    
}


int main() {
    cur_table = createTable();
    globalfuncs = createTable();
    yyparse();
    astNode* root = pop();
    /* printTree(root); */
    printf("\n\n---------Initiating Semantic Analysis---------\n\n");
    init_table(root, cur_table);
    printf("\n\n---------Semantic Analysis done---------\n---------Program is semantically correct---------\n\n");
    printf("\n\n---------Symbol Table---------\n\n");
    printTable(cur_table);
    printf("\n\n---------Global Function Table---------\n\n");
    printTable(globalfuncs);
}

int yyerror() {
    printf("Syntax error\n");
    exit(0);
}
