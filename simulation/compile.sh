#!/bin/env bash
CC=gcc
CFLAGS="-Wall -g"


flex lexer.l
yacc -d parser.y
${CC} "${CFLAGS}" ast.c symboltable.c simulate.c lex.yy.c y.tab.c -o simulation.out
