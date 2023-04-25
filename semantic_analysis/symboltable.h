#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
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
    if(strcmp(id , "int") == 0)
        return 0;
    if(strcmp(id , "float") == 0)
        return 1;
    if(strcmp(id , "char") == 0)
        return 2;
    if(strcmp(id , "aio") == 0)
        return 3;
    if(strcmp(id , "ait") == 0)
        return 4;
    if(strcmp(id , "afo") == 0)
        return 5;
    if(strcmp(id , "aft") == 0)
        return 6;
    if(strcmp(id , "aco") == 0)
        return 7;
    if(strcmp(id , "act") == 0)
        return 8;
    return 9; // function
}

int vtoi(void *p) {
    return *(int *)p;
}

char vtoc(void *p) {
    return *(char *)p;
}

float vtof(void *p) {
    return *(float *)p;
}

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

typedef struct entry {
    char *id; // identifier
    void *value; // value
    int x_lim; // if array then row lim, if func number of parameters
    int y_lim; // if 2D array then col lim
    int type; // type of var
    bool isfunc;
    int *parameters; // func parameters
} entry;

typedef struct table {
    struct entry* entries[30];
    int childCnt;
    int entryCnt;
    struct table* childTables[10];
    struct table* parent;
} table;


static table* createTable() {
    table* cur = (table *)(malloc(sizeof(table)));
    cur->childCnt = 0;
    for(int i = 0 ; i < cur->childCnt ; i++)
        cur->childTables[i] = NULL;
    cur->parent = NULL;
    cur->entryCnt = 0;
    for(int i = 0 ; i < 30 ; i++)
        cur->entries[i] = NULL;
    return cur;
}

static void chainTable(table* parent, table* child) {
    if(parent == NULL) {
        printf("parent is null\n");
        return;
    }
    int cnt = parent->childCnt++;
    parent->childTables[cnt] = child;
    child->parent = parent;
}

static entry* createVarEntry(char *id, int type, void *value, int x_lim, int y_lim) {
    entry* cur = (entry *)(malloc(sizeof(entry)));
    cur->id = strdup(id);
    cur->type = type;
    cur->value = value;
    cur->x_lim = x_lim;
    cur->y_lim = y_lim;
    cur->isfunc = false;
    return cur;
}

static void insert(entry* curentry, table* cur) {
    int c = cur->entryCnt++;
    cur->entries[c] = curentry;
}

static void insertvar(char *id, int type, void *value, int x_lim, int y_lim , table *curtable) {
    entry* cur = createVarEntry(id , type , value , x_lim, y_lim);
    insert(cur, curtable);
}

static bool searchTable(table* cur, char *id) {
    for(int i = 0 ; i < cur->entryCnt; i++) {
        if(strcmp(id , cur->entries[i]->id) == 0)
            return true;
    }
    return false;
}

static bool isDeclared(char *id, table* cur) {
    while(cur != NULL) {
        if(searchTable(cur , id))
            return true;
        cur = cur->parent;
    }
    return false;
}

static int typevar(table* cur , char *id) {
    while(cur != NULL) {
        for(int i = 0 ; i < cur->entryCnt; i++) {
            if(strcmp(id , cur->entries[i]->id) == 0)
                return cur->entries[i]->type;
        }
        cur = cur->parent;
    }
    return -1;
}

static table* changeScope(table* cur) {
    table *child = createTable();
    chainTable(cur , child);
    return child;
}

#endif