#ifndef SIMULATE_H
#define SIMULATE_H

#include "ast.h"
#include "symboltable.h"



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
bool isCompound(astNode* root);
bool isExpr(astNode* root);
bool isWhile(astNode* root);
bool isDeclaration(astNode* root);
node *simulateExpression(astNode* root, table* scope);
node *simulateUnary(astNode* root, table* scope);
node *simulateIdentifier(astNode* root, table* scope);
node *simulateArrElement(astNode* root, table* scope);
node *simulateAssignment(astNode* root, table* scope);
void simulateStatementList(astNode* root, table* scope);
void simulateStatement(astNode* root, table* scope);
void simulateCompoundStatement(astNode* root, table* scope);
node* simulateExpr(astNode* root, table* scope);
void simulateForStatement(astNode* root, table* scope);
void simulateForDeclaration(astNode* root, table* scope);
void simulateForAssignment(astNode* root, table* scope);
// node *simulateFunctionCall(astNode* root, table* scope);
void setVar(char *id, table* scope, node* aval);
node* getArrayValue(char *id, table* scope, int id_1, int id_2);
void setArrayValue(char *id, table* scope, int id_1, int id_2, node* aval);
// node* simulateFunction(astNode* root, table* scope);
void simulateDeclaration(astNode* root, table* scope);
void getPrintParams(astNode* root, node** arr, int* itr, table* scope);
void simulatePrinting(astNode* root, table* scope);
void simulateIf(astNode* root, table* scope);
void simulateWhile(astNode* root, table* scope);
void findInitDec(astNode* root, table* scope);
void simulateMain(astNode* root, table* scope);
void simulateProgram(astNode* root, table* scope);
#endif
