%{
#include "ast.h"
#include "stack.h"
#include "y.tab.h"

int yylex(void);


void yyerror(char const *s) {
    fprintf(stderr, "%s\n", s);
}

uint ic_idx = 0;
uint temp_var = 1;
uint is_for = 0;
uint is_while = 0;
uint is_for_1 = 0;
uint print_num = 0;

Stack *ifstack, *whilestack, *forstack;
uint ifIdx = 1, whileIdx = 1, forIdx = 1;
charStack *loops;
char globalFor[200];

%}


%union {
    int ival;
    float fval;
    char strval[200];
    astNode* node;
}

%token BREAK CASE CHAR CONTINUE DEFAULT ELSE FLOAT FOR IF RETURN
%token INT SWITCH VOID WHILE MAIN_FUNCTION
%token <strval> IDENTIFIER STRING_LITERAL CHAR_CONST
%token <ival> I_CONSTANT
%token <fval> F_CONSTANT
%token <node> AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP EQUAL_SIGN
%token <node> SEMICOLON LEFT_CURLY RIGHT_CURLY COMMA COLON LEFT_ROUND
%token <node> RIGHT_ROUND LEFT_SQUARE RIGHT_SQUARE
%token <node> EXCLAMATION HYPHEN PLUS STAR SLASH LT_OP GT_OP PERCENT UNARY_MINUS
%token <node> PRINTF_TOKEN


%type <node> s main_func functional_declaration P var_type
%type <node> func_type func_declarator param_list declare_var
%type <node> compound_statement statement_list single_statement
%type <node> switch_statment for_statement if_statement while_statement
%type <node> declaration jump_statement print_statement expr return_statement
%type <node> expression_statement unary_expr functional_call
%type <node> arr_element assignment_statement
%type <node> arg_list arg case_list_def case_list default_stmt case
%type <node> else_clause for_loop_assignment for_loop_declaration
%type <node> init_declarator init_declarator_list declarator_arr
%type <node> declarator_var print_params


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
s : P  {
    $$ = createNodeByLabel(".S");
    addNode($$, $1);
};

P : main_func { $$ = $1; }
| functional_declaration P { $$ = passNode(".P", 2, $1, $2); }
;

functional_declaration : func_type func_declarator compound_statement {
    $$ = passNode(".func_declaration", 3, $1, $2, $3);
    printf("ENDFUNCTION\n");
}
;

var_type : INT {
    $$ = passNode(".int", 0);
    $$->type = TY_INT;
}
| CHAR {
    $$ = passNode(".char", 0);
    $$->type = TY_CHAR;
}
| FLOAT {
    $$ = passNode(".float", 0);
    $$->type = TY_FLOAT;
}
;

func_type : var_type {
    $$ = passNode(".var_type", 1, $1);
    $$->type = $1->type;
}
| VOID {
    $$ = passNode(".void", 0);
    $$->type = TY_VOID;
}
;

func_declarator : IDENTIFIER LEFT_ROUND RIGHT_ROUND  {
    printf("FUNCTION %s\n", $1);
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".func_declarator", 3, identifier, left, right);
}
| IDENTIFIER LEFT_ROUND param_list RIGHT_ROUND {
    printf("FUNCTION %s\n", $1);
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".func_declarator", 4, identifier, left, $3, right);
}
;

param_list : declare_var {
    $$ = passNode(".param_list", 1, $1);
}
| declare_var COMMA param_list {
    astNode* c = createNodeByLabel("., ");
    $$ = passNode(".param_list", 3, $1, c, $3);
}
;

declare_var : var_type IDENTIFIER {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($2);
    addNode(identifier, actual_id);
    $$ = passNode(".declare_var", 2, $1, identifier);
}
;

/* Main Function Starts below */
main_func : MAIN_FUNCTION { printf("FUNCTION main\n"); } LEFT_ROUND RIGHT_ROUND compound_statement {
    astNode* main = createNodeByLabel(".main");
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".main_func", 4, main, left, right, $5);
    printf("ENDFUNCTION\n");
}
| INT MAIN_FUNCTION { printf("FUNCTION main\n"); } LEFT_ROUND RIGHT_ROUND compound_statement {
    astNode* type = createNodeByLabel(".int");
    astNode* main = createNodeByLabel(".main");
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".main_func", 5, type,  main, left, right, $6);
    printf("ENDFUNCTION\n");
}
| VOID MAIN_FUNCTION { printf("FUNCTION main\n"); } LEFT_ROUND RIGHT_ROUND compound_statement {
    astNode* type = createNodeByLabel(".void");
    astNode* main = createNodeByLabel(".main");
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".main_func", 5, type, main, left, right, $6);
    printf("ENDFUNCTION\n");
}
;

