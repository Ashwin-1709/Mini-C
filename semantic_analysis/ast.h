#ifndef AST_H
#define AST_H

#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "symboltable.h"

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

typedef struct astNode {
    int childCnt;
    struct astNode* child[55];
    int type;
    char label[200];
} astNode;

static astNode* createNode() {
    astNode* cur = (astNode *)(malloc(sizeof(astNode)));
    cur->childCnt = 0;
    for(int i = 0 ; i < 200 ; i++)
        cur->label[i] = 0;
    for(int i = 0; i < 55 ; i++)
        cur->child[i] = NULL;
    cur->type = -1;
    return cur;    
}

static astNode* createNodeByVal(float val) {
    astNode* cur = createNode();
    char buf[50];
    gcvt(val, 10 , buf);
    strcpy(cur->label, buf);
    cur->type = type("float");
    return cur;    
}

static astNode* createNodeByIntVal(int val) {
    astNode* cur = createNode();
    char buf[50];
    sprintf(buf, "%d" , val);
    strcpy(cur->label, buf);
    cur->type = type("int");
    return cur;    
}

static astNode* createNodeByLabel(char *label) {
    astNode* cur = createNode();
    strcpy(cur->label, label);
    return cur;
}

static void addNode(astNode* parent, astNode* child) {
    if(parent == NULL) {
        printf("parent is null\n");
        return;
    }
    int c = parent->childCnt++;
    astNode **children = parent->child;
    children[c] = child;
}

static void printTree(astNode *root) {
    printf("[%s ", root->label);
    int c = root->childCnt;
    for(int i = 0; i < c ; i++)
        printTree(root->child[i]);
    printf("]");
}

static astNode* passNode(char *label,int count,...) {
    va_list arglist;
    astNode* cur = createNode();
    va_start(arglist, count);
    for(int i = 0 ; i < count ; i++)
        addNode(cur, va_arg(arglist, astNode*));
    strcpy(cur->label, label);
    va_end(arglist);
    return cur;
}

#endif