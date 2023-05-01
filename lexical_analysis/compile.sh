#!/bin/env bash
flex lexer.l
gcc lex.yy.c -ll -o lexer
