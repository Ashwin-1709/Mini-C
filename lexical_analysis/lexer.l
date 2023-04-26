%{
    // #include "y.tab.h"    
    #include <string.h>
    int lNum=1;
    int varCount(char * text){
        int l=strlen(text);
        int res=0;
        for(int i=0;i<l-1;i++){
            if(text[i]=='%'){
                if(text[i+1]=='d' || text[i+1]=='c'||text[i+1]=='f'){
                    res++;
 
                }
            }
        }
        return res;
    }
    int pfCount=0;
%}
 
DIGIT           [0-9]
NONZERO         [1-9]
LETTER          [a-zA-Z_]
ALNUM           [a-zA-Z_0-9]
EXPONENT        ([Ee][+-]?{DIGIT}+)
FLOAT_SUFFIX    (f|F|l|L)
ESCAPE_SEQUENCE (\\(['"\?\\abfnrtv]))
WHITESPACE      [ \t\v\n\f]
 
%x PF
%%
"/*"(.|\n|\s)*"*/"                                 {for(int i =0;i<strlen(yytext);i++){if(yytext[i]=='\n'){lNum++;}}/*comment();*/ }
"//".*                                    { /* consume //-comment */ }
 
"break"					{printf("%d\t%s\t%s\n",lNum,yytext,"BREAK");}
"case"					{printf("%d\t%s\t%s\n",lNum,yytext,"CASE"); }
"char"					{printf("%d\t%s\t%s\n",lNum,yytext,"CHAR"); }
"continue"				{printf("%d\t%s\t%s\n",lNum,yytext,"CONTINUE"); }
"default"				{printf("%d\t%s\t%s\n",lNum,yytext,"DEFAULT");  }
"else"					{printf("%d\t%s\t%s\n",lNum,yytext,"ELSE"); }
"float"					{printf("%d\t%s\t%s\n",lNum,yytext,"FLOAT");  }
"for"					{printf("%d\t%s\t%s\n",lNum,yytext,"FOR"); }
"if"					{printf("%d\t%s\t%s\n",lNum,yytext,"IF"); }
"int"					{printf("%d\t%s\t%s\n",lNum,yytext,"INT"); }
"return"				{printf("%d\t%s\t%s\n",lNum,yytext,"RETURN"); }
"switch"				{printf("%d\t%s\t%s\n",lNum,yytext,"SWITCH"); }
"void"					{printf("%d\t%s\t%s\n",lNum,yytext,"VOID"); }
"while"					{printf("%d\t%s\t%s\n",lNum,yytext,"WHILE"); }
"main"                  {printf("%d\t%s\t%s\n",lNum,yytext,"MAIN_FUNCTION");}
"printf"                {BEGIN PF;printf("%d\t%s\t%s\n",lNum,yytext,"PRINTF_TOKEN");}
<PF>"("(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	{pfCount+=varCount(yytext);yytext[0]="";printf("%d\t%s\t%s\n",lNum,yytext,"STRING_LITERAL");  }
<PF>","{LETTER}{ALNUM}*	{pfCount--;yytext[0]="";printf("%d\t%s\t%s\n",lNum,yytext,"IDENTIFIER");}
<PF>")"                   {if (pfCount==0){printf("Valid printf\n");} else {printf("Invalid printf\n");pfCount=0;} BEGIN 0;}
{LETTER}{ALNUM}*					{printf("%d\t%s\t%s\n",lNum,yytext,"IDENTIFIER");}
 
("0"|{NONZERO}({DIGIT}*))				{printf("%d\t%s\t%s\n",lNum,yytext,"I_CONSTANT"); }
"'"([^'\\\n]|{ESCAPE_SEQUENCE})+"'"		{printf("%d\t%s\t%s\n",lNum,yytext,"I_CONSTANT"); }
 
{DIGIT}+{EXPONENT}{FLOAT_SUFFIX}?				{printf("%d\t%s\t%s\n",lNum,yytext,"F_CONSTANT");  }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOAT_SUFFIX}?			{printf("%d\t%s\t%s\n",lNum,yytext,"F_CONSTANT");  }
{DIGIT}+"."{EXPONENT}?{FLOAT_SUFFIX}?			{printf("%d\t%s\t%s\n",lNum,yytext,"F_CONSTANT");  }
 
(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	{printf("%d\t%s\t%s\n",lNum,yytext,"STRING_LITERAL"); }
 
"&&"					{printf("%d\t%s\t%s\n",lNum,yytext,"AND_OP");  }
"||"					{printf("%d\t%s\t%s\n",lNum,yytext,"OR_OP");  }
"<="					{printf("%d\t%s\t%s\n",lNum,yytext,"LE_OP");  }
">="					{printf("%d\t%s\t%s\n",lNum,yytext,"GE_OP");  }
"=="					{printf("%d\t%s\t%s\n",lNum,yytext,"EQ_OP");  }
"!="					{printf("%d\t%s\t%s\n",lNum,yytext,"NE_OP");  }
";"					{printf("%d\t%s\t%s\n",lNum,yytext,"SEMICOLON");  }
"{"     				{printf("%d\t%s\t%s\n",lNum,yytext,"LEFT_CURLY");  }
"}"     				{printf("%d\t%s\t%s\n",lNum,yytext,"RIGHT_CURLY");  }
","					{printf("%d\t%s\t%s\n",lNum,yytext,"COMMA");  }
":"					{printf("%d\t%s\t%s\n",lNum,yytext,"COLON");  }
"="					{printf("%d\t%s\t%s\n",lNum,yytext,"EQUAL_SIGN");  }
"("					{printf("%d\t%s\t%s\n",lNum,yytext,"LEFT_ROUND");  }
")"					{printf("%d\t%s\t%s\n",lNum,yytext,"RIGHT_ROUND");  }
"["     			{printf("%d\t%s\t%s\n",lNum,yytext,"LEFT_SQUARE");  }
"]"     			{printf("%d\t%s\t%s\n",lNum,yytext,"RIGHT_SQUARE"); }
"!"					{printf("%d\t%s\t%s\n",lNum,yytext,"EXALAMATION");  }
"-"					{printf("%d\t%s\t%s\n",lNum,yytext,"HYPHEN");  }
"+"					{printf("%d\t%s\t%s\n",lNum,yytext,"PLUS");  }
"*"					{printf("%d\t%s\t%s\n",lNum,yytext,"STAR");  }
"/"					{printf("%d\t%s\t%s\n",lNum,yytext,"SLASH");  }
"%"					{printf("%d\t%s\t%s\n",lNum,yytext,"PERCENT");  }
"<"					{printf("%d\t%s\t%s\n",lNum,yytext,"LT_OP");  }
">"					{printf("%d\t%s\t%s\n",lNum,yytext,"GT_OP");  }
"\n"                     {lNum++;}
{WHITESPACE}+					{ /* whitespace separates tokens */ }
.					{ printf("Error in lexical Analysis\n"); }
 
%%
int main(){
    yylex();
 }
int yywrap(void) {       /* called at end of input */ 
    return 1;           /* terminate now */
}
