CXX = g++
CC = gcc
CFLAGS = -g -Wall

all: lex.yy.c y.tab.c intermediate.out

intermediate.out: stack.h stack.c lex.yy.c y.tab.c ast.h ast.c symboltable.h symboltable.c
	$(CC) $(CFLAGS) ast.h ast.c stack.c symboltable.c lex.yy.c y.tab.c -o $@

lex.yy.c: lexer.l
	flex lexer.l
y.tab.c: parser.y
	yacc -d parser.y
clean:
	rm lex.yy.c y.tab.c y.tab.h intermediate.out
