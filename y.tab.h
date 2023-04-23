/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CASE = 259,
    CHAR = 260,
    CONTINUE = 261,
    DEFAULT = 262,
    ELSE = 263,
    FLOAT = 264,
    FOR = 265,
    IF = 266,
    RETURN = 267,
    INT = 268,
    SWITCH = 269,
    VOID = 270,
    WHILE = 271,
    MAIN_FUNCTION = 272,
    IDENTIFIER = 273,
    I_CONSTANT = 274,
    F_CONSTANT = 275,
    STRING_LITERAL = 276,
    AND_OP = 277,
    OR_OP = 278,
    LE_OP = 279,
    GE_OP = 280,
    EQ_OP = 281,
    NE_OP = 282,
    EQUAL_SIGN = 283,
    SEMICOLON = 284,
    LEFT_CURLY = 285,
    RIGHT_CURLY = 286,
    COMMA = 287,
    COLON = 288,
    LEFT_ROUND = 289,
    RIGHT_ROUND = 290,
    LEFT_SQUARE = 291,
    RIGHT_SQUARE = 292,
    DOT = 293,
    AMPERSAND = 294,
    EXCLAMATION = 295,
    HYPHEN = 296,
    PLUS = 297,
    STAR = 298,
    SLASH = 299,
    LT_OP = 300,
    GT_OP = 301,
    PERCENT = 302,
    PRINTF_TOKEN = 303,
    SCANF_TOKEN = 304
  };
#endif
/* Tokens.  */
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
#define I_CONSTANT 274
#define F_CONSTANT 275
#define STRING_LITERAL 276
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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
