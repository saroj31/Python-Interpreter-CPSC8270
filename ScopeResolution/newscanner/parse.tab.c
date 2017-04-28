/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parse.y" /* yacc.c:339  */

  #include <iostream>
  #include "ast.h"
  #include <math.h>
  
	int yylex (void);
	extern int yylineno;
	extern char *yytext;
	void yyerror (char const *);

#line 77 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    MINUS = 309,
    NAME = 310,
    NEWLINE = 311,
    NOT = 312,
    NOTEQUAL = 313,
    NUMBER = 314,
    OR = 315,
    PASS = 316,
    PERCENT = 317,
    PERCENTEQUAL = 318,
    PLUS = 319,
    PLUSEQUAL = 320,
    PRINT = 321,
    RAISE = 322,
    RBRACE = 323,
    RETURN = 324,
    RIGHTSHIFT = 325,
    RIGHTSHIFTEQUAL = 326,
    RPAR = 327,
    RSQB = 328,
    SEMI = 329,
    SLASH = 330,
    SLASHEQUAL = 331,
    STAR = 332,
    STAREQUAL = 333,
    STRING = 334,
    TILDE = 335,
    TRY = 336,
    VBAREQUAL = 337,
    WHILE = 338,
    WITH = 339,
    YIELD = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parse.y" /* yacc.c:355  */

  Ast* ast;
  double d;
  //int i;

#line 209 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 226 "parse.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  139
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  323
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    42,    42,    43,    44,    53,    54,    57,    60,    61,
      64,    65,    68,    69,    72,    73,    76,    77,    80,    81,
      84,    87,    88,    91,    92,    95,    96,    99,   100,   103,
     104,   107,   108,   111,   112,   115,   118,   119,   122,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     140,   141,   144,   145,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   162,   164,   167,   168,
     171,   172,   175,   178,   181,   182,   183,   184,   185,   188,
     191,   194,   195,   198,   201,   202,   205,   206,   209,   210,
     213,   214,   217,   220,   221,   224,   225,   228,   229,   232,
     233,   234,   237,   238,   241,   242,   245,   248,   249,   252,
     253,   256,   257,   260,   261,   264,   265,   268,   269,   270,
     271,   272,   273,   274,   275,   278,   279,   282,   283,   286,
     287,   290,   291,   294,   295,   298,   299,   302,   303,   306,
     307,   310,   313,   314,   317,   318,   321,   322,   325,   326,
     329,   330,   334,   335,   338,   339,   342,   343,   346,   347,
     350,   351,   360,   361,   364,   365,   368,   369,   372,   373,
     376,   377,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   398,   399,   402,   403,   406,
     407,   410,   411,   414,   415,   418,   419,   429,   430,   433,
     434,   476,   477,   478,   479,   482,   489,   492,   493,   494,
     497,   501,   504,   505,   508,   509,   510,   511,   512,   513,
     514,   517,   518,   521,   522,   525,   526,   529,   530,   533,
     534,   537,   538,   541,   542,   545,   546,   549,   550,   551,
     554,   557,   558,   559,   562,   563,   566,   567,   570,   571,
     574,   578,   581,   582,   585,   586,   589,   590,   593,   594,
     597,   598,   601,   602,   603,   604,   605,   606,   609,   610,
     613,   614,   617,   618,   621,   622,   625,   626,   629,   630,
     634,   635,   638,   639,   642,   643,   646,   650,   651,   654,
     655,   656,   659,   660,   661,   664,   665,   666,   669,   670,
     671,   674,   675,   676,   679,   680,   681,   685,   686,   687,
     690,   691,   692,   695,   696,   697,   700,   703,   706,   707,
     708,   711,   712,   713
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "MINUS", "NAME", "NEWLINE", "NOT", "NOTEQUAL",
  "NUMBER", "OR", "PASS", "PERCENT", "PERCENTEQUAL", "PLUS", "PLUSEQUAL",
  "PRINT", "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL",
  "RPAR", "RSQB", "SEMI", "SLASH", "SLASHEQUAL", "STAR", "STAREQUAL",
  "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD",
  "$accept", "start", "single_input", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "fpdef", "fplist", "stmt", "simple_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "augassign", "print_stmt",
  "opt_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "star_DOT", "plus_DOT", "pick_STAR_import",
  "import_as_name", "dotted_as_name", "import_as_names", "dotted_as_names",
  "dotted_name", "global_stmt", "exec_stmt", "assert_stmt",
  "compound_stmt", "if_stmt", "star_ELIF", "while_stmt", "for_stmt",
  "try_stmt", "plus_except", "opt_ELSE", "opt_FINALLY", "with_stmt",
  "star_COMMA_with_item", "with_item", "except_clause", "pick_AS_COMMA",
  "opt_AS_COMMA", "suite", "plus_stmt", "testlist_safe", "old_test",
  "old_lambdef", "test", "opt_IF_ELSE", "or_test", "and_test", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "subscript", "opt_test_only",
  "opt_sliceop", "sliceop", "exprlist", "testlist", "dictorsetmaker",
  "pick_comp_for", "pick_for_test", "classdef", "opt_testlist", "arglist",
  "argument", "opt_comp_for", "list_iter", "list_for", "list_if",
  "comp_iter", "comp_for", "comp_if", "testlist1", "encoding_decl",
  "yield_expr", "star_fpdef_notest", "star_COMMA_expr", "star_COMMA_fpdef",
  "star_COMMA_test", "star_test_COLON_test", "star_COMMA_subscript",
  "star_COMMA_import_as_name", "plus_COMMA_test", "plus_COMMA_old_test",
  "dictarg", "listarg", "arglist_postlist", "small_stmt_STAR_OR_SEMI", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -376

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-376)))

