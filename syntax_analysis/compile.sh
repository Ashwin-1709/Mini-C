#!/bin/env bash
yacc -d parser.y
flex lexer.l
gcc lex.yy.c y.tab.c -ll -o syntax.out
