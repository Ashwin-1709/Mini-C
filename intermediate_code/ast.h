#ifndef AST_H
#define AST_H

typedef enum {
    TY_UNDEFINED,
    TY_INT,
    TY_FLOAT,
    TY_CHAR,
    TY_AIO,
    TY_AFO,
    TY_AFT,
    TY_ACO,
    TY_ACT,
    TY_FUNCTION,
    TY_VOID,
} Type;

typedef struct astNode {
    int childCnt;
    struct astNode *child[55];
    Type type;
    char label[200];
} astNode;

#include "symboltable.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

astNode *createNode();
astNode *createNodeByVal(float val);
astNode *createNodeByIntVal(int val);
astNode *createNodeByLabel(char *label);
void addNode(astNode *parent, astNode *child);
void printTree(astNode *root);
astNode *passNode(char *label, int count, ...);
char *find_id(astNode *root);
void arg_dfs(astNode *root, int *cur, int *args);
int *get_args(astNode *root);

#endif
