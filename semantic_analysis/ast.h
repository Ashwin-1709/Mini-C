#ifndef AST_H
#define AST_H

typedef struct astNode {
    int childCnt;
    struct astNode *child[55];
    int type;
    char label[200];
} astNode;

#include "symboltable.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/*
    type -> 0 - int
    type -> 1 - float
    type -> 2 - char
    type -> 3 - int *
    type -> 4 - int **
    type -> 5 - float *
    type -> 6 - float **
    type -> 7 - char *
    type -> 8 - char **
*/

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
