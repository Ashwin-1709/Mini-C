%{
#include <stdio.h>
#include "y.tab.h"
extern int sym_type(const char *);  /* returns type from symbol table */
void error(char *msg) {
    printf("%s\n", msg);
    exit(0);
}
%}

%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

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

{L}{A}*					{ return IDENTIFIER; /*TODO: check_type() */}

{HP}{H}+{IS}?				{ return I_CONSTANT; }
{NZ}{D}*{IS}?				{ return I_CONSTANT; }
"0"{O}*{IS}?				{ return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ return I_CONSTANT; }

{D}+{E}{FS}?				{ return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{ return F_CONSTANT; }
{D}+"."{E}?{FS}?			{ return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{ return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ return STRING_LITERAL; }

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

{WS}+					{ /* whitespace separates tokens */ }
.					{ error("Error in lexical Analysis\n"); }

%%

int yywrap(void) {       /* called at end of input */ 
    return 1;           /* terminate now */
}
