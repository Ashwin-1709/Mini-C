#include "simulate.h"
#include "assert.h"


bool isExpression(astNode *root){
    if(strcmp(root->label, ".expression_stmt") == 0)
        return true;
    return false;
}

bool isAssignment(astNode *root) {
    if(strcmp(root->label, ".assign_stmt") == 0)
        return true;
    return false;
}

bool isPrintf(astNode *root) {
    if(strcmp(root->label, ".print_stmt") == 0)
        return true;
    return false;
}

bool isFor(astNode* root) {
    if(strcmp(root->label, ".for_stmt") == 0)
        return true;
    return false;
}

bool isIf(astNode* root) {
    if(strcmp(root->label, ".if_stmt") == 0)
        return true;
    return false;
}

bool isSwitch(astNode* root) {
    if(strcmp(root->label, ".switch_stmt") == 0)
        return true;
    return false;
}

bool isFunction(astNode* root) {
    if(strcmp(root->label, ".functional_call") == 0)
        return true;
    return false;
}

bool isUnary(astNode* root) {
    if(strcmp(root->label, ".unary") == 0)
        return true;
    return false;
}

bool isVar(astNode* root) {
    if(strcmp(root->label, ".id") == 0)
        return true;
    return false;   
}

bool isArr(astNode* root) {
    if(strcmp(root->label, ".arr_element") == 0)
        return true;
    return false;   
}

bool isIconst(astNode* root) {
    if(strcmp(root->label, ".I_CONST") == 0)
        return true;
    return false; 
}

bool isFconst(astNode* root) {
    if(strcmp(root->label, ".F_CONST") == 0)
        return true;
    return false; 
}

bool isCharconst(astNode* root) {
    if(strcmp(root->label, ".CHAR_CONST") == 0)
        return true;
    return false; 
}

bool isCompound(astNode* root) {
    if(strcmp(root->label, ".compound_stmt") == 0)
        return true;
    return false;   
}

bool isExpr(astNode* root) {
    if(strcmp(root->label, ".expr") == 0)
        return true;
    return false;   
}

bool isWhile(astNode* root) {
    if(strcmp(root->label, ".while_stmt") == 0)
        return true;
    return false;   
}

bool isDeclaration(astNode* root) {
    if(strcmp(root->label, ".declaration") == 0)
        return true;
    return false;   
}

node *simulateUnary(astNode* root, table* scope) {
    node* curVal = simulateExpression(root -> child[1], scope);
    if(strcmp(root -> child[0] -> label, "-") == 0) {
        if(curVal->type == TY_INT)
            curVal->val.ival = -curVal->val.ival;
        else if(curVal->type == TY_FLOAT) 
            curVal->val.fval = -curVal->val.fval;
    } else {
        if(curVal -> type == TY_INT)
            curVal -> val.ival = !(curVal -> val.ival);
        else curVal -> val.fval = !(curVal -> val.fval);
        curVal -> type = TY_INT;
        return curVal;
    }
}

node* simulateArrElement(astNode* root, table* scope){
    int idx1 = atoi(root -> child[2] -> child[0] -> label), idx2 = -1;
    if (root -> childCnt == 7){
        idx2 = atoi(root -> child[5] -> child[0] -> label);
    }
    return getArrayValue(root -> child[0] -> child[0] -> label, scope, idx1, idx2);
}

node* simulateAssignment(astNode* root, table* scope){
    node* right = simulateExpression(root -> child[2], scope);
    node* result = (node *)(malloc(sizeof(node)));
    result -> type = TY_INT;
    result -> val.ival = 1;
    if(isVar(root -> child[0])){
        setVar(root -> child[0] -> child[0] -> label, scope, right);
    }
    if(isArr(root -> child[0])){
        int idx1 = atoi(root -> child[0] -> child[2] -> child[0] -> label), idx2 = -1;
        if (root -> child[0] -> childCnt == 7) 
            idx2 = atoi(root -> child[0] -> child[5] -> child[0] -> label);
        setArrayValue(root -> child[0] -> child[0] -> child[0] -> label, scope, idx1, idx2, right);
    }
    return result;
}

