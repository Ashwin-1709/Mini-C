#include "ast.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

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
    for (int i = 0; i < 30; i++) {
        cur->entries[i] = NULL;
        cur->visited[i] = false;
    }
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

entry *createVarEntry(char *id, Type type, void *value, int x_lim, int y_lim) {
    entry *cur = (entry *)(malloc(sizeof(entry)));
    cur->id = strdup(id);
    cur->type = type;
    cur->value = value;
    cur->x_lim = x_lim;
    cur->y_lim = y_lim;
    cur->isfunc = false;
    cur->node = NULL;
    if(x_lim > 0 && y_lim == -1) {
        if(type == 1) {
            int *arr = (int *)malloc(sizeof(int) * x_lim);
            cur->value = (void *)&arr;
        } else if(type == 2) {
            float *arr = (float *)malloc(sizeof(float) * x_lim);
            cur->value = (void *)&arr;
        } else {
            char *arr = (char *)malloc(sizeof(char) * x_lim);
            cur->value = (void *)&arr;
        }
    } else if(x_lim > 0 && y_lim > 0) {
        if(type == 1) {
            int **arr = (int **)malloc(sizeof(int*) * x_lim);
            for(int i = 0 ; i < x_lim ; i++)
                arr[i] = (int *)malloc(sizeof(int) * y_lim);
            cur->value = (void *)&arr;
        } else if(type == 2) {
            float **arr = (float **)malloc(sizeof(float*) * x_lim);
            for(int i = 0 ; i < x_lim ; i++)
                arr[i] = (float *)malloc(sizeof(float) * y_lim);
            cur->value = (void *)&arr;
        } else {
            char **arr = (char **)malloc(sizeof(char*) * x_lim);
            for(int i = 0 ; i < x_lim ; i++)
                arr[i] = (char *)malloc(sizeof(char) * y_lim);
            cur->value = (void *)&arr;
        }
    }
    return cur;
}

void insert(entry *curentry, table *cur) {
    int c = cur->entryCnt++;
    cur->entries[c] = curentry;
}

void insertvar(char *id, Type type, void *value, int x_lim, int y_lim,
               table *curtable) {
    entry *cur = createVarEntry(id, type, value, x_lim, y_lim);
    insert(cur, curtable);
}

bool searchTable(table *cur, char *id) {
    // printf("here = %s %d\n", id, cur->entryCnt);
    for (int i = 0; i < cur->entryCnt; i++) {
        // printf("entry = %s\n", cur->entries[i]->id);
        if (strcmp(id, cur->entries[i]->id) == 0)
            return true;
    }
    return false;
}

bool isDeclared(char *id, table *cur) {
    // printf("here isdeclared = %s\n", id);
    while (cur != NULL) {
        if (searchTable(cur, id))
            return true;
        cur = cur->parent;
    }
    return false;
}

Type typevar(table *cur, char *id) {
    while (cur != NULL) {
        for (int i = 0; i < cur->entryCnt; i++) {
            if (strcmp(id, cur->entries[i]->id) == 0)
                return cur->entries[i]->type;
        }
        cur = cur->parent;
    }
    return TY_UNDEFINED;
}

entry* getEntry(table* cur, char *id) {
    while (cur != NULL) {
        for (int i = 0; i < cur->entryCnt; i++) {
            if (strcmp(id, cur->entries[i]->id) == 0)
                return cur->entries[i];
        }
        cur = cur->parent;
    }
    assert("entry not found in symbol table");
    return NULL;
}

table *changeScope(table *cur) {
    table *child = createTable();
    chainTable(cur, child);
    return child;
}

void insertfunc(char *id, Type type, table *curtable, int *args, bool hasargs, astNode* fnode) {
    entry *cur = (entry *)(malloc(sizeof(entry)));
    cur->id = strdup(id);
    cur->type = type;
    cur->isfunc = true;
    int count = 0;
    if(hasargs) {
        for (int j = 0; j < 50; j++) {
            if (args[j] == 100) {
                count = j;
                break;
            }
        }
        // printf("argcount = %d\n", count);
        cur->x_lim = count;
    }
    else cur->x_lim = -1;
    cur->y_lim = -1;
    if (hasargs)
        cur->parameters = args;
    cur->node = fnode;
    insert(cur, curtable);
}

table* nextScope(table* cur) {
    for(int i = 0 ; i < cur->childCnt ; i++)
        if(!cur->visited[i]) {
            cur->visited[i] = true;
            return cur->childTables[i];
        }
    assert("Cannot change scope");
    return NULL;
}

void resetTables(table* scope) {
    assert(scope != NULL);
    for(int i = 0 ; i < 30 ; i++)
        scope->visited[i] = false;
    for(int i = 0 ; i < scope -> childCnt ; i++)
        resetTables(scope -> childTables[i]);
}
