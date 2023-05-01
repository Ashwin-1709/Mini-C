%{
#include <stdio.h>
#include <string.h>
extern int sym_type(const char *);  /* returns type from symbol table */

void error(char *msg) {
    printf("%s\n", msg);
    exit(0);
}

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
int line=1;
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
%s PF
%%
"/*"(.|\n|\s)*"*/"                                 { for(int i=0;i<strlen(yytext);i++){if(yytext[i]=='\n'){line++;}}
    /*comment();*/ }
"//".*                                    {line++; /* consume //-comment */ }
("\n")+                     {line+=strlen(yytext);}
"break"					{printf("%d\t%s\t%s\n",line,yytext,"BREAK");}
"case"					{printf("%d\t%s\t%s\n",line,yytext,"CASE"); }
"char"					{printf("%d\t%s\t%s\n",line,yytext,"CHAR"); }
"continue"				{printf("%d\t%s\t%s\n",line,yytext,"CONTINUE"); }
"default"				{printf("%d\t%s\t%s\n",line,yytext,"DEFAULT");  }
"else"					{printf("%d\t%s\t%s\n",line,yytext,"ELSE"); }
"float"					{printf("%d\t%s\t%s\n",line,yytext,"FLOAT");  }
"for"					{printf("%d\t%s\t%s\n",line,yytext,"FOR"); }
"if"					{printf("%d\t%s\t%s\n",line,yytext,"IF"); }
"int"					{printf("%d\t%s\t%s\n",line,yytext,"INT"); }
"return"				{printf("%d\t%s\t%s\n",line,yytext,"RETURN"); }
"switch"				{printf("%d\t%s\t%s\n",line,yytext,"SWITCH"); }
"void"					{printf("%d\t%s\t%s\n",line,yytext,"VOID"); }
"while"					{printf("%d\t%s\t%s\n",line,yytext,"WHILE"); }
"main"                  {printf("%d\t%s\t%s\n",line,yytext,"MAIN_FUNCTION");}
"printf"                {BEGIN PF;printf("%d\t%s\t%s\n",line,yytext,"PRINTF_TOKEN");}

<PF>"("(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	              {pfCount+=varCount(yytext);yytext[0]="";printf("%d\t%s\t%s\n",line,yytext,"STRING_LITERAL");  }
<PF>","{LETTER}{ALNUM}*	                                                {pfCount--;yytext[0]=" ";printf("%d\t%s\t%s\n",line,yytext,"IDENTIFIER");}
<PF>")"                                                                {if (pfCount==0){printf("Valid printf\n");} else {printf("Invalid printf\n");pfCount=0;} BEGIN 0;}
{LETTER}{ALNUM}*					                                    {printf("%d\t%s\t%s\n",line,yytext,"IDENTIFIER");}
 
("0"|{NONZERO}({DIGIT}*))				                                {printf("%d\t%s\t%s\n",line,yytext,"I_CONSTANT"); }
"'"[^\']"'"                                                             {printf("%d\t%s\t%s\n",line,yytext,"CHAR_CONST");}
 
{DIGIT}+{EXPONENT}{FLOAT_SUFFIX}?				                         {printf("%d\t%s\t%s\n",line,yytext,"F_CONSTANT");  }
{DIGIT}*"."{DIGIT}+{EXPONENT}?{FLOAT_SUFFIX}?			                  {printf("%d\t%s\t%s\n",line,yytext,"F_CONSTANT");  }
{DIGIT}+"."{EXPONENT}?{FLOAT_SUFFIX}?			                                {printf("%d\t%s\t%s\n",line,yytext,"F_CONSTANT");  }
 
(\"([^"\\\n]|{ESCAPE_SEQUENCE})*\"{WHITESPACE}*)+	                                {printf("%d\t%s\t%s\n",line,yytext,"STRING_LITERAL"); }
";\n"					{printf("%d\t%s\t%s\n",line,";","SEMICOLON"); line++; }
"{\n"  				{printf("%d\t%s\t%s\n",line,"{","LEFT_CURLY"); line++; }
"}\n"     				{printf("%d\t%s\t%s\n",line,"}","RIGHT_CURLY");line++;  }

"&&"					{printf("%d\t%s\t%s\n",line,yytext,"AND_OP");  }
"||"					{printf("%d\t%s\t%s\n",line,yytext,"OR_OP");  }
"<="					{printf("%d\t%s\t%s\n",line,yytext,"LE_OP");  }
">="					{printf("%d\t%s\t%s\n",line,yytext,"GE_OP");  }
"=="					{printf("%d\t%s\t%s\n",line,yytext,"EQ_OP");  }
"!="					{printf("%d\t%s\t%s\n",line,yytext,"NE_OP");  }
";"					{printf("%d\t%s\t%s\n",line,yytext,"SEMICOLON");  }
"{"  				{printf("%d\t%s\t%s\n",line,yytext,"LEFT_CURLY");  }
"}"     				{printf("%d\t%s\t%s\n",line,yytext,"RIGHT_CURLY");  }
","					{printf("%d\t%s\t%s\n",line,yytext,"COMMA");  }
":"					{printf("%d\t%s\t%s\n",line,yytext,"COLON");  }
"="					{printf("%d\t%s\t%s\n",line,yytext,"EQUAL_SIGN");  }
"("					{printf("%d\t%s\t%s\n",line,yytext,"LEFT_ROUND");  }
")"					{printf("%d\t%s\t%s\n",line,yytext,"RIGHT_ROUND");  }
"["     			{printf("%d\t%s\t%s\n",line,yytext,"LEFT_SQUARE");  }
"]"     			{printf("%d\t%s\t%s\n",line,yytext,"RIGHT_SQUARE"); }
"!"					{printf("%d\t%s\t%s\n",line,yytext,"EXALAMATION");  }
"-"					{printf("%d\t%s\t%s\n",line,yytext,"HYPHEN");  }
"+"					{printf("%d\t%s\t%s\n",line,yytext,"PLUS");  }
"*"					{printf("%d\t%s\t%s\n",line,yytext,"STAR");  }
"/"					{printf("%d\t%s\t%s\n",line,yytext,"SLASH");  }
"%"					{printf("%d\t%s\t%s\n",line,yytext,"PERCENT");  }
"<"					{printf("%d\t%s\t%s\n",line,yytext,"LT_OP");  }
">"					{printf("%d\t%s\t%s\n",line,yytext,"GT_OP");  }

{WHITESPACE}+					{ for(int i=0;i<strlen(yytext);i++){if(yytext[i]=='\n'){line++;}}}
.               			{ error("Error in lexical Analysis\n"); }
%%
int main(){
    yyin=fopen("/Users/mokshpapneja/Desktop/CC/Assignment2/Compiler-Construction-Assignment-2/lexical_analysis/test.c","r+");
    yylex();
}
int yywrap(void) {       /* called at end of input */ 
    return 1;           /* terminate now */
}
