#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include <stdarg.h>
#include <stdbool.h>
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

int type(char *id);
char *retype(int type);
int vtoi(void *p);

char vtoc(void *p);

float vtof(void *p);

int *vtoa(void *p);

float *vtofa(void *p);

char *vtoca(void *p);

typedef struct entry {
    char *id;    // identifier
    void *value; // value
    int x_lim;   // if array then array len, if func number of parameters
    int y_lim;   // if 2D array then col lim
    int type;    // type of var
    bool isfunc;
    int *parameters; // func parameters
    astNode *node;   // pointer to node if any
} entry;

typedef struct table {
    struct entry *entries[30];
    int childCnt;
    int entryCnt;
    struct table *childTables[10];
    struct table *parent;
} table;

table *createTable();
void chainTable(table *parent, table *child);
entry *createVarEntry(char *id, int type, void *value, int x_lim, int y_lim);
void insert(entry *curentry, table *cur);
void insertvar(char *id, int type, void *value, int x_lim, int y_lim,
               table *curtable);
bool searchTable(table *cur, char *id);
bool isDeclared(char *id, table *cur);
int typevar(table *cur, char *id);
table *changeScope(table *cur);
void insertfunc(char *id, int type, table *curtable, int *args, bool hasargs, astNode* fnode);

#endif
