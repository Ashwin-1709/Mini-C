CXX = g++
CC = gcc
CFLAGS = -Wall -g

all: lexer parser main

main: lex.yy.c y.tab.c ast.h ast.c symboltable.h symboltable.c simulate.h simulate.c
	$(CC) $(CFLAGS) ast.c symboltable.c simulate.c lex.yy.c y.tab.c -o simulation.out
lexer: lexer.l
	flex lexer.l
parser: parser.y
	yacc -d parser.y
clean:
	lex.yy.c y.tab.c y.tab.h
