yacc -d $1
flex lexer.l
gcc ast.c symboltable.c lex.yy.c y.tab.c -o a.out