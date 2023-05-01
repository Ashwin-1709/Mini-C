#!/bin/env bash
CC=gcc
CFLAGS="-Wall -g"

flex lexer.l
yacc -d parseNew.y
${CC} "${CFLAGS}" ast.c symboltable.c lex.yy.c y.tab.c -o semantic_analyzer.out
