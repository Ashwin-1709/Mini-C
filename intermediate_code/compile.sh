#!/bin/env bash
CC=gcc
CFLAGS=-"g -Wall -Wno-format-overflow -Wshadow -Wconversion -Wpedantic -Wno-float-equal -Wno-variadic-macros"



flex lexer.l
yacc -d parser.y
${CC} "${CFLAGS}" ast.h ast.c stack.c symboltable.c lex.yy.c y.tab.c -o intermediate.out