void findInitDec(astNode* root, table* scope) {
    if(strcmp(root->label, ".init_dec") == 0) {
        simulateDeclaration(root, scope);
        return;
    }
    for(int i = 0 ; i < root->childCnt; i++)
        findInitDec(root->child[i], scope);
}

void simulateDeclaration(astNode* root, table* scope){
    // root is init_declarator
    if (root -> childCnt == 3){
        node* right = simulateExpression(root -> child[2], scope);
        setVar(root -> child[0] -> child[0] -> child[0] -> label, scope, right); 
    }
}

void getPrintParams(astNode* root, node** arr, int* itr, table* scope){
    if(strcmp(root -> label , ".id") == 0) {
        node* id = simulateIdentifier(root, scope);
        arr[*itr] = id;
        *itr = *itr + 1;
        return;
    }
    if (strcmp(root -> label, ".I_CONST") == 0){
        node* id = (node *)(malloc(sizeof(node)));
        id -> val.ival = atoi(root -> child[0] -> label);
        id -> type = TY_INT;
        arr[*itr] = id;
        *itr = *itr + 1;
        return;
    }
    if (strcmp(root -> label, ".F_CONST") == 0){
        node* id = (node *)(malloc(sizeof(node)));
        id -> val.fval = atof(root -> child[0] -> label);
        id -> type = TY_FLOAT;
        arr[*itr] = id;
        *itr = *itr + 1;
        return;
    }
    if (strcmp(root -> label, ".CHAR_CONST") == 0){
        node* id = (node *)(malloc(sizeof(node)));
        id -> val.cval = root -> child[0] -> label[1];
        id -> type = TY_CHAR;
        arr[*itr] = id;
        *itr = *itr + 1;
        return;
    }
    if (strcmp(root -> label, ".arr_element") == 0){
        node* id = simulateArrElement(root, scope);
        arr[*itr] = id;
        *itr = *itr + 1;
        return;
    }
    for(int i = 0 ; i < root -> childCnt ; i++)
        getPrintParams(root -> child[i], arr, itr, scope);
}

void simulatePrinting(astNode* root, table* scope){
    char* str = root -> child[2] -> child[0] -> label;
    if (root -> childCnt == 5){
        for(int i = 1; i < strlen(str) - 1; i++){
            if (str[i] == '\\' && i < strlen(str) - 1){
                if (str[i + 1] == 'n'){
                    printf("\n");
                    i = i + 1;
                }
            }
            else{
                printf("%c", str[i]);
            }
        }
        return;
    }
    node** arr = (node**)(malloc(sizeof(node*) * 50));
    int itr = 0;
    getPrintParams(root, arr, &itr, scope);
    int ind = 0;
    for(int i = 1; i < strlen(str); i++){
        if (str[i] == '%' && i < strlen(str) - 1){
            if (itr == ind){
                printf("Error : print function needs more parameters.\n");
                exit(-1);
            }
            if (arr[ind] -> type == TY_INT){
                if (str[i + 1] != 'd'){
                    printf("Error : mismatch of variable type.\n");
                    exit(-1);
                }
                printf("%d", arr[ind] -> val.ival);
                i = i + 1;
            }
            if (arr[ind] -> type == TY_FLOAT){
                if (str[i + 1] != 'f'){
                    printf("Error : mismatch of variable type.\n");
                    exit(-1);
                }
                printf("%f", arr[ind] -> val.fval);
                i = i + 1;
            }
            if (arr[ind] -> type == TY_CHAR){
                if (str[i + 1] != 'c'){
                    printf("Error : mismatch of variable type.\n");
                    exit(-1);
                }
                printf("%c", arr[ind] -> val.cval);
                i = i + 1;
            }
            ind++;
        }
        else if (str[i] == '\\' && i < strlen(str) - 1){
            if (str[i + 1] == 'n'){
                printf("\n");
                i = i + 1;
            }
        }
        else{
            if (str[i] == '"'){
                break;
            }
            printf("%c", str[i]);
        }
        if (ind > itr){
            printf("Error : Print overloaded with parameters\n");
            exit(-1);
        }
    }
}