#define YYTABLE_NINF -306

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     401,   779,    -2,   779,  -376,     8,  -376,    95,   823,   823,
     823,    24,    98,   779,    -2,    19,   779,    78,   779,  -376,
     100,   152,   347,  -376,  -376,  -376,   608,   779,   779,    81,
    -376,   146,   779,   779,   779,   164,  -376,  -376,   480,   137,
     159,    35,  -376,  -376,   169,  -376,    99,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
     155,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,   156,
       0,   170,  -376,   285,   166,   162,   173,    18,    47,    20,
    -376,   823,  -376,    64,  -376,  -376,    43,  -376,  -376,  -376,
    -376,   163,  -376,    38,  -376,    41,    28,   129,    89,  -376,
      48,   143,    26,    -2,   145,  -376,   172,  -376,   174,   130,
     779,    52,  -376,   178,     9,   158,   128,   121,  -376,    76,
    -376,   124,  -376,  -376,    97,   127,  -376,  -376,   779,  -376,
     156,   181,  -376,  -376,   638,   183,   186,   198,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,   689,   151,   153,
     779,  -376,   347,   347,  -376,   347,  -376,  -376,  -376,  -376,
    -376,   154,  -376,  -376,   177,  -376,   823,   823,   823,   823,
    -376,  -376,   823,  -376,  -376,   823,  -376,  -376,  -376,  -376,
     823,  -376,   157,   231,   730,   191,    64,  -376,  -376,  -376,
    -376,    78,  -376,  -376,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,    78,   779,   165,   231,  -376,  -376,   779,   638,   779,
      -3,   206,   823,  -376,   779,   779,  -376,  -376,    57,    71,
     638,    -2,   167,  -376,   207,   160,   779,   171,   175,  -376,
     779,   212,   779,   823,  -376,  -376,  -376,  -376,  -376,  -376,
    -376,   823,  -376,  -376,  -376,   220,  -376,   779,  -376,   195,
    -376,    31,   638,   779,   224,   823,    99,  -376,  -376,   156,
      11,   170,  -376,  -376,  -376,   166,   162,   173,    18,    47,
      20,  -376,  -376,   779,   779,   176,   125,  -376,   226,  -376,
     227,   223,   232,   184,   233,   239,   823,  -376,   228,  -376,
    -376,  -376,  -376,  -376,   187,  -376,  -376,  -376,   188,  -376,
     189,   638,    89,   240,   247,    71,   208,   258,  -376,  -376,
     249,  -376,   242,  -376,  -376,    52,  -376,  -376,  -376,  -376,
     250,  -376,    21,  -376,   122,   229,   236,   779,  -376,  -376,
     240,   559,   779,   255,   248,   264,   253,   186,   638,   166,
    -376,  -376,   779,  -376,  -376,  -376,   779,  -376,  -376,   231,
     762,   260,  -376,   312,  -376,   779,  -376,  -376,   235,   269,
    -376,  -376,  -376,   779,  -376,   638,  -376,   215,   234,   208,
    -376,   779,   265,   207,   270,  -376,  -376,   158,   779,  -376,
    -376,  -376,   347,   809,   277,  -376,   559,   278,    45,   638,
     282,   266,   638,   283,  -376,  -376,  -376,  -376,  -376,   284,
    -376,  -376,  -376,   233,  -376,   286,  -376,   638,  -376,   275,
    -376,  -376,   249,   289,   290,  -376,   251,   212,   297,    94,
      29,   105,   299,  -376,   256,   779,  -376,  -376,  -376,  -376,
    -376,   779,  -376,  -376,   638,   302,  -376,   287,   638,   762,
    -376,   779,  -376,  -376,  -376,   304,  -376,   638,   638,  -376,
    -376,   779,   809,  -376,  -376,  -376,   809,   305,   809,  -376,
    -376,  -376,   809,  -376,  -376,  -376,   638,  -376,  -376,  -376,
    -376,   638,   242,  -376,   309,   106,  -376,   809,   105,   314,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,   809,  -376
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      11,     0,     0,     0,    79,     0,    80,     0,     0,     0,
       0,    96,     0,     0,     0,    28,   228,   224,   226,   208,
     218,     8,     0,   219,    73,   207,    69,    85,    82,   230,
     209,     0,     0,     0,   288,     0,     4,     2,    11,     0,
      17,     0,   124,   122,     9,    36,   323,    39,    40,    41,
      42,    43,    74,    75,    76,    78,    77,    44,    90,    91,
      45,    46,    47,    37,   117,   118,   119,   120,   121,   300,
     165,   166,   168,   171,   172,   185,   187,   189,   191,   195,
     199,     0,   206,   213,   220,   163,    53,   123,     3,    83,
     218,   116,   109,     0,   284,     0,     0,     0,   294,    72,
     114,     0,    96,     0,     0,   112,     0,   107,    92,   105,
       0,     0,    33,     0,     0,    26,   300,     0,   227,   300,
     223,     0,   222,   221,   300,     0,   225,   170,     0,    66,
     300,    89,    81,   229,     0,     0,   143,   145,   287,     1,
       8,    10,     9,     7,    16,    19,    18,   322,     0,     0,
     299,   251,     0,     0,   162,     0,   176,   175,   177,   179,
     181,   183,   174,   178,     0,   180,     0,     0,     0,     0,
     193,   194,     0,   198,   197,     0,   204,   203,   202,   201,
       0,   205,     0,    15,   245,   211,   213,    59,    61,    65,
      64,     0,    62,    55,    58,    54,    63,    57,    56,    60,
      49,     0,     0,     0,    15,    13,   217,     0,     0,   261,
      28,     0,   293,   250,     0,     0,    95,    97,     0,     0,
       0,     0,     0,   236,   291,     0,     0,     0,     0,    23,
       0,   297,     0,     0,   253,   256,   257,   216,   233,   234,
     214,     0,   231,   232,   215,    71,    68,     0,    84,     0,
     152,     0,     0,     0,     0,     0,   323,    38,   111,   300,
       0,   167,   169,   184,   182,   173,   186,   188,   190,   192,
     196,   200,   239,     0,     0,     0,   271,    14,   264,   267,
     266,     0,   242,     0,   306,     0,     0,   212,    53,    51,
      50,    48,   115,   110,     0,   285,   259,   260,     0,    22,
       0,     0,   294,    87,     0,     0,     0,   103,    99,    94,
     309,   101,   128,   108,   104,   290,    35,    34,   235,    32,
      30,    25,    28,    24,   303,     0,     0,     0,    67,    70,
      87,     0,   147,     0,   138,     0,   130,   143,     0,   144,
     321,   298,     0,   316,   317,   237,     0,   268,   270,   263,
       0,     0,   238,   245,   240,   245,   210,    52,     0,     0,
      21,    20,   292,     0,   113,     0,    93,     0,     0,   308,
     106,     0,   126,   291,     0,    31,    27,    26,   302,   252,
     254,   255,     0,     0,   312,    88,   155,     0,   151,     0,
       0,   140,     0,     0,   142,   141,   164,   269,   262,   320,
     319,   265,   241,   306,   244,   247,    12,     0,    86,   132,
     100,   102,   309,     0,     0,   289,     0,   297,     0,   281,
      28,   275,   157,   159,   158,   311,   310,   154,   153,   148,
     149,     0,   146,   134,     0,     0,   133,   136,     0,     0,
     304,   249,   243,   246,   258,     0,   307,     0,     0,    29,
     295,     0,     0,   280,   278,   279,     0,     0,     0,   274,
     272,   273,     0,   156,   150,   137,     0,   135,   129,   318,
     248,     0,   128,   125,   303,   283,   161,     0,   277,   315,
     139,   131,   127,   301,   282,   160,   276,   314,   313
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -376,  -376,  -376,  -376,  -376,   298,  -376,   133,   300,  -376,
     303,  -376,  -203,   -38,    25,  -376,  -376,  -106,  -376,    37,
       1,   199,  -376,   149,    63,  -376,  -376,  -376,  -376,  -376,
    -376,  -376,  -376,  -376,  -376,  -376,  -376,    23,  -376,  -376,
    -376,  -376,   257,   259,    50,    -9,   144,    62,  -376,    17,
    -376,  -376,  -376,  -376,  -376,  -100,  -376,  -376,  -376,   -64,
    -376,  -376,  -376,    42,   131,  -376,  -376,  -376,  -197,   -12,
    -376,  -375,  -376,    -1,  -376,  -149,   222,    -8,  -376,  -376,
      12,   211,   213,   214,  -376,   210,  -376,   205,  -376,   -68,
    -376,  -376,   200,  -376,  -376,  -376,  -376,  -376,   359,  -376,
    -376,  -376,  -376,  -376,    36,    39,  -376,  -376,    -6,   -10,
    -376,  -376,  -376,   349,  -376,    46,  -322,  -376,   -82,   273,
    -376,   -75,  -110,  -376,  -376,  -376,    -7,    30,   103,    -4,
     -89,   -67,    13,     2,    33,   -60,  -321,  -376,   -17,   192
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    35,    36,    37,    38,    39,    40,   275,    41,    42,
      43,   211,   113,   231,   114,   375,   229,   115,   225,   386,
     250,    46,    47,   288,   200,   201,    48,   129,   328,    49,
      50,    51,    52,    53,    54,    55,    56,   364,   248,    57,
      58,    59,   103,   104,   309,   310,   107,   311,   108,   109,
      60,    61,    62,    63,    64,   372,    65,    66,    67,   334,
     391,   436,    68,   254,   136,   335,   431,   432,   251,   387,
     421,   479,   423,    69,   154,    70,    71,    72,    73,   166,
      74,    75,    76,    77,   172,    78,   175,    79,   180,    80,
      81,    82,   185,    83,   120,   121,   125,   117,    84,   126,
     122,    85,   186,   283,   284,   285,   442,   443,    99,    86,
     118,   379,   234,    87,   298,   277,   278,   347,   459,   460,
     461,   453,   454,   455,    95,    88,    89,   316,   213,   323,
     151,   381,   354,   370,   329,   463,   279,   280,   401,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    45,    94,   260,   101,   224,   235,   300,   422,   238,
     123,   296,   106,   181,   127,   116,   119,   124,   132,    93,
      98,   100,    98,   312,   138,   130,   131,   236,   399,   400,
     239,   135,   137,   227,   110,   243,  -296,    44,   342,    45,
     152,   246,   176,   208,   456,   102,   187,   102,   111,     5,
     206,   429,   112,    92,     7,   336,   188,   207,   167,   203,
     153,   430,   332,    96,   333,   170,   189,   -98,   190,   299,
     111,   153,   111,   191,   112,   142,   112,   475,   203,   209,
     111,   476,   177,   478,   112,   182,   228,     3,   171,   204,
     214,   192,   150,  -296,   205,   178,   193,   179,   305,   167,
    -286,   173,   485,   111,   361,   212,   194,   112,   195,   223,
     233,   174,   271,   150,   196,   183,   184,   399,   400,   197,
     218,   198,   306,    15,    16,   199,   307,   245,   233,    17,
      18,   241,    19,    90,   452,    22,   222,    23,   378,   241,
     233,   395,    25,   232,   150,   458,   452,   262,   308,   259,
      97,   203,    -5,   105,   153,   346,   233,    29,    30,   233,
      29,   134,   233,    34,   139,   143,   348,     2,   409,    -6,
     341,   149,   150,   147,   168,   155,   167,   169,   265,   202,
     210,   289,   276,   282,   290,   215,   219,   220,   230,   237,
     221,   289,   433,   226,   290,   437,   240,   247,   252,   297,
     244,   292,   253,   276,   255,   304,   295,   257,   258,   373,
     444,   263,   272,   303,   380,   286,   377,   457,   356,   264,
     293,   301,   314,   315,   302,   318,   319,   325,   322,   321,
     320,   324,   317,   419,   424,   326,   327,   465,   331,   338,
       3,   468,   349,   350,   351,    98,   330,  -244,   345,   353,
     472,   473,   137,    98,   355,   273,   363,   352,   191,   358,
     359,   360,   365,   307,   368,   369,   374,   339,   371,   480,
     389,   382,   343,   344,   481,   390,    15,    16,   383,   392,
     393,   402,    17,    18,   407,    19,    90,   410,    22,   411,
      23,   406,   414,   425,   416,    25,   428,   434,   438,   435,
     439,   441,   445,   424,   447,   448,   449,   424,   274,   424,
      29,    30,   451,   424,   156,   462,   153,   466,   332,   471,
     477,     3,   157,   158,   159,   378,   384,   160,   424,   161,
     487,   388,    45,   281,   162,   163,   141,   294,   424,   417,
     144,   396,   164,   165,   145,   397,   256,   376,   276,   276,
     291,   357,   282,   385,   404,   366,     3,    15,    16,   216,
     412,   217,   408,    17,    18,   313,    19,    90,   367,    22,
     413,    23,   482,   467,   427,   261,    25,   418,   266,   394,
     270,   267,   269,   268,   337,  -305,   287,    45,   133,   403,
     146,    29,    30,    16,   405,   398,   486,   242,    17,    18,
     484,    19,    90,   415,    22,   362,    23,   483,     1,     2,
       3,    25,     4,   450,   446,     5,   440,   426,     6,   488,
       7,     8,   469,     0,   384,     0,    29,    30,     0,     0,
     464,     0,     0,     9,     0,    10,    11,    12,   276,     0,
     470,    13,    14,     0,     0,     0,    15,    16,   340,     0,
     474,     0,    17,    18,     0,    19,    20,    21,    22,     0,
      23,     0,    24,     0,     0,    25,     0,    26,    27,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    31,     0,    32,    33,    34,     1,     2,     3,
       0,     4,     0,     0,     5,     0,     0,     6,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,    11,    12,     0,     0,     0,
      13,    14,     0,     0,     0,    15,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    90,   140,    22,     0,    23,
       0,    24,     0,     0,    25,     0,    26,    27,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,     0,    32,    33,    34,     1,     2,     3,     0,
       4,     0,     0,     5,     0,     0,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,    11,    12,     0,     0,     0,    13,
      14,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,    18,     0,    19,    90,     0,    22,     3,    23,     0,
      24,     0,     0,    25,     0,    26,    27,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,     0,    32,    33,    34,     1,     0,     3,     0,     4,
       0,     0,     0,    15,    16,     6,     0,     0,     8,    17,
      18,     0,    19,    90,     0,    22,     0,    23,     0,     0,
       9,     0,    25,    11,    12,     0,     0,     0,   128,    14,
       0,     0,     0,    15,    16,     0,     0,    29,    30,    17,
      18,     0,    19,    90,   249,    22,     1,    23,     3,    24,
       4,     0,    25,     0,    26,    27,     6,    28,     0,     8,
       0,     0,     0,     0,     0,     0,     0,    29,    30,     0,
       0,     9,     0,    34,    11,    12,     0,     0,     0,     0,
      14,     0,     0,     0,    15,    16,     0,     0,     0,     3,
      17,    18,     0,    19,    90,     0,    22,     0,    23,     0,
      24,   281,     0,    25,     0,    26,    27,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
       0,     3,     0,     0,    34,    15,    16,     0,     0,     0,
       0,    17,    18,     0,    19,    90,   273,    22,     3,    23,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    16,    29,
      30,     0,     0,    17,    18,     0,    19,    90,     3,    22,
       0,    23,     0,     0,    15,    16,    25,     0,     0,     0,
      17,    18,     3,    19,    90,     0,    22,     0,    23,     0,
       0,    29,    30,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   420,    16,     0,     0,    29,    30,
      17,    18,     0,    19,    90,     0,    22,     0,    23,    16,
       0,     0,     0,    25,    17,    18,     0,    19,    90,     0,
       0,     0,    23,     0,     0,     0,     0,    25,    29,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,    30
};

