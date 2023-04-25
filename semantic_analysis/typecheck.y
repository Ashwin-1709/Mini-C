%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    int yylex();
    float fans = 0.0;
    int ians =0; ;
%}
%token INT CHAR FLOAT NL
%union {
    struct {
        char type[10];
        union {
            int ival;
            float fval;
            char cval;
    } v;
} t;
}
%%
E : E '+' E NL {
    if (((strcmp($<t.type>1, "float") == 0 && strcmp($<t.type>3, "char") == 0 ))
        || ((strcmp($<t.type>1, "char") == 0 && strcmp($<t.type>3, "float") == 0 ))
        || ((strcmp($<t.type>1, "char") == 0 && strcmp($<t.type>3, "char") == 0 ))
        || ((strcmp($<t.type>1, "int") == 0 && strcmp($<t.type>3, "char") == 0 ))
        || ((strcmp($<t.type>1, "char") == 0 && strcmp($<t.type>3, "int") == 0 ))) {
        printf("At least One of the operands is char type cannot perform arithmetic\n");
    }

    if ((strcmp($<t.type>1 , "float") == 0 && strcmp($<t.type>3 , "float") == 0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 + $<t.v.fval>3;
        fans = $<t.v.fval>$ ; strcpy($<t.type>$, "Float");
        printf("Result of xpression is %s and value is :%f\n",$<t.type>$, fans);
    }

    if ((strcmp($<t.type>1 , "float") == 0 && strcmp($<t.type>3 , "int") == 0 )) {
        $<t.v.fval>$ = $<t.v.fval>1 + $<t.v.ival>3;
        fans = $<t.v.fval>$ ;strcpy($<t.type>$, "Float");
        printf("Result of xpression is %s and value is :%f\n",$<t.type>$, fans);
    }

    if ((strcmp($<t.type>1 , "int") == 0 && strcmp($<t.type>3 , "float") == 0 )) {
        $<t.v.fval>$ = $<t.v.ival>1 + $<t.v.fval>3 ;
        fans = $<t.v.fval>$ ;strcpy($<t.type>$, "Float");
        printf("Result of xpression is %s and value is :%f\n",$<t.type>$, fans);
    }

    if ((strcmp($<t.type>1 , "int") == 0 && strcmp($<t.type>3 , "int") == 0 )) {
        $<t.v.ival>$ = $<t.v.ival>1 + $<t.v.ival>3;
        ians = $<t.v.ival>$; strcpy($<t.type>$, "Int");
        printf("Result of xpression is %s and value is :%d\n",$<t.type>$, ians);
    }
    return 0;
}

E : CHAR {
    strcpy($<t.type>$, "char");
    $<t.v.cval>$ = $<t.v.cval>1;
}

E : INT {
    strcpy($<t.type>$, "int");
    $<t.v.ival>$ = $<t.v.ival>1;
}

E : FLOAT {
    strcpy($<t.type>$, "float");
    $<t.v.fval>$ = $<t.v.fval>1;
}
%%

int main() {
    printf("Give the expression: \n");
    yyparse();
    return 0;
}

void yyerror() {
    printf("Expression error: \n");
    exit(1);
}