node* simulateExpression(astNode* root, table* scope) {
    node* curVal = (node *)(malloc(sizeof(node)));
    if(root -> childCnt == 1) {
        if(isIconst(root -> child[0])) {
            curVal -> val.ival = atoi(root -> child[0] -> child[0] -> label);
            curVal -> type = TY_INT;
            return curVal;
        }
        if(isFconst(root -> child[0])) {
            curVal -> val.fval = atof(root -> child[0] -> child[0]-> label);
            curVal -> type = TY_FLOAT;
            return curVal;   
        }
        if(isCharconst(root -> child[0])) {
            curVal -> val.cval = root -> child[0] -> child[0] -> label[1];
            curVal -> type = TY_CHAR;
            return curVal;
        }
        if(isUnary(root -> child[0])) {
            return simulateUnary(root -> child[0], scope);
        }
        if(isAssignment(root -> child[0])){
            return simulateAssignment(root -> child[0], scope);
        }
        if(isVar(root -> child[0])){
            return simulateIdentifier(root -> child[0], scope);
        }
        if(isArr(root -> child[0])){
            return simulateArrElement(root -> child[0], scope);
        }    
    }

    if (isExpression(root -> child[0])){
        node* left = simulateExpression(root -> child[0], scope);
        node* right = simulateExpression(root -> child[2], scope);
        if (strcmp(root -> child[1] -> label, "||") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) || (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "&&") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) && (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, ">") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) > (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "<") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) < (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, ">=") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) >= (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "<=") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) <= (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "==") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) == (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "!=") == 0){
            curVal -> val.ival = (left -> type == TY_INT ? (left -> val.ival) : (left -> type == TY_FLOAT ? (left -> val.fval) : left -> val.cval)) != (right -> type == TY_INT ? (right -> val.ival) : (right -> type == TY_FLOAT ? (right -> val.fval) : right -> val.cval));
            curVal -> type = TY_INT;
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "+") == 0){
            curVal -> type = ((left -> type == TY_INT) && (right -> type == TY_INT) ? TY_INT : TY_FLOAT);
            if (curVal -> type == TY_FLOAT)
                curVal -> val.fval = (left -> type == TY_INT ? (left -> val.ival) : (left -> val.fval)) + (right -> type == TY_INT ? (right -> val.ival) : (right -> val.fval));
            else{
                curVal -> val.ival = left -> val.ival + right -> val.ival;
            }
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "-") == 0){
            curVal -> type = ((left -> type == TY_INT) && (right -> type == TY_INT) ? TY_INT : TY_FLOAT);
            if (curVal -> type == TY_FLOAT)
                curVal -> val.fval = (left -> type == TY_INT ? (left -> val.ival) : (left -> val.fval)) - (right -> type == TY_INT ? (right -> val.ival) : (right -> val.fval));
            else{
                curVal -> val.ival = left -> val.ival - right -> val.ival;
            }
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "*") == 0){
            curVal -> type = ((left -> type == TY_INT) && (right -> type == TY_INT) ? TY_INT : TY_FLOAT);
            if (curVal -> type == TY_FLOAT)
                curVal -> val.fval = (left -> type == TY_INT ? (left -> val.ival) : (left -> val.fval)) * (right -> type == TY_INT ? (right -> val.ival) : (right -> val.fval));
            else{
                curVal -> val.ival = left -> val.ival * right -> val.ival;
            }
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "/") == 0){
            if (right -> type == TY_INT && right -> val.ival == 0){
                printf("Error : Divide by zero error\n");
                exit(-1);
            }
            if (right -> type == TY_FLOAT && right -> val.fval == 0.0){
                printf("Error : Divide by zero error\n");
                exit(-1);
            }
            curVal -> type = ((left -> type == TY_INT) && (right -> type == TY_INT) ? TY_INT : TY_FLOAT);
            if (curVal -> type == TY_FLOAT)
                curVal -> val.fval = (left -> type == TY_INT ? (left -> val.ival) : (left -> val.fval)) / (right -> type == TY_INT ? (right -> val.ival) : (right -> val.fval));
            else{
                curVal -> val.ival = left -> val.ival / right -> val.ival;
            }
            return curVal;
        }
        if (strcmp(root -> child[1] -> label, "%") == 0){
            if (left -> type == TY_FLOAT || right -> type == TY_FLOAT){
                printf("Error : % operator is expects integral type\n");
                exit(-1);
            }
            if (right -> type == TY_INT && right -> val.ival == 0){
                printf("Error : Divide by zero error\n");
                exit(-1);
            }
            curVal -> val.ival = (left -> val.ival) % (right -> val.ival);
            curVal -> type = TY_INT;
            return curVal;
        }
    }
    return simulateExpression(root -> child[1], scope);
}

