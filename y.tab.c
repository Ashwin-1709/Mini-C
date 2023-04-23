/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>

#line 76 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 232 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BREAK = 3,                      /* BREAK  */
  YYSYMBOL_CASE = 4,                       /* CASE  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_CONTINUE = 6,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 7,                    /* DEFAULT  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_SWITCH = 14,                    /* SWITCH  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_MAIN_FUNCTION = 17,             /* MAIN_FUNCTION  */
  YYSYMBOL_IDENTIFIER = 18,                /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 19,            /* STRING_LITERAL  */
  YYSYMBOL_I_CONSTANT = 20,                /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 21,                /* F_CONSTANT  */
  YYSYMBOL_AND_OP = 22,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 23,                     /* OR_OP  */
  YYSYMBOL_LE_OP = 24,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 25,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 26,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 27,                     /* NE_OP  */
  YYSYMBOL_EQUAL_SIGN = 28,                /* EQUAL_SIGN  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_LEFT_CURLY = 30,                /* LEFT_CURLY  */
  YYSYMBOL_RIGHT_CURLY = 31,               /* RIGHT_CURLY  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_COLON = 33,                     /* COLON  */
  YYSYMBOL_LEFT_ROUND = 34,                /* LEFT_ROUND  */
  YYSYMBOL_RIGHT_ROUND = 35,               /* RIGHT_ROUND  */
  YYSYMBOL_LEFT_SQUARE = 36,               /* LEFT_SQUARE  */
  YYSYMBOL_RIGHT_SQUARE = 37,              /* RIGHT_SQUARE  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_AMPERSAND = 39,                 /* AMPERSAND  */
  YYSYMBOL_EXCLAMATION = 40,               /* EXCLAMATION  */
  YYSYMBOL_HYPHEN = 41,                    /* HYPHEN  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_STAR = 43,                      /* STAR  */
  YYSYMBOL_SLASH = 44,                     /* SLASH  */
  YYSYMBOL_LT_OP = 45,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 46,                     /* GT_OP  */
  YYSYMBOL_PERCENT = 47,                   /* PERCENT  */
  YYSYMBOL_PRINTF_TOKEN = 48,              /* PRINTF_TOKEN  */
  YYSYMBOL_SCANF_TOKEN = 49,               /* SCANF_TOKEN  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_s = 51,                         /* s  */
  YYSYMBOL_functional_declaration = 52,    /* functional_declaration  */
  YYSYMBOL_var_type = 53,                  /* var_type  */
  YYSYMBOL_func_type = 54,                 /* func_type  */
  YYSYMBOL_func_declarator = 55,           /* func_declarator  */
  YYSYMBOL_param_list = 56,                /* param_list  */
  YYSYMBOL_declare_var = 57,               /* declare_var  */
  YYSYMBOL_main_func = 58,                 /* main_func  */
  YYSYMBOL_compound_statement = 59,        /* compound_statement  */
  YYSYMBOL_statement_list = 60,            /* statement_list  */
  YYSYMBOL_single_statement = 61,          /* single_statement  */
  YYSYMBOL_jump_statement = 62,            /* jump_statement  */
  YYSYMBOL_return_statement = 63,          /* return_statement  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_expression_statement = 65,      /* expression_statement  */
  YYSYMBOL_unary_expr = 66,                /* unary_expr  */
  YYSYMBOL_functional_call = 67,           /* functional_call  */
  YYSYMBOL_arg_list = 68,                  /* arg_list  */
  YYSYMBOL_arg = 69,                       /* arg  */
  YYSYMBOL_arr_element = 70,               /* arr_element  */
  YYSYMBOL_assignment_statement = 71,      /* assignment_statement  */
  YYSYMBOL_switch_statment = 72,           /* switch_statment  */
  YYSYMBOL_case_list_def = 73,             /* case_list_def  */
  YYSYMBOL_case_list = 74,                 /* case_list  */
  YYSYMBOL_case = 75,                      /* case  */
  YYSYMBOL_default_stmt = 76,              /* default_stmt  */
  YYSYMBOL_if_statement = 77,              /* if_statement  */
  YYSYMBOL_else_clause = 78,               /* else_clause  */
  YYSYMBOL_for_loop_assignment = 79,       /* for_loop_assignment  */
  YYSYMBOL_for_loop_declaration = 80,      /* for_loop_declaration  */
  YYSYMBOL_for_statement = 81,             /* for_statement  */
  YYSYMBOL_declaration = 82,               /* declaration  */
  YYSYMBOL_init_declarator_list = 83,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 84,           /* init_declarator  */
  YYSYMBOL_declarator_var = 85,            /* declarator_var  */
  YYSYMBOL_declarator_arr = 86,            /* declarator_arr  */
  YYSYMBOL_while_statement = 87,           /* while_statement  */
  YYSYMBOL_print_statement = 88,           /* print_statement  */
  YYSYMBOL_print_params = 89,              /* print_params  */
  YYSYMBOL_scanf_statement = 90,           /* scanf_statement  */
  YYSYMBOL_addr_list = 91,                 /* addr_list  */
  YYSYMBOL_addr = 92                       /* addr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    30,    30,    30,    33,    36,    36,    36,    39,    39,
      42,    42,    45,    45,    48,    52,    53,    54,    57,    58,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    77,    78,    81,    84,    85,    86,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   106,   106,   106,
     106,   109,   110,   113,   114,   116,   116,   118,   118,   118,
     118,   120,   121,   125,   126,   130,   132,   133,   134,   136,
     136,   138,   139,   141,   142,   146,   148,   149,   152,   153,
     154,   156,   157,   159,   163,   165,   165,   167,   168,   169,
     171,   173,   174,   177,   181,   182,   184,   184,   186,   188,
     188,   190
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BREAK", "CASE",
  "CHAR", "CONTINUE", "DEFAULT", "ELSE", "FLOAT", "FOR", "IF", "RETURN",
  "INT", "SWITCH", "VOID", "WHILE", "MAIN_FUNCTION", "IDENTIFIER",
  "STRING_LITERAL", "I_CONSTANT", "F_CONSTANT", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "EQUAL_SIGN", "SEMICOLON", "LEFT_CURLY",
  "RIGHT_CURLY", "COMMA", "COLON", "LEFT_ROUND", "RIGHT_ROUND",
  "LEFT_SQUARE", "RIGHT_SQUARE", "DOT", "AMPERSAND", "EXCLAMATION",
  "HYPHEN", "PLUS", "STAR", "SLASH", "LT_OP", "GT_OP", "PERCENT",
  "PRINTF_TOKEN", "SCANF_TOKEN", "$accept", "s", "functional_declaration",
  "var_type", "func_type", "func_declarator", "param_list", "declare_var",
  "main_func", "compound_statement", "statement_list", "single_statement",
  "jump_statement", "return_statement", "expr", "expression_statement",
  "unary_expr", "functional_call", "arg_list", "arg", "arr_element",
  "assignment_statement", "switch_statment", "case_list_def", "case_list",
  "case", "default_stmt", "if_statement", "else_clause",
  "for_loop_assignment", "for_loop_declaration", "for_statement",
  "declaration", "init_declarator_list", "init_declarator",
  "declarator_var", "declarator_arr", "while_statement", "print_statement",
  "print_params", "scanf_statement", "addr_list", "addr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     130,  -145,  -145,   -11,    -2,   -17,    23,   130,  -145,    14,
    -145,     7,    16,    17,  -145,  -145,    25,    21,    34,    49,
      21,     5,    93,  -145,    21,    21,  -145,  -145,  -145,    70,
      73,    63,    72,    81,    85,    86,    97,    87,    91,    57,
    -145,  -145,  -145,  -145,  -145,   153,   153,   153,    96,   102,
     126,  -145,   117,   149,  -145,  -145,   119,   177,  -145,  -145,
     125,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,    66,  -145,  -145,    65,   153,   119,   153,
     153,   153,    62,   144,   190,  -145,    29,   147,   156,   140,
      60,  -145,   152,  -145,  -145,  -145,    97,   153,   153,   153,
     153,   153,   153,  -145,   153,   153,   153,   153,   153,   153,
     153,   153,  -145,  -145,    97,  -145,   216,   242,   268,   334,
    -145,  -145,  -145,  -145,  -145,   146,   145,   148,  -145,    -1,
     150,   153,  -145,   126,   153,   100,   203,     2,   255,   255,
     229,   229,    29,    29,  -145,  -145,   255,   255,  -145,   334,
     -13,   149,   154,   149,  -145,   189,   155,   168,   159,   157,
     294,  -145,   334,  -145,    -6,   125,   160,   170,   187,   207,
    -145,  -145,   206,   220,   221,  -145,   237,   243,   247,   244,
     263,   149,   149,  -145,   153,   251,   142,  -145,   264,   168,
     271,  -145,   275,   157,   153,  -145,  -145,  -145,   301,  -145,
     272,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   327,   149,
     149,  -145,  -145,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     6,     7,     5,     9,     0,     0,     0,     8,     0,
       2,     0,     0,     0,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,    15,     5,    10,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    60,
      58,    56,    57,    36,    18,     0,     0,     0,     0,     0,
       0,    32,     0,    20,    30,    28,    23,     0,    52,    54,
      59,    53,    22,    24,    27,    31,    29,    25,    26,    16,
      17,    14,    11,     0,    33,    34,     0,     0,    35,     0,
       0,     0,     0,     0,     0,    61,    62,     0,     0,   100,
       0,    96,    98,    99,    19,    21,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    92,     0,    91,     0,     0,     0,    73,
      69,    70,    68,    67,    63,     0,    65,     0,    55,     0,
       0,     0,    94,     0,     0,     0,    40,    39,    44,    43,
      50,    51,    46,    45,    47,    48,    42,    41,    49,    74,
      90,     0,     0,     0,    64,     0,    71,     0,     0,     0,
       0,    95,    97,    38,     0,     0,    88,     0,    87,    78,
     103,    66,     0,   106,     0,   104,     0,     0,   109,   101,
      90,     0,     0,    85,     0,     0,    76,    79,     0,     0,
       0,   111,     0,     0,     0,    89,    93,    86,     0,    75,
       0,    80,    77,    72,   107,   105,   108,   110,     0,    82,
      84,   102,    81,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,   299,  -145,     4,  -145,  -145,   234,  -145,  -145,    -4,
     -53,  -144,  -145,  -145,   -28,   -44,  -145,  -145,   167,  -145,
    -141,  -138,  -145,  -145,  -145,   122,  -145,  -145,  -145,   175,
    -145,  -145,   253,  -145,   197,  -145,  -145,  -145,  -145,   143,
    -145,   169,  -145
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,    50,     9,    17,    30,    31,    10,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   125,   126,
      60,    61,    62,   185,   186,   187,   202,    63,   183,   167,
     114,    64,    65,    90,    91,    92,    93,    66,    67,   174,
      68,   177,   178
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      95,    84,    85,    86,     8,   164,    11,   168,    78,   165,
       1,     8,   166,    23,     2,    12,    26,    13,    27,    96,
      69,    70,    81,    14,    97,    29,    99,   100,   101,   102,
      83,   157,    16,   116,   158,   117,   118,   119,   197,   165,
      28,    18,   166,   104,   105,   106,   107,   108,   109,   110,
      19,    22,    20,   136,   137,   138,   139,   140,   141,    21,
     142,   143,   144,   145,   146,   147,   148,   149,   135,    24,
       1,     1,   106,   107,     2,     2,   110,    29,    27,    27,
     120,   121,   122,   123,    25,    81,   150,   160,    71,   132,
     162,    82,   133,    83,   113,    73,    32,   124,     1,    33,
     170,    74,     2,    34,    35,    36,    27,    37,    72,    38,
      75,    39,    40,    41,    42,    39,    40,    41,    42,    76,
      77,    79,    43,    22,    44,    80,    43,    45,   196,   163,
      87,    45,    96,    46,    47,     1,    88,    46,    47,     2,
     198,    48,    49,     3,    89,     4,   184,     5,    94,   200,
     208,    96,    32,   111,     1,    33,   212,   213,     2,    34,
      35,    36,    27,    37,   127,    38,   129,    39,    40,    41,
      42,    39,    40,    41,    42,   130,   131,   155,    43,    22,
     134,   154,   159,    45,   169,   156,   173,    45,   175,    46,
      47,   172,   180,    46,    47,   182,   176,    48,    49,    97,
      98,    99,   100,   101,   102,   181,   103,   120,   121,   122,
     123,   184,    97,    98,    99,   100,   101,   102,   104,   105,
     106,   107,   108,   109,   110,   128,   188,    99,   100,   101,
     102,   104,   105,   106,   107,   108,   109,   110,    97,    98,
      99,   100,   101,   102,   104,   105,   106,   107,   108,   109,
     110,   151,   189,    99,   100,   191,   190,   104,   105,   106,
     107,   108,   109,   110,    97,    98,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   152,   192,   193,
     194,   164,   199,   104,   105,   106,   107,   108,   109,   110,
      97,    98,    99,   100,   101,   102,   104,   105,   106,   107,
     205,   203,   110,   153,   206,   210,    15,   112,   201,   104,
     105,   106,   107,   108,   109,   110,    97,    98,    99,   100,
     101,   102,   171,    97,    98,    99,   100,   101,   102,   115,
     161,   179,   204,     0,   209,   104,   105,   106,   107,   108,
     109,   110,   104,   105,   106,   107,   108,   109,   110,    97,
      98,    99,   100,   101,   102,   195,    97,    98,    99,   100,
     101,   102,   207,     0,   211,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   104,   105,   106,   107,   108,
     109,   110
};

static const yytype_int16 yycheck[] =
{
      53,    45,    46,    47,     0,    18,    17,   151,    36,   150,
       5,     7,   150,    17,     9,    17,    20,    34,    13,    32,
      24,    25,    28,     0,    22,    21,    24,    25,    26,    27,
      36,    32,    18,    77,    35,    79,    80,    81,   182,   180,
      35,    34,   180,    41,    42,    43,    44,    45,    46,    47,
      34,    30,    35,    97,    98,    99,   100,   101,   102,    34,
     104,   105,   106,   107,   108,   109,   110,   111,    96,    35,
       5,     5,    43,    44,     9,     9,    47,    73,    13,    13,
      18,    19,    20,    21,    35,    28,   114,   131,    18,    29,
     134,    34,    32,    36,    29,    32,     3,    35,     5,     6,
     153,    29,     9,    10,    11,    12,    13,    14,    35,    16,
      29,    18,    19,    20,    21,    18,    19,    20,    21,    34,
      34,    34,    29,    30,    31,    34,    29,    34,   181,    29,
      34,    34,    32,    40,    41,     5,    34,    40,    41,     9,
     184,    48,    49,    13,    18,    15,     4,    17,    31,     7,
     194,    32,     3,    28,     5,     6,   209,   210,     9,    10,
      11,    12,    13,    14,    20,    16,    19,    18,    19,    20,
      21,    18,    19,    20,    21,    19,    36,    32,    29,    30,
      28,    35,    32,    34,    30,    37,    18,    34,    29,    40,
      41,    36,    32,    40,    41,     8,    39,    48,    49,    22,
      23,    24,    25,    26,    27,    35,    29,    18,    19,    20,
      21,     4,    22,    23,    24,    25,    26,    27,    41,    42,
      43,    44,    45,    46,    47,    35,    20,    24,    25,    26,
      27,    41,    42,    43,    44,    45,    46,    47,    22,    23,
      24,    25,    26,    27,    41,    42,    43,    44,    45,    46,
      47,    35,    32,    24,    25,    18,    35,    41,    42,    43,
      44,    45,    46,    47,    22,    23,    24,    25,    26,    27,
      41,    42,    43,    44,    45,    46,    47,    35,    35,    32,
      36,    18,    31,    41,    42,    43,    44,    45,    46,    47,
      22,    23,    24,    25,    26,    27,    41,    42,    43,    44,
      29,    37,    47,    35,    29,    33,     7,    73,   186,    41,
      42,    43,    44,    45,    46,    47,    22,    23,    24,    25,
      26,    27,   155,    22,    23,    24,    25,    26,    27,    76,
     133,    37,   189,    -1,    33,    41,    42,    43,    44,    45,
      46,    47,    41,    42,    43,    44,    45,    46,    47,    22,
      23,    24,    25,    26,    27,   180,    22,    23,    24,    25,
      26,    27,   193,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    41,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     9,    13,    15,    17,    51,    52,    53,    54,
      58,    17,    17,    34,     0,    51,    18,    55,    34,    34,
      35,    34,    30,    59,    35,    35,    59,    13,    35,    53,
      56,    57,     3,     6,    10,    11,    12,    14,    16,    18,
      19,    20,    21,    29,    31,    34,    40,    41,    48,    49,
      53,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      70,    71,    72,    77,    81,    82,    87,    88,    90,    59,
      59,    18,    35,    32,    29,    29,    34,    34,    64,    34,
      34,    28,    34,    36,    65,    65,    65,    34,    34,    18,
      83,    84,    85,    86,    31,    60,    32,    22,    23,    24,
      25,    26,    27,    29,    41,    42,    43,    44,    45,    46,
      47,    28,    56,    29,    80,    82,    65,    65,    65,    65,
      18,    19,    20,    21,    35,    68,    69,    20,    35,    19,
      19,    36,    29,    32,    28,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      64,    35,    35,    35,    35,    32,    37,    32,    35,    32,
      65,    84,    65,    29,    18,    70,    71,    79,    61,    30,
      60,    68,    36,    18,    89,    29,    39,    91,    92,    37,
      32,    35,     8,    78,     4,    73,    74,    75,    20,    32,
      35,    18,    35,    32,    36,    79,    60,    61,    65,    31,
       7,    75,    76,    37,    89,    29,    29,    91,    65,    33,
      33,    37,    60,    60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    52,    53,    53,    53,    54,    54,
      55,    55,    56,    56,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    78,    79,    79,
      79,    80,    80,    81,    82,    83,    83,    84,    84,    84,
      85,    86,    86,    87,    88,    88,    89,    89,    90,    91,
      91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     2,     4,     5,     5,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     1,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     2,     3,     4,     1,     3,     1,     1,     1,
       1,     4,     7,     3,     3,     7,     1,     2,     0,     1,
       2,     4,     3,     3,     2,     6,     2,     0,     1,     3,
       0,     1,     1,     7,     3,     3,     1,     3,     1,     1,
       1,     4,     7,     5,     5,     7,     1,     3,     7,     1,
       3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 37: /* expr: expression_statement SEMICOLON  */