compound_statement : LEFT_CURLY RIGHT_CURLY {
    astNode* left = createNodeByLabel(".{");
    astNode* right = createNodeByLabel(".}");
    $$ = passNode(".compound_stmt", 2, left, right);
}
| LEFT_CURLY statement_list RIGHT_CURLY {
    astNode* left = createNodeByLabel(".{");
    astNode* right = createNodeByLabel(".}");
    $$ = passNode(".compound_stmt", 3, left, $2, right);
}
;

statement_list : single_statement { $$ = passNode(".stmt_list", 1, $1); }
            | single_statement statement_list { $$ = passNode(".stmt_list", 2, $1, $2); }
;
single_statement : switch_statment { $$ = passNode(".single_stmt", 1, $1); }
| expr { $$ = passNode(".single_stmt", 1, $1); }
| if_statement { $$ = passNode(".single_stmt", 1, $1); }
| print_statement { $$ = passNode(".single_stmt", 1, $1); }
| for_statement { $$ = passNode(".single_stmt", 1, $1); }
| return_statement { $$ = passNode(".single_stmt", 1, $1); }
| while_statement  { $$ = passNode(".single_stmt", 1, $1); }
| jump_statement  { $$ = passNode(".single_stmt", 1, $1); }
| declaration { $$ = passNode(".single_stmt", 1, $1); }
| compound_statement { $$ = passNode(".single_stmt", 1, $1); }
;

jump_statement : BREAK SEMICOLON {
    astNode* breakNode = createNodeByLabel(".break");
    astNode* semicolon = createNodeByLabel(".;");
    if (is_for_1) {
        printf("\tgoto FL%d\n", is_for_1);
    } else {
        printf("\tgoto WL%d\n", is_while);
    }
    $$ = passNode(".jump_stmt", 2, breakNode, semicolon);
}
| CONTINUE SEMICOLON {
    astNode* continueNode = createNodeByLabel(".continue");
    astNode* semicolon = createNodeByLabel(".;");
    if (is_for_1) {
        printf("\tgoto FL%d\n", is_for_1 - 1);
    } else {
        printf("\tgoto WL%d\n", is_while - 1);
    }
    $$ = passNode(".jump_stmt", 2, continueNode, semicolon);
}
;

return_statement : RETURN expr {
    astNode* returnNode = createNodeByLabel(".return");
    $$ = passNode(".return_stmt", 2, returnNode, $2);
    printf("\treturn t%d\n", $2->tIdx);
}
;
/* Expression */
expr : SEMICOLON {
     $$ = passNode(".expr", 1, createNodeByLabel(".;"));
}
| expression_statement SEMICOLON {
    $$ = passNode(".expr", 2, $1, createNodeByLabel(".;"));
    printf("\tt%d := t%d\n", temp_var, $1->tIdx);
    $$->tIdx = temp_var++;
}
| expr COMMA expr SEMICOLON {
    $$ = passNode(".expr", 4, $1, createNodeByLabel("., "), $3, createNodeByLabel(".;"));
}
;