node* simulateIdentifier(astNode* root, table* scope) {
    entry* entry = getEntry(scope, root -> child[0] -> label);
    node* curVal = (node *)(malloc(sizeof(node)));
    curVal->type = entry->type;
    if(entry->type == TY_INT) 
        curVal ->val.ival = entry->val.ival;
    else if(entry -> type == TY_FLOAT)
        curVal -> val.fval = entry->val.fval;
    else curVal -> val.cval = entry->val.cval;
    return curVal;
}

void setVar(char *id, table* scope, node* aval) {
    int ival = aval->val.ival;
    float fval = aval->val.fval;
    char cval = aval->val.cval;
    entry* entry = getEntry(scope, id);
    if(entry->type == TY_INT) {
        if(aval -> type == TY_INT)
            entry->val.ival = ival;
        else entry->val.ival = fval;
    }
    else if(entry->type == TY_FLOAT) {
        if(aval -> type == TY_FLOAT)
            entry->val.fval = fval;
        else entry->val.fval = ival;
    }
    else entry->val.cval = cval;
}

node* getArrayValue(char *id, table* scope, int id_1, int id_2) {
    entry* entry = getEntry(scope, id);
    node* curVal = (node *)(malloc(sizeof(node)));
    if(entry->type == TY_AIO) {
        curVal->type = TY_INT;
        curVal->val.ival = entry->val.iar[id_1];
    } else if(entry->type == TY_AIT) {
        curVal->type = TY_INT;
        curVal ->val.ival = entry->val.idr[id_1][id_2];
    }
    else if(entry->type == TY_AFO) {
        curVal->type = TY_FLOAT;
        curVal->val.fval = entry->val.far[id_1];
    } else if(entry->type == TY_AFT) {
        curVal->type = TY_FLOAT;
        curVal ->val.fval = entry->val.fdr[id_1][id_2];
    }
    else if(entry->type == TY_ACO) {
        curVal->type = TY_CHAR;
        curVal->val.cval = entry->val.car[id_1];
    } else if(entry->type == TY_ACT) {
        curVal->type = TY_CHAR;
        curVal ->val.cval = entry->val.cdr[id_1][id_2];
    }
    return curVal;
}

