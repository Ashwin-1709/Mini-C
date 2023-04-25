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
    
} table;

#endif