static const yytype_int16 yycheck[] =
{
       1,     0,     3,   152,    10,   111,   116,   210,   383,   119,
      17,   208,    13,    81,    22,    16,    17,    18,    28,     2,
       8,     9,    10,   220,    34,    26,    27,   116,   350,   350,
     119,    32,    33,    24,    15,   124,    15,     0,    27,    38,
      40,   130,    22,    15,    15,    21,     3,    21,    51,    14,
       9,     6,    55,    55,    19,   252,    13,    16,    10,    21,
      60,    16,    31,    55,    33,    47,    23,    41,    25,    72,
      51,    60,    51,    30,    55,    38,    55,   452,    21,    51,
      51,   456,    62,   458,    55,    21,    77,     9,    70,    51,
      42,    48,    16,    72,    56,    75,    53,    77,    41,    10,
       0,    54,   477,    51,   301,    16,    63,    55,    65,   110,
      34,    64,   180,    16,    71,    51,    52,   439,   439,    76,
     103,    78,    51,    45,    46,    82,    55,   128,    34,    51,
      52,    34,    54,    55,    40,    57,     6,    59,    16,    34,
      34,   338,    64,    15,    16,    40,    40,   155,    77,   150,
      55,    21,     0,    55,    60,    30,    34,    79,    80,    34,
      79,    15,    34,    85,     0,    28,   276,     8,   365,     0,
     259,    16,    16,    74,    12,     5,    10,     4,   166,    16,
      51,   191,   183,   184,   191,    42,    41,    15,    30,    68,
      16,   201,   389,    15,   201,   392,    72,    16,    15,   209,
      73,   202,    16,   204,     6,   215,   207,    56,    55,   315,
     407,    57,    55,   214,   324,    24,   322,   420,   286,    42,
      55,    15,    55,    16,   212,   226,    55,   233,    16,   230,
      55,   232,    72,   382,   383,   241,    16,   434,    43,    15,
       9,   438,    16,    16,    21,   233,   247,    15,    72,    16,
     447,   448,   253,   241,    15,    24,    16,    73,    30,    72,
      72,    72,    15,    55,     6,    16,    16,   255,    26,   466,
      15,    42,   273,   274,   471,    27,    45,    46,    42,    15,
      27,    21,    51,    52,    15,    54,    55,    72,    57,    55,
      59,    56,    27,    16,    24,    64,    18,    15,    15,    33,
      16,    15,    27,   452,    15,    15,    55,   456,    77,   458,
      79,    80,    15,   462,    29,    16,    60,    15,    31,    15,
      15,     9,    37,    38,    39,    16,   327,    42,   477,    44,
      16,   332,   331,    21,    49,    50,    38,   204,   487,   377,
      40,   342,    57,    58,    41,   346,   147,   322,   349,   350,
     201,   288,   353,   330,   355,   305,     9,    45,    46,   102,
     369,   102,   363,    51,    52,   221,    54,    55,   306,    57,
     371,    59,   472,   437,   386,   153,    64,   378,   167,   337,
     175,   168,   172,   169,   253,    73,   186,   386,    29,   353,
      41,    79,    80,    46,   355,   349,   478,   124,    51,    52,
     475,    54,    55,   373,    57,   302,    59,   474,     7,     8,
       9,    64,    11,   417,   412,    14,   403,   384,    17,   479,
      19,    20,   439,    -1,   425,    -1,    79,    80,    -1,    -1,
     431,    -1,    -1,    32,    -1,    34,    35,    36,   439,    -1,
     441,    40,    41,    -1,    -1,    -1,    45,    46,   256,    -1,
     451,    -1,    51,    52,    -1,    54,    55,    56,    57,    -1,
      59,    -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    -1,    83,    84,    85,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    56,    57,    -1,    59,
      -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    85,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,     9,    59,    -1,
      61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    -1,    83,    84,    85,     7,    -1,     9,    -1,    11,
      -1,    -1,    -1,    45,    46,    17,    -1,    -1,    20,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      32,    -1,    64,    35,    36,    -1,    -1,    -1,    70,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,    79,    80,    51,
      52,    -1,    54,    55,    56,    57,     7,    59,     9,    61,
      11,    -1,    64,    -1,    66,    67,    17,    69,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    -1,
      -1,    32,    -1,    85,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,     9,
      51,    52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      61,    21,    -1,    64,    -1,    66,    67,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      -1,     9,    -1,    -1,    85,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    24,    57,     9,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    79,
      80,    -1,    -1,    51,    52,    -1,    54,    55,     9,    57,
      -1,    59,    -1,    -1,    45,    46,    64,    -1,    -1,    -1,
      51,    52,     9,    54,    55,    -1,    57,    -1,    59,    -1,
      -1,    79,    80,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    79,    80,
      51,    52,    -1,    54,    55,    -1,    57,    -1,    59,    46,
      -1,    -1,    -1,    64,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    11,    14,    17,    19,    20,    32,
      34,    35,    36,    40,    41,    45,    46,    51,    52,    54,
      55,    56,    57,    59,    61,    64,    66,    67,    69,    79,
      80,    81,    83,    84,    85,    87,    88,    89,    90,    91,
      92,    94,    95,    96,   105,   106,   107,   108,   112,   115,
     116,   117,   118,   119,   120,   121,   122,   125,   126,   127,
     136,   137,   138,   139,   140,   142,   143,   144,   148,   159,
     161,   162,   163,   164,   166,   167,   168,   169,   171,   173,
     175,   176,   177,   179,   184,   187,   195,   199,   211,   212,
      55,   159,    55,   135,   159,   210,    55,    55,   166,   194,
     166,   194,    21,   128,   129,    55,   159,   132,   134,   135,
      15,    51,    55,    98,   100,   103,   159,   183,   196,   159,
     180,   181,   186,   212,   159,   182,   185,   163,    70,   113,
     159,   159,   195,   184,    15,   159,   150,   159,   195,     0,
      56,    91,   105,    28,    94,    96,   199,    74,   225,    16,
      16,   216,    40,    60,   160,     5,    29,    37,    38,    39,
      42,    44,    49,    50,    57,    58,   165,    10,    12,     4,
      47,    70,   170,    54,    64,   172,    22,    62,    75,    77,
     174,   175,    21,    51,    52,   178,   188,     3,    13,    23,
      25,    30,    48,    53,    63,    65,    71,    76,    78,    82,
     110,   111,    16,    21,    51,    56,     9,    16,    15,    51,
      51,    97,    16,   214,    42,    42,   128,   129,   135,    41,
      15,    16,     6,   159,   103,   104,    15,    24,    77,   102,
      30,    99,    15,    34,   198,   208,   216,    68,   208,   216,
      72,    34,   205,   216,    73,   159,   216,    16,   124,    56,
     106,   154,    15,    16,   149,     6,   107,    56,    55,   159,
     161,   162,   163,    57,    42,   166,   167,   168,   169,   171,
     173,   175,    55,    24,    77,    93,   159,   201,   202,   222,
     223,    21,   159,   189,   190,   191,    24,   178,   109,   195,
     212,   109,   159,    55,    93,   159,   154,   195,   200,    72,
      98,    15,   166,   159,   195,    41,    51,    55,    77,   130,
     131,   133,   154,   132,    55,    16,   213,    72,   159,    55,
      55,   159,    16,   215,   159,   194,   194,    16,   114,   220,
     159,    43,    31,    33,   145,   151,   154,   150,    15,   166,
     225,   216,    27,   159,   159,    72,    30,   203,   208,    16,
      16,    21,    73,    16,   218,    15,   175,   110,    72,    72,
      72,   154,   214,    16,   123,    15,   130,   133,     6,    16,
     219,    26,   141,   103,    16,   101,   100,   103,    16,   197,
     208,   217,    42,    42,   159,   123,   105,   155,   159,    15,
      27,   146,    15,    27,   149,   154,   159,   159,   201,   202,
     222,   224,    21,   190,   159,   191,    56,    15,   159,   154,
      72,    55,   131,   159,    27,   213,    24,    99,   159,   161,
      45,   156,   157,   158,   161,    16,   220,   155,    18,     6,
      16,   152,   153,   154,    15,    33,   147,   154,    15,    16,
     218,    15,   192,   193,   154,    27,   219,    15,    15,    55,
     215,    15,    40,   207,   208,   209,    15,    98,    40,   204,
     205,   206,    16,   221,   159,   154,    15,   145,   154,   224,
     159,    15,   154,   154,   159,   157,   157,    15,   157,   157,
     154,   154,   141,   217,   207,   157,   204,    16,   221
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    88,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   105,   105,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   116,   117,   117,   117,   117,   117,   118,
     119,   120,   120,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   131,   131,   132,   132,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   159,   159,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   174,   174,   174,   175,   175,   176,   176,   176,
     177,   177,   178,   178,   179,   179,   179,   179,   179,   179,
     179,   180,   180,   181,   181,   182,   182,   183,   183,   184,
     184,   185,   185,   186,   186,   187,   187,   188,   188,   188,
     189,   190,   190,   190,   191,   191,   192,   192,   193,   193,
     194,   195,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   200,   201,   201,   201,   201,   201,   201,   202,   202,
     203,   203,   204,   204,   205,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   210,   210,   211,   212,   212,   213,
     213,   213,   214,   214,   214,   215,   215,   215,   216,   216,
     216,   217,   217,   217,   218,   218,   218,   219,   219,   219,
     220,   220,   220,   221,   221,   221,   222,   223,   224,   224,
     224,   225,   225,   225
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     0,     6,     3,     1,     0,     2,     1,     2,     2,
       5,     3,     2,     2,     3,     2,     0,     4,     0,     3,
       0,     3,     2,     1,     3,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     0,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     1,     2,     0,     3,     0,
       1,     1,     2,     5,     4,     2,     0,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       3,     3,     2,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     2,     1,     1,     1,
       4,     3,     2,     1,     4,     0,     1,     3,     1,     3,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       4,     2,     2,     0,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     1,     0,     2,
       1,     2,     2,     2,     2,     4,     3,     3,     3,     2,
       2,     3,     1,     4,     1,     0,     1,     0,     2,     1,
       2,     2,     4,     2,     1,     1,     1,     1,     7,     4,
       1,     0,     3,     2,     1,     3,     1,     1,     2,     3,
       1,     0,     1,     1,     5,     4,     3,     2,     1,     1,
       5,     4,     3,     2,     1,     3,     1,     2,     1,     3,
       1,     0,     3,     1,     0,     4,     1,     0,     3,     1,
       0,     5,     1,     0,     3,     1,     0,     3,     1,     0,
       3,     3,     2,     3,     3,     2,     2,     2,     3,     1,
       1,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 14:
#line 72 "parse.y" /* yacc.c:1646  */
    { (yyval.ast)=new AstNumber('K',(yyvsp[0].ast)); }
#line 1796 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 163 "parse.y" /* yacc.c:1646  */
    { std::cout << (yyvsp[0].ast) << std::endl; }
#line 1802 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 338 "parse.y" /* yacc.c:1646  */
    {std::cout<<"Plus_Stmt"<<std::endl;}
#line 1808 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 418 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = new AstNumber('K', (yyvsp[0].ast));}
#line 1814 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 420 "parse.y" /* yacc.c:1646  */
    {  
		if((yyvsp[-1].ast) == '+' )
			(yyval.ast) = new AstNode('+',(yyvsp[-2].ast),(yyvsp[0].ast));
			
		if((yyvsp[-1].ast) == '-')
			(yyval.ast) = new AstNode('-',(yyvsp[-2].ast),(yyvsp[0].ast));//$$ = $1 - $3;
	   }
#line 1826 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 429 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '+';}
#line 1832 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 430 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '-';}
#line 1838 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 433 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = new AstNumber('K', (yyvsp[0].ast));}
#line 1844 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 435 "parse.y" /* yacc.c:1646  */
    { 
			if('*' == (yyvsp[-1].ast)){
				std::cout<<"Multiplication"<<std::endl;
				(yyval.ast) = (yyvsp[-2].ast)*(yyvsp[0].ast);
			}
			
			if('/' == (yyvsp[-1].ast))
			{ 
				std::cout<<"Division"<<std::endl;
				if( 0 != (yyvsp[0].ast))
					(yyval.ast) = floor((float)(yyvsp[-2].ast)/(float)(yyvsp[0].ast));
				else{
				    std::cout<<"ZeroDivisionError: Integer division or modulo by zero"<<std::endl;
					(yyval.ast) = 0;
					}
			}
			
			if('%' == (yyvsp[-1].ast))
			{
				std::cout<<"Modulus"<<std::endl;
				if( 0 != (yyvsp[0].ast))
					(yyval.ast) = (floor)((float)(yyvsp[-2].ast) - (((float)(yyvsp[-2].ast)/(float)(yyvsp[0].ast))) * (float)(yyvsp[0].ast));
				else{
				    std::cout<<"Traceback (most recent call last):"<<std::endl;
					std::cout<<"  File \"<stdin>\", line 1, in <module>"<<std::endl;
					std::cout<<"ZeroDivisionError: Integer division or modulo by zero"<<std::endl;
					(yyval.ast) = 0;
					}
				   
			
				if('D' == (yyvsp[-1].ast)){
				std::cout<<"Integer Division"<<std::endl;
				(yyval.ast) = floor((float)(yyvsp[-2].ast)/(float)(yyvsp[0].ast));
				std::cout<<"$1="<<(yyvsp[-2].ast)<<"$3="<<(yyvsp[0].ast)<<std::endl;
				}
				
			
			}
		}
#line 1888 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 476 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '*';}
#line 1894 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 477 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '/';}
#line 1900 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 478 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '%';}
#line 1906 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 479 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = 'D';}
#line 1912 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 483 "parse.y" /* yacc.c:1646  */
    { 
	  if('+' == (yyvsp[-1].ast))
		(yyval.ast) = (yyvsp[0].ast);
	  if('-' == (yyvsp[-1].ast))
		(yyval.ast) = -(yyvsp[0].ast);
	}
#line 1923 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 492 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '+';}
#line 1929 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 493 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = '-';}
#line 1935 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 497 "parse.y" /* yacc.c:1646  */
    {   if(0>(yyvsp[0].ast))
												std::cout<<"NOT_HANDLED: Negative Exponent"<<std::endl;
											  else
												(yyval.ast) = pow((yyvsp[-3].ast),(yyvsp[0].ast)); }
#line 1944 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 508 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1950 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 513 "parse.y" /* yacc.c:1646  */
    { (yyval.ast) = new AstNumber('K', (yyvsp[0].d));}
#line 1956 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 1960 "parse.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 716 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (char const *s) {
	fprintf (stderr, "%d: %s with [%s]\n", yylineno, s, yytext);
}

