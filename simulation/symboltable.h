#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "ast.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef union value {
    int ival;
    float fval;
    char cval;
} value;

int vtoi(void *p);

char vtoc(void *p);

float vtof(void *p);

int *vtoa(void *p);

float *vtofa(void *p);

char *vtoca(void *p);

typedef struct entry {
    char *id;    // identifier
    void *value; // value
    value val;
    int x_lim;   // if array then array len, if func number of parameters
    int y_lim;   // if 2D array then col lim
    Type type;   // type of var
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
    bool visited[30];
} table;

table *createTable();
void chainTable(table *parent, table *child);
entry *createVarEntry(char *id, Type type, void *value, int x_lim, int y_lim);
void insert(entry *curentry, table *cur);
void insertvar(char *id, Type type, void *value, int x_lim, int y_lim,
               table *curtable);
bool searchTable(table *cur, char *id);
bool isDeclared(char *id, table *cur);
Type typevar(table *cur, char *id);
table *changeScope(table *cur);
void insertfunc(char *id, Type type, table *curtable, int *args, bool hasargs, astNode* fnode);
table *nextScope(table* cur);
Type typevar(table *cur, char *id);
entry* getEntry(table* cur, char *id);
void resetTables(table* scope);
#endif
