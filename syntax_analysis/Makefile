exec:
	yacc -d parser.y
	flex lexer.l
	gcc lex.yy.c y.tab.c -ll