
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Parser.y"


#include <stdio.h>
#include "Common.h"

FILE *yyin;
int yyerror();
SyntaxTree* SyntaxTree_init(Type type, const char* text, int children);

extern int yylex();

SyntaxTree* root;



/* Line 189 of yacc.c  */
#line 89 "Parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_MAIN_RULE = 258,
     TMP_STATE = 259,
     KW_MOVES = 260,
     KW_PLAYERS = 261,
     KW_STATE = 262,
     KW_INT = 263,
     KW_BOOL = 264,
     KW_RETURN = 265,
     KW_IF = 266,
     KW_WHILE = 267,
     IDENTIFIER = 268,
     INTEGER = 269,
     BOOLEAN = 270,
     OPERATOR_EQUAL = 271,
     OPERATOR_NOT_EQUAL = 272,
     OPERATOR_LESS_EQUAL = 273,
     OPERATOR_GREATER_EQUAL = 274,
     OPERATOR_AND = 275,
     OPERATOR_OR = 276,
     TMP = 277
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
/* Line 214 of yacc.c  */
#line 16 "Parser.y"
symval
{

/* Line 214 of yacc.c  */
#line 16 "Parser.y"

	struct SyntaxTree* t;



/* Line 214 of yacc.c  */
#line 156 "Parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 168 "Parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    41,    39,    30,     2,     2,
      33,    34,    28,    26,    42,    27,    40,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      24,    36,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    13,    19,    24,    29,    31,    34,
      40,    44,    45,    48,    54,    56,    58,    60,    62,    67,
      68,    71,    73,    75,    77,    79,    84,    87,    91,    99,
     107,   109,   111,   115,   119,   123,   127,   131,   135,   138,
     142,   146,   150,   154,   158,   162,   166,   170,   173,   176,
     177,   180,   183,   185,   189,   195,   197,   200,   203,   205,
     209,   219,   221,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    46,    47,    48,    -1,     6,    31,
      49,    32,    -1,     7,    51,    33,    56,    34,    -1,     3,
      31,    66,    32,    -1,     5,    31,    70,    32,    -1,    50,
      -1,    50,    49,    -1,    13,    31,    14,    32,    35,    -1,
      31,    52,    32,    -1,    -1,    53,    52,    -1,    54,    13,
      36,    55,    35,    -1,     8,    -1,     9,    -1,    14,    -1,
      15,    -1,    51,    37,    57,    38,    -1,    -1,    58,    57,
      -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,    64,
      36,    63,    35,    -1,    10,    35,    -1,    10,    63,    35,
      -1,    11,    33,    63,    34,    37,    57,    38,    -1,    12,
      33,    63,    34,    37,    57,    38,    -1,    64,    -1,    55,
      -1,    33,    63,    34,    -1,    63,    26,    63,    -1,    63,
      27,    63,    -1,    63,    28,    63,    -1,    63,    29,    63,
      -1,    63,    30,    63,    -1,    27,    63,    -1,    63,    16,
      63,    -1,    63,    17,    63,    -1,    63,    19,    63,    -1,
      63,    18,    63,    -1,    63,    25,    63,    -1,    63,    24,
      63,    -1,    63,    20,    63,    -1,    63,    21,    63,    -1,
      23,    63,    -1,    65,    13,    -1,    -1,    39,    40,    -1,
      41,    40,    -1,    67,    -1,    67,    30,    66,    -1,    13,
      33,    56,    34,    68,    -1,    69,    -1,    69,    68,    -1,
      13,    56,    -1,    71,    -1,    71,    30,    70,    -1,    13,
      24,    72,    25,    51,    33,    56,    34,    56,    -1,    28,
      -1,    73,    -1,    13,    -1,    13,    42,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    68,    75,    83,    90,   100,   106,   114,
     125,   133,   137,   145,   154,   160,   167,   173,   183,   191,
     195,   204,   210,   216,   222,   229,   237,   241,   248,   256,
     266,   272,   278,   284,   291,   298,   305,   312,   319,   326,
     333,   340,   347,   354,   361,   368,   375,   382,   390,   398,
     402,   406,   413,   419,   428,   438,   444,   452,   461,   467,
     475,   486,   490,   497,   503
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_MAIN_RULE", "TMP_STATE", "KW_MOVES",
  "KW_PLAYERS", "KW_STATE", "KW_INT", "KW_BOOL", "KW_RETURN", "KW_IF",
  "KW_WHILE", "IDENTIFIER", "INTEGER", "BOOLEAN", "OPERATOR_EQUAL",
  "OPERATOR_NOT_EQUAL", "OPERATOR_LESS_EQUAL", "OPERATOR_GREATER_EQUAL",
  "OPERATOR_AND", "OPERATOR_OR", "TMP", "'!'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'['", "']'", "'('", "')'", "';'", "'='", "'{'",
  "'}'", "'$'", "'.'", "'#'", "','", "$accept", "GAME", "PLAYERS", "STATE",
  "MAIN_RULE", "MOVES", "PLAYERS_LIST", "PLAYER", "DATA_SET", "VAR_LIST",
  "VAR_DECLARATION", "VAR_TYPE", "VAR_DEFINITION", "INSTRUCTION_BLOCK",
  "INSTRUCTION_LIST", "INSTRUCTION", "ASSIGN_INSTR", "RETURN_INSTR",
  "IF_INSTR", "WHILE_INSTR", "EXPR", "VAR_REFERENCE", "SCOPE",
  "M_RULE_LIST", "M_RULE", "PAYOFF_LIST", "PAYOFF", "MOVE_LIST", "MOVE",
  "PLAYERS_SCOPE", "IDENTIFIER_LIST", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    33,    60,    62,    43,    45,    42,    47,
      37,    91,    93,    40,    41,    59,    61,   123,   125,    36,
      46,    35,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    48,    49,    49,    50,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    59,    60,    60,    61,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      65,    65,    66,    66,    67,    68,    68,    69,    70,    70,
      71,    72,    72,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     5,     4,     4,     1,     2,     5,
       3,     0,     2,     5,     1,     1,     1,     1,     4,     0,
       2,     1,     1,     1,     1,     4,     2,     3,     7,     7,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     0,
       2,     2,     1,     3,     5,     1,     2,     2,     1,     3,
       9,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       7,    11,     0,     0,     0,     0,     3,     8,    14,    15,
       0,    11,     0,     0,     0,     0,     2,     0,    10,    12,
       0,     0,     0,     0,     0,    52,     0,     0,     0,    19,
       4,     0,     5,     0,     0,     0,    58,     9,    16,    17,
       0,    49,     0,     0,     0,     0,     0,    19,    21,    22,
      23,    24,     0,     0,     0,    53,     0,     6,     0,    13,
      49,    49,    49,    26,    31,     0,    30,    49,    49,    50,
      51,    18,    20,    49,    48,     0,    63,    61,     0,    62,
      59,    47,    38,     0,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    27,     0,     0,
       0,     0,    54,    55,     0,     0,    32,    39,    40,    42,
      41,    45,    46,    44,    43,    33,    34,    35,    36,    37,
       0,     0,    25,    57,    56,    64,     0,    19,    19,     0,
       0,     0,     0,    28,    29,     0,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    14,    26,     9,    10,    31,    20,
      21,    22,    74,    32,    56,    57,    58,    59,    60,    61,
      75,    76,    63,    34,    35,   112,   113,    45,    46,    88,
      89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
      15,   -24,    22,    20,    28,   -67,    12,    44,    19,    21,
      28,     1,    18,    24,    47,    42,   -67,   -67,   -67,   -67,
      27,     1,    49,    12,    50,    29,   -67,    33,   -67,   -67,
      32,    37,    35,    43,    60,    63,    81,    62,     4,     3,
     -67,    12,   -67,    50,    71,    66,    72,   -67,   -67,   -67,
      68,    31,    73,    74,    64,    76,    70,     3,   -67,   -67,
     -67,   -67,    89,   104,    92,   -67,    -5,   -67,    81,   -67,
      34,    34,    34,   -67,   -67,    61,   -67,    34,    34,   -67,
     -67,   -67,   -67,    34,   -67,   115,    85,   -67,   111,   -67,
     -67,   186,    -4,   114,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,   -67,   133,   152,
      94,    12,   -67,   115,   124,    12,   -67,   199,   199,   204,
     204,   186,   171,   204,   204,    -4,    -4,   -67,   -67,   -67,
     108,   109,   -67,   -67,   -67,   -67,   122,     3,     3,    12,
     118,   126,   113,   -67,   -67,    12,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   -67,   155,   -67,    -6,   145,
     -67,   -67,   136,   -40,   -54,   -67,   -67,   -67,   -67,   -67,
     -66,   -37,   -67,   132,   -67,    79,   -67,   116,   -67,   -67,
      69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      12,    64,    62,    82,    91,    92,    93,     4,    86,    18,
      19,   108,   109,    51,    52,    53,   -49,   110,    48,    49,
      62,     1,     5,    87,   104,   105,   106,     6,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     8,    54,    11,    55,    48,    49,    13,    48,    49,
      15,    23,    25,    16,    70,    24,    27,    70,    71,    28,
      36,    71,    30,    33,    72,    37,    73,    72,    38,    40,
      54,   133,    55,    54,    39,    55,    41,    94,    95,    96,
      97,    98,    99,   140,   141,   100,   101,   102,   103,   104,
     105,   106,    42,    43,    44,    66,   107,    47,    67,   142,
      62,    62,    68,    69,    79,   146,    77,    78,    81,   136,
      94,    95,    96,    97,    98,    99,    80,    84,   100,   101,
     102,   103,   104,   105,   106,    83,    85,   114,   111,   132,
      94,    95,    96,    97,    98,    99,   115,    86,   100,   101,
     102,   103,   104,   105,   106,   137,   138,   145,   116,    94,
      95,    96,    97,    98,    99,   139,   143,   100,   101,   102,
     103,   104,   105,   106,   144,    17,    29,   130,    94,    95,
      96,    97,    98,    99,    50,    65,   100,   101,   102,   103,
     104,   105,   106,   135,    90,     0,   131,    94,    95,    96,
      97,    98,   134,     0,     0,   100,   101,   102,   103,   104,
     105,   106,    94,    95,    96,    97,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,    96,    97,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
       6,    41,    39,    57,    70,    71,    72,    31,    13,     8,
       9,    77,    78,    10,    11,    12,    13,    83,    14,    15,
      57,     6,     0,    28,    28,    29,    30,     7,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    13,    39,    31,    41,    14,    15,     3,    14,    15,
      31,    33,     5,    32,    23,    31,    14,    23,    27,    32,
      31,    27,    13,    13,    33,    32,    35,    33,    36,    34,
      39,   111,    41,    39,    37,    41,    33,    16,    17,    18,
      19,    20,    21,   137,   138,    24,    25,    26,    27,    28,
      29,    30,    32,    30,    13,    24,    35,    35,    32,   139,
     137,   138,    30,    35,    40,   145,    33,    33,    38,   115,
      16,    17,    18,    19,    20,    21,    40,    13,    24,    25,
      26,    27,    28,    29,    30,    36,    34,    42,    13,    35,
      16,    17,    18,    19,    20,    21,    25,    13,    24,    25,
      26,    27,    28,    29,    30,    37,    37,    34,    34,    16,
      17,    18,    19,    20,    21,    33,    38,    24,    25,    26,
      27,    28,    29,    30,    38,    10,    21,    34,    16,    17,
      18,    19,    20,    21,    38,    43,    24,    25,    26,    27,
      28,    29,    30,   114,    68,    -1,    34,    16,    17,    18,
      19,    20,   113,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    44,    45,    31,     0,     7,    46,    13,    49,
      50,    31,    51,     3,    47,    31,    32,    49,     8,     9,
      52,    53,    54,    33,    31,     5,    48,    14,    32,    52,
      13,    51,    56,    13,    66,    67,    31,    32,    36,    37,
      34,    33,    32,    30,    13,    70,    71,    35,    14,    15,
      55,    10,    11,    12,    39,    41,    57,    58,    59,    60,
      61,    62,    64,    65,    56,    66,    24,    32,    30,    35,
      23,    27,    33,    35,    55,    63,    64,    33,    33,    40,
      40,    38,    57,    36,    13,    34,    13,    28,    72,    73,
      70,    63,    63,    63,    16,    17,    18,    19,    20,    21,
      24,    25,    26,    27,    28,    29,    30,    35,    63,    63,
      63,    13,    68,    69,    42,    25,    34,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      34,    34,    35,    56,    68,    73,    51,    37,    37,    33,
      57,    57,    56,    38,    38,    34,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 55 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(game, "", 4);
	root = st;
	
	st->children[0] = (yyvsp[(1) - (4)].t);
	st->children[1] = (yyvsp[(2) - (4)].t);
	st->children[2] = (yyvsp[(3) - (4)].t);
	st->children[3] = (yyvsp[(4) - (4)].t);
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 68 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(players, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(3) - (4)].t);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 75 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(state, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (5)].t);
	st->children[1] = (yyvsp[(4) - (5)].t);
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 83 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(main_rule, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(3) - (4)].t);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 90 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(moves, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(3) - (4)].t);
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 100 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(players_list, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 106 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(players_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 114 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(player, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (5)].t);
	st->children[1] = (yyvsp[(3) - (5)].t);
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 125 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(data_set, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (3)].t);
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 133 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_list_tail, "", 0);
	(yyval.t) = st;
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 137 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 145 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_declaration, "", 3);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (5)].t);
	st->children[1] = (yyvsp[(2) - (5)].t);
	st->children[2] = (yyvsp[(4) - (5)].t);
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 154 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_type, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 160 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_type, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 167 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_definition, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 173 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_definition, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 183 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction_block, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (4)].t);
	st->children[1] = (yyvsp[(3) - (4)].t);
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 191 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction_list_tail, "", 0);
	(yyval.t) = st;
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 195 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 204 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 210 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 216 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 222 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(instruction, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 229 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(assign_instr, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (4)].t);
	st->children[1] = (yyvsp[(3) - (4)].t);
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 237 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(return_instr, "", 0);
	(yyval.t) = st;
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 241 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(return_instr, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (3)].t);
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 248 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(if_instr, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(3) - (7)].t);
	st->children[1] = (yyvsp[(6) - (7)].t);
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 256 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(while_instr, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(3) - (7)].t);
	st->children[1] = (yyvsp[(6) - (7)].t);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 266 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_ref, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 272 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_literal, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 278 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (3)].t);
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_add, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 291 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_sub, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 298 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_mul, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 305 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_div, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 312 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_mod, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 319 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_neg, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 326 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_equal, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 333 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_not_equal, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 340 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_greater_equal, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 347 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_greater_equal, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 354 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_greater, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 361 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_less, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 368 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_and, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 375 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_or, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 382 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(expr_not, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 390 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(var_reference, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 398 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(local_scope, "", 0);
	(yyval.t) = st;
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 402 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(state_scope, "", 0);
	(yyval.t) = st;
;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 406 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(move_scope, "", 0);
	(yyval.t) = st;
;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 413 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(m_rule_list, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 419 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(m_rule_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 428 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(m_rule, "", 3);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (5)].t);
	st->children[1] = (yyvsp[(3) - (5)].t);
	st->children[2] = (yyvsp[(5) - (5)].t);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 438 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(payoff_list, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 444 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(payoff_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 452 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(payoff, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (2)].t);
	st->children[1] = (yyvsp[(2) - (2)].t);
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 461 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(move_list, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 467 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(move_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 475 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(move, "", 5);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (9)].t);
	st->children[1] = (yyvsp[(3) - (9)].t);
	st->children[2] = (yyvsp[(5) - (9)].t);
	st->children[3] = (yyvsp[(7) - (9)].t);
	st->children[4] = (yyvsp[(9) - (9)].t);
;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 486 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(players_scope, "", 0);
	(yyval.t) = st;
;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 490 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(players_scope, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 497 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(identifier_list, "", 1);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (1)].t);
;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 503 "Parser.y"
    {
	SyntaxTree* st = SyntaxTree_init(identifier_list, "", 2);
	(yyval.t) = st;
	
	st->children[0] = (yyvsp[(1) - (3)].t);
	st->children[1] = (yyvsp[(3) - (3)].t);
;}
    break;



/* Line 1455 of yacc.c  */
#line 2283 "Parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 515 "Parser.y"


SyntaxTree* parser_main(char *file_path)
{
	FILE *fp = NULL;
	
	fopen_s(&fp, file_path, "rb");

	if (fp == NULL)
	{
		perror("Failed to open file");
		return NULL;
	}
	else
	{
		yyin = fp;
	}

	yyparse();

	if (fp != NULL)
	{
		fclose(fp);
	}

	return root;
}

int yyerror(const char *p) {

	printf("%s\n", p);
	return 0;
}

SyntaxTree* SyntaxTree_init(Type type, const char* text, int children)
{
	SyntaxTree* st = (SyntaxTree*)malloc(sizeof(SyntaxTree));
	if (st == NULL) { printf("Memry allocation error\n"); exit(-1); }

	st->children =(SyntaxTree**) malloc(sizeof(SyntaxTree) * children);
	if (st->children == NULL) { printf("Memry allocation error\n"); exit(-1); }

	st->type = type;
	st->children_num = children;
	
	st->text = calloc(strlen(text) + 1, 1);
	strcpy_s(st->text, strlen(text) + 1, text);

	return st;
}

