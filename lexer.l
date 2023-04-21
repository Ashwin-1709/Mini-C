%{
#include <stdio.h>

//extern void yyerror(const char *);  /* prints grammar violation message */

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
"/*"                                    { /*comment();*/ }
"//".*                                    { /* consume //-comment */ }

"break"					{ printf("BREAK\n"); }
"case"					{ printf("CASE\n"); }
"char"					{ printf("CHAR\n"); }
"continue"				{ printf("CONTINUE\n"); }
"default"				{ printf("DEFAULT\n"); }
"double"				{ printf("DOUBLE\n"); }
"else"					{ printf("ELSE\n"); }
"float"					{ printf("FLOAT\n"); }
"for"					{ printf("FOR\n"); }
"if"					{ printf("IF\n"); }
"int"					{ printf("INT\n"); }
"long"					{ printf("LONG\n"); }
"return"				{ printf("RETURN\n"); }
"short"					{ printf("SHORT\n"); }
"switch"				{ printf("SWITCH\n"); }
"void"					{ printf("VOID\n"); }
"while"					{ printf("WHILE\n"); }

{L}{A}*					{ printf("IDENTIFIER\n"); /*TODO: check_type() */}

{HP}{H}+{IS}?				{ printf("I_CONSTANT\n"); }
{NZ}{D}*{IS}?				{ printf("I_CONSTANT\n"); }
"0"{O}*{IS}?				{ printf("I_CONSTANT\n"); }
{CP}?"'"([^'\\\n]|{ES})+"'"		{ printf("I_CONSTANT\n"); }

{D}+{E}{FS}?				{ printf("F_CONSTANT\n"); }
{D}*"."{D}+{E}?{FS}?			{ printf("F_CONSTANT\n"); }
{D}+"."{E}?{FS}?			{ printf("F_CONSTANT\n"); }
{HP}{H}+{P}{FS}?			{ printf("F_CONSTANT\n"); }
{HP}{H}*"."{H}+{P}{FS}?			{ printf("F_CONSTANT\n"); }
{HP}{H}+"."{P}{FS}?			{ printf("F_CONSTANT\n"); }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ printf("STRING_LITERAL\n"); }

"&&"					{ printf("AND_OP\n"); }
"||"					{ printf("OR_OP\n"); }
"<="					{ printf("LE_OP\n"); }
">="					{ printf("GE_OP\n"); }
"=="					{ printf("EQ_OP\n"); }
"!="					{ printf("NE_OP\n"); }
";"					{ printf(";\n"); }
"{"     				{ printf("{\n"); }
"}"     				{ printf("}\n"); }
","					{ printf(",\n"); }
"="					{ printf("=\n"); }
"("					{ printf("(\n"); }
")"					{ printf(")\n"); }
"["     				{ printf("[\n"); }
"]"     				{ printf("]\n"); }
"."					{ printf(".\n"); }
"!"					{ printf("!\n"); }
"-"					{ printf("-\n"); }
"+"					{ printf("+\n"); }
"*"					{ printf("*\n"); }
"/"					{ printf("/\n"); }
"%"					{ printf("%\n"); }
"<"					{ printf("<\n"); }
">"					{ printf(">\n"); }

{WS}+					{ /* whitespace separates tokens */ }
.					{ printf("ERROR\n"); }

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
