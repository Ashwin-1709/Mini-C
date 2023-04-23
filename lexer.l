%{
#include <stdio.h>
#include "y.tab.h"

extern int sym_type(const char *);  /* returns type from symbol table */

void error(char *msg) {
    printf("%s\n", msg);
    exit(0);
}

%}


DIGIT           [0-9]
NONZERO         [1-9]
LETTER          [a-zA-Z_]
ALNUM           [a-zA-Z_0-9]
EXPONENT        ([Ee][+-]?{DIGIT}+)
FLOAT_SUFFIX    (f|F|l|L)
ESCAPE_SEQUENCE (\\(['"\?\\abfnrtv]))
WHITESPACE      [ \t\v\n\f]

%%
"/*"(.|\n|\s)*"*/"                                 {/*comment();*/ }
"//".*                                    { /* consume //-comment */ }

"break"					{ return BREAK; }
"case"					{ return CASE; }
"char"					{ return CHAR; }
"continue"				{ return CONTINUE; }
"default"				{ return DEFAULT; }
"else"					{ return ELSE; }
"float"					{ return FLOAT; }
"for"					{ return FOR; }
"if"					{ return IF; }
"int"					{ return INT; }
"return"				{ return RETURN; }
"switch"				{ return SWITCH; }
"void"					{ return VOID; }
"while"					{ return WHILE; }
"main"                  {return MAIN_FUNCTION;}
"printf"                {return PRINTF_TOKEN;}
"scanf"                 {return SCANF_TOKEN;}

{LETTER}{ALNUM}*					{ return IDENTIFIER; /*TODO: check_type() */}

("0"|{NONZERO}({DIGIT}*))				{ yylval.iconst = atoi(yytext); return I_CONSTANT; }
"'"([^'\\\n]|{ESCAPE_SEQUENCE})+"'"		{ return I_CONSTANT; }

{DIGIT}+{EXPONENT}{FLOAT_SUFFIX}?				{ yylval.dconst = atof(yytext); return F_CONSTANT; }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOAT_SUFFIX}?			{yylval.dconst = atof(yytext); return F_CONSTANT; }
{DIGIT}+"."{EXPONENT}?{FLOAT_SUFFIX}?			{ yylval.dconst = atof(yytext); return F_CONSTANT; }

(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	{ return STRING_LITERAL; }

"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
";"					{ return SEMICOLON; }
"{"     				{ return LEFT_CURLY; }
"}"     				{ return RIGHT_CURLY; }
","					{ return COMMA; }
":"					{ return COLON; }
"="					{ return EQUAL_SIGN; }
"("					{ return LEFT_ROUND; }
")"					{ return RIGHT_ROUND; }
"["     				{ return LEFT_SQUARE; }
"]"     				{ return RIGHT_SQUARE; }
"."					{ return DOT; }
"&"					{ return AMPERSAND; }
"!"					{ return EXCLAMATION; }
"-"					{ return HYPHEN; }
"+"					{ return PLUS; }
"*"					{ return STAR; }
"/"					{ return SLASH; }
"%"					{ return PERCENT; }
"<"					{ return LT_OP; }
">"					{ return GT_OP; }

{WHITESPACE}+					{ /* whitespace separates tokens */ }
.					{ error("Error in lexical Analysis\n"); }

%%

int yywrap(void) {       /* called at end of input */ 
    return 1;           /* terminate now */
}