expression_statement : expression_statement OR_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".||"), $3);
    if (!is_for) {
        printf("\tt%d := t%d || t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d || t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement AND_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".&&"), $3);
    if (!is_for) {
        printf("\tt%d := t%d && t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d && t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement GT_OP expression_statement  {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".>"), $3);
    if (!is_for) {
        printf("\tt%d := t%d > t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d > t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement LT_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".<"), $3);
    if (!is_for) {
        printf("\tt%d := t%d < t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d < t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement GE_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".>="), $3);
    if (!is_for) {
        printf("\tt%d := t%d >= t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d >= t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement LE_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".<="), $3);
    if (!is_for) {
        printf("\tt%d := t%d <= t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d <= t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement PLUS expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".+"), $3);
    if (!is_for) {
        printf("\tt%d := t%d + t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d + t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement HYPHEN expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".-"), $3);
    if (!is_for) {
        printf("\tt%d := t%d - t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d - t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement STAR expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".*"), $3);
    if (!is_for) {
        printf("\tt%d := t%d * t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d * t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement SLASH expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel("./"), $3);
    if (!is_for) {
        printf("\tt%d := t%d / t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d / t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement PERCENT expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".%"), $3);
    if (!is_for) {
        printf("\tt%d := t%d %% t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d %% t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement EQ_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".=="), $3);
    if (!is_for) {
        printf("\tt%d := t%d == t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d == t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| expression_statement NE_OP expression_statement {
    $$ = passNode(".expression_stmt", 3, $1, createNodeByLabel(".!="), $3);
    if (!is_for) {
        printf("\tt%d := t%d != t%d\n", temp_var, $1->tIdx, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := t%d != t%d\n", temp_var, $1->tIdx, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$->tIdx = temp_var++;
}
| unary_expr { $$ = passNode(".expression_stmt", 1, $1); }
| assignment_statement {
    $$ = passNode(".expression_stmt", 1, $1);
    $$->tIdx = $1->tIdx;
}
| functional_call { $$ = passNode(".expression_stmt", 1, $1); }
| LEFT_ROUND expression_statement RIGHT_ROUND {
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".expression_stmt", 3, left, $2, right);
}
| I_CONSTANT {
    if (!is_for) {
        printf("\tt%d := %d\n", temp_var, $<ival>$);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := %d\n", temp_var, $<ival>$);
        strcat(globalFor, buf);
    }
    astNode* iconst = createNodeByLabel(".x I_CONST");
    astNode* val = createNodeByIntVal($1);
    addNode(iconst, val);
    $$ = passNode(".expression_stmt", 1, iconst);
    $$->tIdx = temp_var++;
}
| F_CONSTANT {
    if (!is_for) {
        printf("\tt%d := %f\n", temp_var, $<fval>$);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := %f\n", temp_var, $<fval>$);
        strcat(globalFor, buf);
    }
    astNode* fconst = createNodeByLabel(".x F_CONST");
    astNode* fval = createNodeByVal($1);
    addNode(fconst, fval);
    $$ = passNode(".expression_stmt", 1, fconst);
    $$->tIdx = temp_var++;
}
| STRING_LITERAL {
    if (!is_for) {
        printf("\tt%d := %s\n", temp_var, $<strval>$);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d := %s\n", temp_var, $<strval>$);
        strcat(globalFor, buf);
    }
    astNode* string_literal = createNodeByLabel(".STRING_LITERAL");
    astNode* sval = createNodeByLabel($1);
    addNode(string_literal, sval);
    $$ = passNode(".expression_stmt", 1, string_literal);
    $$->tIdx = temp_var++;
}
| CHAR_CONST {
    if (!is_for) {
        printf("\tt%d := %s\n", temp_var, $<strval>$);
    } else {
        char* buf = calloc(5, sizeof(char));
        sprintf(buf, "\tt%d := %s\n", temp_var, $<strval>$);
        strcat(globalFor, buf);
    }
    astNode* char_literal = createNodeByLabel(".CHAR_CONST");
    astNode* cval = createNodeByLabel($1);
    addNode(char_literal, cval);
    cval->type = TY_CHAR;
    $$ = passNode(".expression_stmt", 1 , char_literal);    
    $$->tIdx = temp_var++;
}
| arr_element {
    char *array = $1->child[0]->child[0]->label;
    char *index = $1->child[2]->child[0]->label;
    if (!is_for) {
        printf("\tt%d = %s[%s]\n", temp_var, array, index);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\tt%d = %s[%s]\n", temp_var, array, index);
        strcat(globalFor, buf);
    }
    astNode* equalto = createNodeByLabel(".=");
    $$ = passNode(".expression_stmt", 1, $1);
    $$->tIdx = temp_var++;
}
| IDENTIFIER {
  astNode* identifier = createNodeByLabel(".id");
  astNode* actual_id = createNodeByLabel($1);
  addNode(identifier, actual_id);
  if (!is_for) {
      printf("\tt%d := %s\n", temp_var, $1);
  } else {
      char* buf = calloc(30, sizeof(char));
      sprintf(buf, "\tt%d := %s\n", temp_var, $1);
      strcat(globalFor, buf);
  }
  $$ = passNode(".expression_stmt", 1, identifier);
  $$->tIdx = temp_var++;
};

unary_expr : EXCLAMATION expression_statement %prec EXCLAMATION { $$ = passNode(".unary", 2, createNodeByLabel(".!"), $2); }
| HYPHEN expression_statement %prec UNARY_MINUS { $$ = passNode(".unary", 2, createNodeByLabel(".-"), $2); }

functional_call : IDENTIFIER LEFT_ROUND RIGHT_ROUND {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".functional_call", 3, identifier, left, right);
}
| IDENTIFIER LEFT_ROUND arg_list RIGHT_ROUND {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".(");
    astNode* right = createNodeByLabel(".)");
    $$ = passNode(".functional_call", 4, identifier, left, $3, right);
}
;

arg_list : arg { $$ = passNode(".arg_list", 1, $1); }
| arg COMMA arg_list {
    astNode* c = createNodeByLabel("., ");
    $$ = passNode(".arg_list", 3, $1, c, $3);
}
;
arg : expression_statement { $$ = passNode(".arg", 1, $1); };
arr_element : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    astNode* iconst = createNodeByLabel(".I_CONST");
    astNode* val = createNodeByIntVal($3);
    addNode(iconst, val);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".[");
    astNode* right = createNodeByLabel(".]");
    $$ = passNode(".arr_element", 4, identifier, left, iconst, right);
}
| IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    astNode* iconst = createNodeByLabel(".I_CONST");
    astNode* val = createNodeByIntVal($3);
    addNode(iconst, val);
    addNode(identifier, actual_id);
    astNode* left = createNodeByLabel(".[");
    astNode* right = createNodeByLabel(".]");
    astNode* left_2 = createNodeByLabel(".[");
    astNode* right_2 = createNodeByLabel(".]");
    astNode* iconst_2 = createNodeByLabel(".I_CONST");
    astNode* val_2 = createNodeByIntVal($6);
    addNode(iconst_2, val_2);
    $$ = passNode(".arr_element", 7, identifier, left, iconst, right, left_2, iconst_2, right_2);
}
;

/* Assignment */
assignment_statement : IDENTIFIER EQUAL_SIGN expression_statement %prec EQUAL_SIGN{
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* equalto = createNodeByLabel(".=");
    if (!is_for) {
        printf("\t%s := t%d\n", $1, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\t%s := t%d\n", $1, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$ = passNode(".assign_stmt", 3, identifier, equalto, $3);
    $$->tIdx = $3->tIdx;
}
| arr_element EQUAL_SIGN expression_statement %prec EQUAL_SIGN {
    char *array = $1->child[0]->child[0]->label;
    char *index = $1->child[2]->child[0]->label;
    astNode* equalto = createNodeByLabel(".=");
    if (!is_for) {
        printf("\t%s[%s] = t%d\n", array, index, $3->tIdx);
    } else {
        char* buf = calloc(30, sizeof(char));
        sprintf(buf, "\t%s[%s] = t%d\n", array, index, $3->tIdx);
        strcat(globalFor, buf);
    }
    $$ = passNode(".assign_stmt", 3, $1, equalto, $3);
    $$->tIdx = $3->tIdx;
}
;

/* Switch-case */
switch_statment : SWITCH LEFT_ROUND expression_statement RIGHT_ROUND LEFT_CURLY case_list_def RIGHT_CURLY{
    astNode* switch_terminal = createNodeByLabel(".switch");
    astNode* left_round = createNodeByLabel(".(");
    astNode* right_round = createNodeByLabel(".)");
    astNode* left_curly = createNodeByLabel(".{");
    astNode* right_curly = createNodeByLabel(".}");
    $$ = passNode(".switch_stmt", 7, switch_terminal, left_round, $3, right_round, left_curly, $6, right_curly);
}
;
case_list_def : case_list { $$ = passNode(".case_list_def", 1, $1); }
| case_list default_stmt { $$ = passNode(".case_list_def", 2, $1, $2); }
| { $$ = passNode(".case_list_def", 0); }
;
case_list : case { $$ = passNode(".case_list", 1, $1); }
| case_list case { $$ = passNode(".case_list", 2, $1, $2); };
case : CASE expression_statement COLON statement_list {
    astNode* case_st = createNodeByLabel(".case");
    astNode* colon = createNodeByLabel(".:");
    $$ = passNode(".case_st", 4, case_st, $2, colon, $4);
}
| CASE expression_statement COLON {
    astNode* case_st = createNodeByLabel(".case");
    astNode* colon = createNodeByLabel(".:");
    $$ = passNode(".case_st", 3, case_st, $2, colon);
}
;
default_stmt : DEFAULT COLON statement_list {
    astNode* default_st = createNodeByLabel(".default");
    astNode* colon = createNodeByLabel(".:");
    $$ = passNode(".default_stmt", 3, default_st, colon, $3);
}
| DEFAULT COLON {
    astNode* default_st = createNodeByLabel(".default");
    astNode* colon = createNodeByLabel(".:");
    $$ = passNode(".default_stmt", 2, default_st, colon);
}
;

/* if else */
if_statement: IF LEFT_ROUND expression_statement {
    printf("\tif !(t%d) goto IL%d\n", $3->tIdx, ifIdx);
    stackPush(ifstack, ifIdx++);
} RIGHT_ROUND single_statement {
    unsigned int lbl = stackPop(ifstack);
    printf("\tgoto IL%d\n", ifIdx);
    stackPush(ifstack, ifIdx++);
    printf("IL%d:\n", lbl);
} else_clause {
    astNode* if_st = createNodeByLabel(".if");
    astNode* left_round = createNodeByLabel(".(");
    astNode* right_round = createNodeByLabel(".)");
    $$ = passNode(".if_stmt", 6, if_st, left_round, $3, right_round, $6, $8);
    printf("IL%d:\n", stackPop(ifstack));
}
;
else_clause : ELSE single_statement {
    astNode* else_st = createNodeByLabel(".else");
    $$ = passNode(".else_clause", 2, else_st, $2);
}
| {
    $$ = passNode(".else_clause", 0);
}
;
/* For loop */
for_loop_assignment : assignment_statement { $$ = passNode(".for_assign", 1, $1); }
| assignment_statement COMMA for_loop_assignment {
    astNode* comma = createNodeByLabel("., ");
    $$ = passNode(".for_assign", 3, $1, comma, $3);
}
| { $$ = passNode(".for_assign", 0); }
;
for_loop_declaration : declaration { $$ = passNode(".for_declare", 1, $1); }
| SEMICOLON { astNode* semicolon = createNodeByLabel(".;"); $$ = passNode(".for_declare", 1, semicolon); }
;
for_statement : FOR LEFT_ROUND for_loop_declaration {
    printf("FL%d:\n", forIdx);
    stackPush(forstack, forIdx+1);
    stackPush(forstack, forIdx++);
    stackPush(forstack, forIdx++);
} expr {
    printf("\tif !(t%d) goto FL%d\n", $5->tIdx, stackPop(forstack));
    is_for++;
} for_loop_assignment {
    charStackPush(loops, globalFor);
    memset(globalFor, '\0', sizeof(globalFor[0]));
    is_for--;
    is_for_1 = forIdx - 1;
} RIGHT_ROUND single_statement {
    is_for_1 -= 2;
    printf("%s\n", charStackPop(loops));
    printf("\tgoto FL%d\n", stackPop(forstack));
    printf("FL%d:\n", stackPop(forstack));
    astNode* for_st = createNodeByLabel(".for");
    astNode* left_round = createNodeByLabel(".(");
    astNode* right_round = createNodeByLabel(".)");
    $$ = passNode(".for_stmt", 7, for_st, left_round, $3, $5, $7, right_round, $10);
}
;

/* declaration */
declaration : var_type init_declarator_list SEMICOLON {
    astNode* semicolon = createNodeByLabel(".;");
    $$ = passNode(".declaration", 3, $1, $2, semicolon);
}
;
init_declarator_list : init_declarator_list COMMA init_declarator {
    astNode* comma = createNodeByLabel("., ");
    $$ = passNode(".init_dec_list", 3, $1, comma, $3);
}
| init_declarator { $$ = passNode(".init_dec_list", 1, $1); }
;
init_declarator : declarator_var EQUAL_SIGN expression_statement {
    astNode* equalto = createNodeByLabel(".=");
    printf("\t%s := t%d\n", $1->varname, $3->tIdx);
    $$ = passNode(".init_dec", 3, $1, equalto, $3);
}
| declarator_var { $$ = passNode(".init_dec", 1, $1); }
| declarator_arr { $$ = passNode(".init_dec", 1, $1); }
;
declarator_var : IDENTIFIER {
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    $$ = passNode(".dec_var", 1, identifier);
    strcpy($$->varname, $1);
}
;
declarator_arr : IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE{
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left_square = createNodeByLabel(".[");
    astNode* right_square = createNodeByLabel(".]");
    astNode* iconst = createNodeByLabel(".I_CONST");
    astNode* val = createNodeByIntVal($3);
    addNode(iconst, val);
    $$ = passNode(".dec_arr", 4, identifier, left_square, iconst, right_square);
}
| IDENTIFIER LEFT_SQUARE I_CONSTANT RIGHT_SQUARE LEFT_SQUARE I_CONSTANT RIGHT_SQUARE{
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* left_square = createNodeByLabel(".[");
    astNode* right_square = createNodeByLabel(".]");
    astNode* iconst1 = createNodeByLabel(".I_CONST");
    astNode* val1 = createNodeByIntVal($3);
    addNode(iconst1, val1);
    astNode* iconst2 = createNodeByLabel(".I_CONST");
    astNode* val2 = createNodeByIntVal($6);
    addNode(iconst2, val2);
    $$ = passNode(".dec_arr", 7, identifier, left_square, iconst1, right_square, left_square, iconst2, right_square);
}
;
/* While */
while_statement : WHILE {
    printf("\tWL%d:\n", whileIdx);
    stackPush(whilestack, whileIdx+1);
    stackPush(whilestack, whileIdx++);
    stackPush(whilestack, whileIdx++);
} LEFT_ROUND expression_statement RIGHT_ROUND {
    is_while = whileIdx - 1;
    printf("\tif (!t%d) goto WL%d;\n", $4->tIdx, stackPop(whilestack));
} single_statement {
    is_while -= 2;
    printf("\tgoto WL%d;\n", stackPop(whilestack));
    printf("WL%d:\n", stackPop(whilestack));
    astNode* while_st = createNodeByLabel(".while");
    astNode* left_round = createNodeByLabel(".(");
    astNode* right_round = createNodeByLabel(".)");
    $$ = passNode(".while_stmt", 5, while_st, left_round, $4, right_round, $7);
}
;

/* Printf and scanf */
print_statement : PRINTF_TOKEN LEFT_ROUND STRING_LITERAL RIGHT_ROUND SEMICOLON{
    printf("\tprintf %s\n", $3);
    astNode* printf_tk = createNodeByLabel(".printf");
    astNode* left_round = createNodeByLabel(".(");
    astNode* string_lit = createNodeByLabel(".string");
    astNode* string_lit_actual = createNodeByLabel($3);
    addNode(string_lit, string_lit_actual);
    astNode* right_round = createNodeByLabel(".)");
    astNode* semicolon = createNodeByLabel(".;");
    $$ = passNode(".print_stmt", 5, printf_tk, left_round, string_lit, right_round, semicolon);
} | PRINTF_TOKEN LEFT_ROUND STRING_LITERAL COMMA print_params RIGHT_ROUND SEMICOLON {
    printf("\tprintf %s, %d\n", $3, print_num);
    astNode* printf_tk = createNodeByLabel(".printf");
    astNode* left_round = createNodeByLabel(".(");
    astNode* string_lit = createNodeByLabel(".string");
    astNode* string_lit_actual = createNodeByLabel($3);
    addNode(string_lit, string_lit_actual);
    astNode* comma = createNodeByLabel("., ");
    astNode* right_round = createNodeByLabel(".)");
    astNode* semicolon = createNodeByLabel(".;");
    $$ = passNode(".print_stmt", 7, printf_tk, left_round, string_lit, comma, $5, right_round, semicolon);
}
;
print_params : IDENTIFIER {
    print_num++;
    printf("\tpush %s\n", $1);
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    $$ = passNode(".print_params", 1, identifier);
}
| IDENTIFIER COMMA print_params {
    print_num++;
    printf("\tpush %s\n", $1);
    astNode* identifier = createNodeByLabel(".id");
    astNode* actual_id = createNodeByLabel($1);
    addNode(identifier, actual_id);
    astNode* comma = createNodeByLabel("., ");
    $$ = passNode(".print_params", 3, identifier, comma, $3);
}
;
%%

int main() {
    ifstack = newStack();
    whilestack = newStack();
    forstack = newStack();
    loops = newCharStack();
    yyparse();
}
