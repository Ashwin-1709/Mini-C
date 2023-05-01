#ifndef SIMULATE_H
#define SIMULATE_H

#include "ast.h"
#include "symboltable.h"

typedef union value {
    int ival;
    float fval;
    char cval;
} value;

typedef struct node{
    value val;
    Type type;
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
node *simulateExpression(astNode* root, table* scope);
node *simulateUnary(astNode* root, table* scope);
node *simulateIdentifier(astNode* root, table* scope);
node *simulateArrElement(astNode* root, table* scope);
node *simulateAssignment(astNode* root, table* scope);
node *simulateFunctionCall(astNode* root, table* scope);
void setValue(char *id, table* scope, Type type, void *value);


#endif