void setArrayValue(char *id, table* scope, int id_1, int id_2, node* aval) {
    entry* entry = getEntry(scope, id);
    int ival = aval->val.ival;
    float fval = aval->val.fval;
    char cval = aval->val.cval;
    if(entry->type == TY_AIO) {
        if(aval->type == TY_INT)
            entry ->val.iar[id_1] = ival;
        else if(aval->type == TY_FLOAT)
            entry->val.iar[id_1] = (int)fval;
        else entry->val.iar[id_1] = (int)cval;
    }
    else if(entry->type == TY_AIT) {
        if(aval->type == TY_INT)
            entry ->val.idr[id_1][id_2] = ival;
        else if(aval->type == TY_FLOAT)
            entry->val.idr[id_1][id_2] = (int)fval;
        else entry->val.idr[id_1][id_2] = (int)cval;
    }
    else if(entry->type == TY_AFO) {
        if(aval->type == TY_INT)
            entry ->val.far[id_1] = (float)ival;
        else if(aval->type == TY_FLOAT)
            entry->val.far[id_1] = fval;
        else entry->val.far[id_1] = (float)cval;
    }
    else if(entry->type == TY_AFT) {
        if(aval->type == TY_INT)
            entry ->val.fdr[id_1][id_2] = (float)ival;
        else if(aval->type == TY_FLOAT)
            entry->val.fdr[id_1][id_2] = fval;
        else entry->val.fdr[id_1][id_2] = (float)cval;
    }
    else if(entry->type == TY_ACO) {
        if(aval->type == TY_INT)
            entry ->val.car[id_1] = (char)ival;
        else if(aval->type == TY_FLOAT)
            entry->val.car[id_1] = (char)fval;
        else entry->val.car[id_1] = cval;
    }
    else if(entry->type == TY_ACT) {
        if(aval->type == TY_INT)
            entry ->val.cdr[id_1][id_2] = (char)ival;
        else if(aval->type == TY_FLOAT)
            entry->val.cdr[id_1][id_2] = (char)fval;
        else entry->val.cdr[id_1][id_2] = cval;
    }
}

void simulateWhile(astNode* root, table* scope) {
    node *exprNode = simulateExpression(root -> child[2], scope);
    bool flg = false;
    if(exprNode->type == TY_INT)
        flg = exprNode->val.ival;
    else if(exprNode->type == TY_FLOAT)
        flg = exprNode->val.fval;

    if(isCompound(root->child[4]->child[0])) {
        table *child = nextScope(scope);
        while(flg) {
            if(root->child[4]->child[0]->childCnt > 2)
                simulateStatementList(root->child[4]->child[0]->child[1], child);
                node *exprNode = simulateExpression(root -> child[2], child);
                if(exprNode->type == TY_INT)
                    flg = exprNode->val.ival;
                else if(exprNode->type == TY_FLOAT)
                    flg = exprNode->val.fval;
            resetTables(child);
        }
    } else {
        while(flg) {
            simulateStatement(root->child[4], scope);
            node *exprNode = simulateExpression(root -> child[2], scope);
            if(exprNode->type == TY_INT)
                flg = exprNode->val.ival;
            else if(exprNode->type == TY_FLOAT)
                flg = exprNode->val.fval;
        }
    }    
}

void simulateStatementList(astNode* root, table* scope) {
    simulateStatement(root->child[0], scope);
    if(root->childCnt > 1)
        simulateStatementList(root->child[1], scope);
}

void simulateStatement(astNode* root, table* scope) {
    astNode* stmt = root->child[0];
    if(isExpression(stmt)) 
        simulateExpression(stmt, scope);
    else if(isExpr(stmt))
        simulateExpr(stmt, scope);
    else if(isPrintf(stmt))
        simulatePrinting(stmt, scope);
    else if(isAssignment(stmt))
        simulateAssignment(stmt, scope);
    else if(isFor(stmt)) {
        table* child = nextScope(scope);
        simulateForStatement(stmt, child);
    }
    else if(isCompound(stmt))
        simulateCompoundStatement(stmt, scope);
    else if(isDeclaration(stmt))
        findInitDec(stmt, scope);
    else if(isWhile(stmt))
        simulateWhile(stmt, scope);
    else if(isIf(stmt))
        simulateIf(stmt, scope);    
        
}

