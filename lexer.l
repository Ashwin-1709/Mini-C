%{
#include <stdio.h>


extern int sym_type(const char *);  /* returns type from symbol table */

//#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

//static void comment(void);
//static int check_type(void);
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
"double"				{ return DOUBLE; }
"else"					{ return ELSE; }
"float"					{ return FLOAT; }
"for"					{ return FOR; }
"if"					{ return IF; }
"int"					{ return INT; }
"long"					{ return LONG; }
"return"				{ return RETURN; }
"short"					{ return SHORT; }
"switch"				{ return SWITCH; }
"void"					{ return VOID; }
"while"					{ return WHILE; }

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
";"					{ return ';'; }
"{"     				{ return '{'; }
"}"     				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
"["     				{ return '['; }
"]"     				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }

{WS}+					{ /* whitespace separates tokens */ }
.					{ return ERROR; }

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

// static void comment(void)
// {
//     int c;
//
//     while ((c = input()) != 0)
//         if (c == '*')
//         {
//             while ((c = input()) == '*')
//                 ;
//
//             if (c == '/')
//                 return;
//
//             if (c == 0)
//                 break;
//         }
//     yyerror("unterminated comment");
// }

//static int check_type(void)
//{
//    switch (sym_type(yytext))
//    {
//    case TYPEDEF_NAME:                /* previously defined */
//        return TYPEDEF_NAME;
//    case ENUMERATION_CONSTANT:        /* previously defined */
//        return ENUMERATION_CONSTANT;
//    default:                          /* includes undefined */
//        return IDENTIFIER;
//    }
//}

int main() {
    yylex();
}
