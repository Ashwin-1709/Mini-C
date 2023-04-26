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

int type(char *id) {
    if (strcmp(id, "int") == 0)
        return 0;
    if (strcmp(id, "float") == 0)
        return 1;
    if (strcmp(id, "char") == 0)
        return 2;
    if (strcmp(id, "aio") == 0)
        return 3;
    if (strcmp(id, "ait") == 0)
        return 4;
    if (strcmp(id, "afo") == 0)
        return 5;
    if (strcmp(id, "aft") == 0)
        return 6;
    if (strcmp(id, "aco") == 0)
        return 7;
    if (strcmp(id, "act") == 0)
        return 8;
    if (strcmp(id, "function") == 0)
        return 9;
    return 10; // void
}

char *retype(int type) {
    char *id;
    switch (type) {
    case 0:
        id = "int";
        return id;
    case 1:
        id = "float";
        return id;
    case 2:
        id = "char";
        return id;
    case 3:
        id = "aio";
        return id;
    case 4:
        id = "ait";
        return id;
    case 5:
        id = "afo";
        return id;
    case 6:
        id = "aft";
        return id;
    case 7:
        id = "aco";
        return id;
    case 8:
        id = "act";
        return id;
    case 9:
        id = "function";
        return id;
    case 10:
        id = "void";
        return id;
    }
    id = "N/A";
    return id;
}

int vtoi(void *p) { return *(int *)p; }

char vtoc(void *p) { return *(char *)p; }

float vtof(void *p) { return *(float *)p; }

int *vtoa(void *p) {
    int *n = (int *)p;
    return n;
}

float *vtofa(void *p) {
    float *n = (float *)p;
    return n;
}

char *vtoca(void *p) {
    char *n = (char *)p;
    return n;
}

table *createTable() {
    table *cur = (table *)(malloc(sizeof(table)));
    cur->childCnt = 0;
    for (int i = 0; i < cur->childCnt; i++)
        cur->childTables[i] = NULL;
    cur->parent = NULL;
    cur->entryCnt = 0;
    for (int i = 0; i < 30; i++)
        cur->entries[i] = NULL;
    return cur;
}

void chainTable(table *parent, table *child) {
    if (parent == NULL) {
        printf("parent is null\n");
        return;
    }
    int cnt = parent->childCnt++;
    parent->childTables[cnt] = child;
    child->parent = parent;
}

entry *createVarEntry(char *id, int type, void *value, int x_lim, int y_lim) {
    entry *cur = (entry *)(malloc(sizeof(entry)));
    cur->id = strdup(id);
    cur->type = type;
    cur->value = value;
    cur->x_lim = x_lim;
    cur->y_lim = y_lim;
    cur->isfunc = false;
    cur->node = NULL;
    return cur;
}

void insert(entry *curentry, table *cur) {
    int c = cur->entryCnt++;
    cur->entries[c] = curentry;
}

void insertvar(char *id, int type, void *value, int x_lim, int y_lim,
               table *curtable) {
    entry *cur = createVarEntry(id, type, value, x_lim, y_lim);
    insert(cur, curtable);
}

bool searchTable(table *cur, char *id) {
    for (int i = 0; i < cur->entryCnt; i++) {
        if (strcmp(id, cur->entries[i]->id) == 0)
            return true;
    }
    return false;
}

bool isDeclared(char *id, table *cur) {
    while (cur != NULL) {
        if (searchTable(cur, id))
            return true;
        cur = cur->parent;
    }
    return false;
}

int typevar(table *cur, char *id) {
    while (cur != NULL) {
        for (int i = 0; i < cur->entryCnt; i++) {
            if (strcmp(id, cur->entries[i]->id) == 0)
                return cur->entries[i]->type;
        }
        cur = cur->parent;
    }
    return -1;
}

table *changeScope(table *cur) {
    table *child = createTable();
    chainTable(cur, child);
    return child;
}

void insertfunc(char *id, int type, table *curtable, int *args, bool hasargs, astNode* fnode) {
    entry *cur = (entry *)(malloc(sizeof(entry)));
    cur->id = strdup(id);
    cur->type = type;
    cur->isfunc = true;
    int count = 0;
    for (int j = 0; j < 50; j++) {
        if (args[j] == 100) {
            count = j;
            break;
        }
    }
    // printf("argcount = %d\n", count);
    cur->x_lim = count;
    cur->y_lim = -1;
    if (hasargs)
        cur->parameters = args;
    cur->node = fnode;
    insert(cur, curtable);
}
