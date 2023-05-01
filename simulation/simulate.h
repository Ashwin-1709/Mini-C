#ifndef SIMULATE_H
#define SIMULATE_H

#include "ast.h"
#include "symboltable.h"

typedef union value {
    int ival;
    float fval;
    char cval;
} value;

typedef struct node {
    
} node;

bool isExpression(astNode *root);
bool isAssignment(astNode *root);
bool isPrintf(astNode *root);
bool isFor(astNode* root);
bool isIf(astNode* root);
bool isSwitch(astNode* root);
bool isWhile(astNode* root);
bool isFunction(astNode* root);
bool isUnary(astNode* root);
bool isVar(astNode* root);
bool isArr(astNode* root);
bool isIconst(astNode* root);
bool isFconst(astNode* root);
bool isCharconst(astNode* root);
value simulateExpression(astNode* root, table* scope);

#endif
