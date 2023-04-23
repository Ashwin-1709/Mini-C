#!/usr/bin/env bash
yacc -d parser.y
lex lexer.l
gcc lex.yy.c y.tab.c -lfl -o compiler

