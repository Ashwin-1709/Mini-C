%{
    #include "y.tab.h"    
    int lNum=1;
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

"break"					{printf("%d\t%s\t%s",lNum,yytext,"BREAK"); return BREAK; }
"case"					{printf("%d\t%s\t%s",lNum,yytext,"CASE"); return CASE; }
"char"					{printf("%d\t%s\t%s",lNum,yytext,"CHAR"); return CHAR; }
"continue"				{printf("%d\t%s\t%s",lNum,yytext,"CONTINUE"); return CONTINUE; }
"default"				{printf("%d\t%s\t%s",lNum,yytext,"DEFAULT"); return DEFAULT; }
"else"					{printf("%d\t%s\t%s",lNum,yytext,"ELSE"); return ELSE; }
"float"					{printf("%d\t%s\t%s",lNum,yytext,"FLOAT"); return FLOAT; }
"for"					{printf("%d\t%s\t%s",lNum,yytext,"FOR"); return FOR; }
"if"					{printf("%d\t%s\t%s",lNum,yytext,"IF"); return IF; }
"int"					{printf("%d\t%s\t%s",lNum,yytext,"INT"); return INT; }
"return"				{printf("%d\t%s\t%s",lNum,yytext,"RETURN"); return RETURN; }
"switch"				{printf("%d\t%s\t%s",lNum,yytext,"SWITCH"); return SWITCH; }
"void"					{printf("%d\t%s\t%s",lNum,yytext,"VOID"); return VOID; }
"while"					{printf("%d\t%s\t%s",lNum,yytext,"WHILE"); return WHILE; }
"main"                  {printf("%d\t%s\t%s",lNum,yytext,"MAIN_FUNCTION");return MAIN_FUNCTION;}
"printf"                {printf("%d\t%s\t%s",lNum,yytext,"PRINTF_TOKEN");return PRINTF_TOKEN;}

{LETTER}{ALNUM}*					{printf("%d\t%s\t%s",lNum,yytext,"IDENTIFIER");return IDENTIFIER;}

("0"|{NONZERO}({DIGIT}*))				{printf("%d\t%s\t%s",lNum,yytext,"I_CONSTANT");return I_CONSTANT; }
"'"([^'\\\n]|{ESCAPE_SEQUENCE})+"'"		{printf("%d\t%s\t%s",lNum,yytext,"I_CONSTANT");return I_CONSTANT; }

{DIGIT}+{EXPONENT}{FLOAT_SUFFIX}?				{printf("%d\t%s\t%s",lNum,yytext,"F_CONSTANT"); return F_CONSTANT; }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOAT_SUFFIX}?			{printf("%d\t%s\t%s",lNum,yytext,"F_CONSTANT"); return F_CONSTANT; }
{DIGIT}+"."{EXPONENT}?{FLOAT_SUFFIX}?			{printf("%d\t%s\t%s",lNum,yytext,"F_CONSTANT"); return F_CONSTANT; }

(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	{printf("%d\t%s\t%s",lNum,yytext,"STRING_LITERAL"); return STRING_LITERAL; }

"&&"					{printf("%d\t%s\t%s",lNum,yytext,"AND_OP"); return AND_OP; }
"||"					{printf("%d\t%s\t%s",lNum,yytext,"OR_OP"); return OR_OP; }
"<="					{printf("%d\t%s\t%s",lNum,yytext,"LE_OP"); return LE_OP; }
">="					{printf("%d\t%s\t%s",lNum,yytext,"GE_OP"); return GE_OP; }
"=="					{printf("%d\t%s\t%s",lNum,yytext,"EQ_OP"); return EQ_OP; }
"!="					{printf("%d\t%s\t%s",lNum,yytext,"NE_OP"); return NE_OP; }
";"					{printf("%d\t%s\t%s",lNum,yytext,"SEMICOLON"); return SEMICOLON; }
"{"     				{printf("%d\t%s\t%s",lNum,yytext,"LEFT_CURLY"); return LEFT_CURLY; }
"}"     				{printf("%d\t%s\t%s",lNum,yytext,"RIGHT_CURLY"); return RIGHT_CURLY; }
","					{printf("%d\t%s\t%s",lNum,yytext,"COMMA"); return COMMA; }
":"					{printf("%d\t%s\t%s",lNum,yytext,"COLON"); return COLON; }
"="					{printf("%d\t%s\t%s",lNum,yytext,"EQUAL_SIGN"); return EQUAL_SIGN; }
"("					{printf("%d\t%s\t%s",lNum,yytext,"LEFT_ROUND"); return LEFT_ROUND; }
")"					{printf("%d\t%s\t%s",lNum,yytext,"RIGHT_ROUND"); return RIGHT_ROUND; }
"["     			{printf("%d\t%s\t%s",lNum,yytext,"LEFT_SQUARE"); return LEFT_SQUARE; }
"]"     			{printf("%d\t%s\t%s",lNum,yytext,"RIGHT_SQUARE"); return RIGHT_SQUARE; }
"!"					{printf("%d\t%s\t%s",lNum,yytext,"EXALAMATION"); return EXCLAMATION; }
"-"					{printf("%d\t%s\t%s",lNum,yytext,"HYPHEN"); return HYPHEN; }
"+"					{printf("%d\t%s\t%s",lNum,yytext,"PLUS"); return PLUS; }
"*"					{printf("%d\t%s\t%s",lNum,yytext,"STAR"); return STAR; }
"/"					{printf("%d\t%s\t%s",lNum,yytext,"SLASH"); return SLASH; }
"%"					{printf("%d\t%s\t%s",lNum,yytext,"PERCENT"); return PERCENT; }
"<"					{printf("%d\t%s\t%s",lNum,yytext,"LT_OP"); return LT_OP; }
">"					{printf("%d\t%s\t%s",lNum,yytext,"GT_OP"); return GT_OP; }
"\n"                     {lNum++;}
{WHITESPACE}+					{ /* whitespace separates tokens */ }
.					{ error("Error in lexical Analysis\n"); }

%%

int yywrap(void) {       /* called at end of input */ 
    return 1;           /* terminate now */
}