#line 85 "parser.y"
                                          {printf("---parsed expression----\n");}
#line 1491 "y.tab.c"
    break;

  case 39: /* expression_statement: expression_statement OR_OP expression_statement  */
#line 89 "parser.y"
                                                                       {printf("expr || expr parsed\n");}
#line 1497 "y.tab.c"
    break;

  case 40: /* expression_statement: expression_statement AND_OP expression_statement  */
#line 90 "parser.y"
                                                                                        {printf("expr && expr parsed\n");}
#line 1503 "y.tab.c"
    break;

  case 41: /* expression_statement: expression_statement GT_OP expression_statement  */
#line 91 "parser.y"
                                                                                        {printf("expr > expr parsed\n");}
#line 1509 "y.tab.c"
    break;

  case 42: /* expression_statement: expression_statement LT_OP expression_statement  */
#line 92 "parser.y"
                                                                                   {printf("expr < expr parsed\n");}
#line 1515 "y.tab.c"
    break;

  case 43: /* expression_statement: expression_statement GE_OP expression_statement  */
#line 93 "parser.y"
                                                                                       {printf("expr >= expr parsed\n");}
#line 1521 "y.tab.c"
    break;

  case 44: /* expression_statement: expression_statement LE_OP expression_statement  */
#line 94 "parser.y"
                                                                                       {printf("expr <= expr parsed\n");}
