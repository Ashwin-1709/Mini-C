CXX = g++
CC = gcc
CFLAGS = -Wall -g

all: lexer parser main

main: lex.yy.c y.tab.c
	$(CC) $(CFLAGS) lex.yy.c y.tab.c -lfl -o compiler
lexer: lexer.l
	flex lexer.l
parser: parser.y
	yacc -d parser.y
