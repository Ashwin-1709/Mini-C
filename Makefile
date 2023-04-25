CXX = g++
CC = gcc
CFLAGS = -Wall -g -lfl

# all: lexical syntax semantic

SEMANTIC_FILES = semantic_analysis/lexer.l semantic_analysis/parser.y semantic_analysis/ast.h semantic_analysis/symboltable.h

semantic: $(SEMANTIC_FILES)
	cd semantic_analysis && make
