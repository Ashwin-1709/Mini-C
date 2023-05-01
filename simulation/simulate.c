#include "simulate.h"

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
    if(strcmp(root->label, ".printf") == 0)
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

bool isWhile(astNode* root) {
    if(strcmp(root->label, ".while_stmt") == 0)
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

node *simulateUnary(astNode* root, table* scope) {
    node* curVal = simulateExpression(root -> child[1], scope);
    if(strcmp(root -> child[0] -> label, "-") == 0) {
        if(curVal == TY_INT)
            curVal->val.ival = -curVal->val.ival;
        else if(curVal == TY_FLOAT) 
            curVal->val.fval = -curVal->val.fval;
    } else {
        if(curVal -> type == TY_INT)
            curVal -> val.ival = !(curVal -> val.ival);
        else curVal -> val.fval = !(curVal -> val.fval);
        curVal -> type = TY_INT;
        return curVal;
    }
}

node* simulateIdentifier(astNode* root, table* scope){
    node* id = (node *)(malloc(sizeof(node)));
    id -> type = root -> child[0] -> type;
    if (root -> child[0] -> type == TY_INT){
        id -> val.ival = 
    }
}

node* simulateArrElement(astNode* root, table* scope){
    node* id = simulateIdentifier(root -> child[0], scope);
    node* idx1 = (node *)(malloc(sizeof(node)));
    idx1 -> val.ival = atoi(root -> child[2] -> child[0] -> label);
    idx1 -> type = TY_INT;
    if (root -> childCnt == 7){
        node* idx2 = (node *)(malloc(sizeof(node)));
        idx2 -> val.ival = atoi(root -> child[5] -> child[0] -> label);
        idx2 -> type = TY_INT;
    }
}

node* simulateAssignment(astNode* root, table* scope){
    node* right = simulateExpression(root -> child[2], scope);
    if(isVar(root -> child[0])){
        node* left = simulateIdentifier(root -> child[0], scope);
    }
    if(isArr(root -> child[0])){
        node* left = simulateArrElement(root -> child[0], scope);
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
            curVal -> val.cval = root -> child[0] -> label[1];
            curVal -> type = TY_CHAR;
            return curVal;
        }
        if(isUnary(root -> child[0])) {
            simulateUnary(root -> child[0], scope);
        }
        if(isAssignment(root -> child[0])){
            simulateAssignment(root -> child[0], scope);
        }
        if(isVar(root -> child[0])){
            simulateIdentifier(root -> child[0], scope);
        }
        if(isArr(root -> child[0])){
            simulateArrElement(root -> child[0], scope);
        }
        
        
    }
}

node* simulateIdentifier(astNode* root, table* scope) {
    entry* entry = getEntry(scope, root -> child[0] -> label);
    node* curVal = (node *)(malloc(sizeof(node)));
    curVal->type = entry->type;
    if(entry->type == TY_INT) 
        curVal ->val.ival = vtoi(entry->value);
    else if(entry -> type == TY_FLOAT)
        curVal -> val.fval = vtof(entry -> value);
    else curVal -> val.cval = vtoc(entry -> value);
    return curVal;
}

void setValue(char *id, table* scope, Type type, void *value) {
    entry* entry = getEntry(scope, id);
    if(type == TY_INT) {
        int new_val = vtoi(entry->value);
    }
}