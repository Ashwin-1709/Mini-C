/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BREAK = 258,                   /* BREAK  */
    CASE = 259,                    /* CASE  */
    CHAR = 260,                    /* CHAR  */
    CONTINUE = 261,                /* CONTINUE  */
    DEFAULT = 262,                 /* DEFAULT  */
    ELSE = 263,                    /* ELSE  */
    FLOAT = 264,                   /* FLOAT  */
    FOR = 265,                     /* FOR  */
    IF = 266,                      /* IF  */
    RETURN = 267,                  /* RETURN  */
    INT = 268,                     /* INT  */
    SWITCH = 269,                  /* SWITCH  */
    VOID = 270,                    /* VOID  */
    WHILE = 271,                   /* WHILE  */
    MAIN_FUNCTION = 272,           /* MAIN_FUNCTION  */
    IDENTIFIER = 273,              /* IDENTIFIER  */
    STRING_LITERAL = 274,          /* STRING_LITERAL  */
    I_CONSTANT = 275,              /* I_CONSTANT  */
    F_CONSTANT = 276,              /* F_CONSTANT  */
    AND_OP = 277,                  /* AND_OP  */
    OR_OP = 278,                   /* OR_OP  */
    LE_OP = 279,                   /* LE_OP  */
    GE_OP = 280,                   /* GE_OP  */
    EQ_OP = 281,                   /* EQ_OP  */
    NE_OP = 282,                   /* NE_OP  */
    EQUAL_SIGN = 283,              /* EQUAL_SIGN  */
    SEMICOLON = 284,               /* SEMICOLON  */
    LEFT_CURLY = 285,              /* LEFT_CURLY  */
    RIGHT_CURLY = 286,             /* RIGHT_CURLY  */
    COMMA = 287,                   /* COMMA  */
    COLON = 288,                   /* COLON  */
    LEFT_ROUND = 289,              /* LEFT_ROUND  */
    RIGHT_ROUND = 290,             /* RIGHT_ROUND  */
    LEFT_SQUARE = 291,             /* LEFT_SQUARE  */
    RIGHT_SQUARE = 292,            /* RIGHT_SQUARE  */
    DOT = 293,                     /* DOT  */
    AMPERSAND = 294,               /* AMPERSAND  */
    EXCLAMATION = 295,             /* EXCLAMATION  */
    HYPHEN = 296,                  /* HYPHEN  */
    PLUS = 297,                    /* PLUS  */
    STAR = 298,                    /* STAR  */
    SLASH = 299,                   /* SLASH  */
    LT_OP = 300,                   /* LT_OP  */
    GT_OP = 301,                   /* GT_OP  */
    PERCENT = 302,                 /* PERCENT  */
    PRINTF_TOKEN = 303,            /* PRINTF_TOKEN  */
    SCANF_TOKEN = 304              /* SCANF_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BREAK 258
#define CASE 259
#define CHAR 260
#define CONTINUE 261
#define DEFAULT 262
#define ELSE 263
#define FLOAT 264
#define FOR 265
#define IF 266
#define RETURN 267
#define INT 268
#define SWITCH 269
#define VOID 270
#define WHILE 271
#define MAIN_FUNCTION 272
#define IDENTIFIER 273
#define STRING_LITERAL 274
#define I_CONSTANT 275
#define F_CONSTANT 276
#define AND_OP 277
#define OR_OP 278
#define LE_OP 279
#define GE_OP 280
#define EQ_OP 281
#define NE_OP 282
#define EQUAL_SIGN 283
#define SEMICOLON 284
#define LEFT_CURLY 285
#define RIGHT_CURLY 286
#define COMMA 287
#define COLON 288
#define LEFT_ROUND 289
#define RIGHT_ROUND 290
#define LEFT_SQUARE 291
#define RIGHT_SQUARE 292
#define DOT 293
#define AMPERSAND 294
#define EXCLAMATION 295
#define HYPHEN 296
#define PLUS 297
#define STAR 298
#define SLASH 299
#define LT_OP 300
#define GT_OP 301
#define PERCENT 302
#define PRINTF_TOKEN 303
#define SCANF_TOKEN 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 6 "parser.y"

    int iconst;
    float dconst;

#line 170 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
