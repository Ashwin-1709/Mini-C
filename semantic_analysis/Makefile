CXX = g++
CC = gcc
CFLAGS = -Wall -g -lfl

all: lexer parser main

main: lex.yy.c y.tab.c
	$(CC) $(CFLAGS) lex.yy.c y.tab.c -o semantic_analyzer.out
lexer: lexer.l
	flex lexer.l
parser: parser.y
	yacc -d parser.y
clean:
	lex.yy.c y.tab.c y.tab.h
