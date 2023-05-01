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

value simulateExpression(astNode* root, table* scope) {
    value curVal;
    if(root -> childCnt == 1) {
        if(isIconst(root)) 
            curVal.ival = atoi(root -> child[0] -> label);
        if(isFconst(root))
            curVal.fval = atof(root -> child[0] -> label);
        if(isCharconst(root))
            curVal.cval = root -> child[0] -> label[1];
        if(isUnary(root)) {
            
        }
    }
}