#line 1527 "y.tab.c"
    break;

  case 45: /* expression_statement: expression_statement PLUS expression_statement  */
#line 95 "parser.y"
                                                                                      {printf("expr + expr parsed\n");}
#line 1533 "y.tab.c"
    break;

  case 46: /* expression_statement: expression_statement HYPHEN expression_statement  */
#line 96 "parser.y"
                                                                                        {printf("expr - expr parsed\n");}
#line 1539 "y.tab.c"
    break;

  case 47: /* expression_statement: expression_statement STAR expression_statement  */
#line 97 "parser.y"
                                                                                      {printf("expr * expr parsed\n");}
#line 1545 "y.tab.c"
    break;

  case 48: /* expression_statement: expression_statement SLASH expression_statement  */
#line 98 "parser.y"
                                                                                       {printf("expr / expr parsed\n");}
#line 1551 "y.tab.c"
    break;

  case 49: /* expression_statement: expression_statement PERCENT expression_statement  */
#line 99 "parser.y"
                                                                                         {printf("expr mod expr parsed\n");}
#line 1557 "y.tab.c"
    break;

  case 50: /* expression_statement: expression_statement EQ_OP expression_statement  */
#line 100 "parser.y"
                                                                       {printf("expr == expr parsed\n");}
#line 1563 "y.tab.c"
    break;

  case 51: /* expression_statement: expression_statement NE_OP expression_statement  */
#line 101 "parser.y"
                                                                       {printf("expr != expr parsed\n");}
#line 1569 "y.tab.c"
    break;

  case 52: /* expression_statement: unary_expr  */
#line 102 "parser.y"
                                                  {printf("unary parsed\n");}
#line 1575 "y.tab.c"
    break;

  case 61: /* unary_expr: EXCLAMATION expression_statement  */
#line 109 "parser.y"
                                                                {printf("!(expr) parsed\n");}
#line 1581 "y.tab.c"
    break;

  case 62: /* unary_expr: HYPHEN expression_statement  */
#line 110 "parser.y"
                                                       {printf("-(expr) parsed\n");}
#line 1587 "y.tab.c"
    break;


#line 1591 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 192 "parser.y"


int main() {
    yyparse();
    printf("Lexical Analysis done......\n");
    printf("Syntax Analysis done......\nProgram is Syntactically correct\n");
    printf("Initiating simulation and semantic analysis.........\n");
}

int yyerror() {
    printf("Syntax error\n");
    exit(0);
}
