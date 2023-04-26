CXX = g++
CC = gcc
CFLAGS = -Wall -g

all: lexer parser main

main: lex.yy.c y.tab.c ast.h ast.c symboltable.h symboltable.c
	$(CC) $(CFLAGS) ast.c symboltable.c lex.yy.c y.tab.c -o semantic_analyzer.out
lexer: lexer.l
	flex lexer.l
parser: parser.y
	yacc -d parser.y
clean:
	lex.yy.c y.tab.c y.tab.h