void simulateCompoundStatement(astNode* root, table* scope) {
    if(root->childCnt > 2) {
        table* child = nextScope(scope);
        simulateStatementList(root ->child[1] , child);
    }
}

void simulateIf(astNode* root, table* scope) {
    node *exprNode = simulateExpression(root -> child[2], scope);
    bool flg = false;
    if(exprNode->type == TY_INT)
        flg = exprNode->val.ival;
    else if(exprNode->type == TY_FLOAT)
        flg = exprNode->val.fval;
    if(flg) simulateStatement(root -> child[4], scope);
    else if(root->childCnt > 6)simulateStatement(root -> child[6] -> child[1], scope);
}

node* simulateExpr(astNode* root, table* scope) {
    int childCnt = root -> childCnt;
    node *result = (node *)(malloc(sizeof(node)));
    if(childCnt == 2) return simulateExpression(root -> child[0], scope);
    else if(childCnt == 4){
        node* expr1 = simulateExpr(root -> child[0], scope);
        node* expr2 = simulateExpr(root -> child[2], scope);
        bool flg1 = (expr1 -> type == TY_INT) ? expr1 -> val.ival : expr1 -> val.fval;
        bool flg2 = (expr2 -> type == TY_INT) ? expr2 -> val.ival : expr2 -> val.fval;
       
        result->type = TY_INT;
        result->val.ival = (flg1 && flg2);
    }
    return result;
}

void simulateForAssignment(astNode* root, table* scope) {
    if(root -> childCnt == 1) 
        simulateAssignment(root -> child[0], scope);
    else if(root -> childCnt > 1) {
        simulateAssignment(root -> child[0], scope);
        simulateForAssignment(root -> child[2], scope);
    }
}

void simulateForDeclaration(astNode* root, table* scope) {
    if(isDeclaration(root->child[0])) {
        findInitDec(root -> child[0], scope);
        return;
    } else if(strcmp(root -> child[0] -> label, ".for_assign") == 0) 
        simulateForAssignment(root -> child[0], scope);
}

void simulateForStatement(astNode* root, table* scope){
    simulateForDeclaration(root->child[2], scope);
    node *exprNode = simulateExpr(root -> child[3], scope);
    bool flg = false;
    if(exprNode->type == TY_INT)
        flg = exprNode->val.ival;
    else if(exprNode->type == TY_FLOAT)
        flg = exprNode->val.fval;

    astNode* stmt = root -> child[6];
    if(isCompound(stmt -> child[0])) {
        table *child = nextScope(scope);
        while(flg) {
            if(stmt -> child[0] -> childCnt > 2)
                simulateStatementList(stmt -> child[0] -> child[1], child);
                simulateForAssignment(root -> child[4], scope);
                node *exprNode = simulateExpr(root -> child[3], scope);
                if(exprNode->type == TY_INT)
                    flg = exprNode->val.ival;
                else if(exprNode->type == TY_FLOAT)
                    flg = exprNode->val.fval;
            resetTables(child);
            resetTables(scope);
        }
    } else {
        while(flg) {
            if(stmt -> child[0] -> childCnt > 2)
                simulateStatementList(stmt -> child[0] -> child[1], scope);
                simulateForAssignment(root -> child[4], scope);
                node *exprNode = simulateExpr(root -> child[3], scope);
                if(exprNode->type == TY_INT)
                    flg = exprNode->val.ival;
                else if(exprNode->type == TY_FLOAT)
                    flg = exprNode->val.fval;
            resetTables(scope);
        }
    } 
}

void simulateMain(astNode* root, table* scope) {
    int lastChild = root -> childCnt - 1;
    simulateCompoundStatement(root -> child[lastChild], scope);
}

void simulateProgram(astNode* root, table* scope) {
    if(strcmp(root -> label, ".main_func") == 0) {
        simulateMain(root, scope);
        return;
    }
    for(int i = 0 ; i < root -> childCnt ; i++) 
        simulateProgram(root -> child[i], scope);
}
