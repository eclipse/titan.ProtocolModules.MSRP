/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Substitute the variable and function names.  */
#define yyparse         MSRP_parse_parse
#define yylex           MSRP_parse_lex
#define yyerror         MSRP_parse_error
#define yylval          MSRP_parse_lval
#define yychar          MSRP_parse_char
#define yydebug         MSRP_parse_debug
#define yynerrs         MSRP_parse_nerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "MSRP.y"

/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
* Gabor Szalai
* Attila Balasko
* Balasko Jeno
* Kulcsár Endre
* Rita Tomasitsne Kovacs
* Sandor Palugyai
* Zsolt Szalai
* Janos Kovesdi
******************************************************************************/
//
//  File:               MSRP.y
//  Rev:                R8A
//  Prodnr:             CNL 113 467
/*C declarations*/

#include "MSRP_parse.h"
#include <stdarg.h>
#include <string.h>
#define YYDEBUG 1
using namespace MSRP__Types;


extern int MSRP_parse_lex();
extern int MSRP_parse_error(const char *s);
extern int error_occured;
extern bool ipv6_br;

PDU__MSRP* MSRP_parse_parsed_message;
MsrpOtherMimeHeader* msrpOtherMimeHeader_parsed;
MsrpHeader* msrpHeader_parsed;
MsrpUri* MsrpUri_parse_parsed_message;

void init_msrpOtherMimeHeader_parsed(){
  if(!msrpOtherMimeHeader_parsed) {
    msrpOtherMimeHeader_parsed=new MsrpOtherMimeHeader(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE);
  }
}



/* Line 268 of yacc.c  */
#line 124 "MSRP_parse_.tab.c"

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
     INT_TOKEN = 258,
     TOKEN = 259,
     CHR_TOKEN = 260,
     TID_TOKEN = 261,
     TOKEN_S = 262,
     DATA_TOKEN = 263,
     H_OTHER = 264,
     H_CONTENT_OTHER = 265,
     SEMICOLON_TOKEN = 266,
     TOKEN_AT = 267,
     END_LINE = 268,
     CRLF = 269,
     MSRP_TOKEN = 270,
     SP = 271,
     DASH = 272,
     SLASH = 273,
     DT_DSLASH = 274,
     COLON = 275,
     SEMICOLON = 276,
     EQ = 277,
     CRLFCRLF = 278,
     H_SUCCES_REPORT = 279,
     H_MESSAGE_ID = 280,
     H_FAILURE_REPORT = 281,
     H_BYTE_RANGE = 282,
     H_STATUS = 283,
     H_TO_PATH = 284,
     H_FROM_PATH = 285,
     H_CONTENT_TYPE = 286,
     H_CONTENT_ID = 287,
     H_CONTENT_DESCRIPTION = 288,
     H_CONTENT_DISPOSITION = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 44 "MSRP.y"

	INTEGER* intnum;
	CHARSTRING* charstring;
	MSRP__Types::MsrpResponseStart* msrpResponseStart;
	MSRP__Types::MsrpRequestStart* msrpRequestStart;
	MSRP__Types::MsrpHeaderPAR* genpram;
	MSRP__Types::MsrpGenParamSETOF* msrpGenParamSETOF;
	MSRP__Types::dispHeader* dispheader;
	MSRP__Types::MsrpDispositionParm* msrpDispositionParm;
	MSRP__Types::MsrpContentStuff* msrpContentStuff;
	MSRP__Types::MsrpEndLine* msrpEndLine;
	MSRP__Types::MsrpUri* msrpUri;
	MSRP__Types::MsrpPath* msrpPath;
	MSRP__Types::MsrpHeaders* msrpHeaders;



/* Line 293 of yacc.c  */
#line 212 "MSRP_parse_.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 224 "MSRP_parse_.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    12,    16,    20,    25,    30,
      32,    36,    45,    46,    48,    49,    52,    53,    56,    58,
      59,    61,    62,    64,    66,    69,    74,    79,    84,    93,
     100,   109,   114,   119,   123,   124,   126,   136,   137,   139,
     141,   144,   149,   154,   160,   165,   166,   168,   170,   173,
     178,   181,   182,   184,   186,   189,   194,   197,   204,   211
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    38,    -1,    64,    39,    53,
      52,    -1,    65,    39,    52,    -1,    40,    41,    49,    -1,
      29,    16,    42,    14,    -1,    30,    16,    42,    14,    -1,
      43,    -1,    42,    16,    43,    -1,     4,    19,    44,     4,
      45,    46,    47,    48,    -1,    -1,    12,    -1,    -1,    20,
       4,    -1,    -1,    18,     4,    -1,    11,    -1,    -1,    11,
      -1,    -1,    50,    -1,    51,    -1,    50,    51,    -1,    25,
      16,     4,    14,    -1,    24,    16,     4,    14,    -1,    26,
      16,     4,    14,    -1,    27,    16,     4,    17,     4,    18,
       4,    14,    -1,    28,    16,     4,    16,     3,    14,    -1,
      28,    16,     4,    16,     3,    16,     7,    14,    -1,     9,
      16,     7,    14,    -1,    13,     6,     4,    14,    -1,     6,
       4,    14,    -1,    -1,    54,    -1,    55,    31,    16,     4,
      18,     4,    61,    23,     8,    -1,    -1,    56,    -1,    57,
      -1,    56,    57,    -1,    32,    16,     4,    14,    -1,    33,
      16,     4,    14,    -1,    34,    16,     4,    58,    14,    -1,
      10,    16,     7,    14,    -1,    -1,    59,    -1,    60,    -1,
      59,    60,    -1,    21,     4,    22,     4,    -1,    21,     4,
      -1,    -1,    62,    -1,    63,    -1,    62,    63,    -1,    21,
       4,    22,     4,    -1,    21,     4,    -1,    15,    16,     6,
      16,     5,    14,    -1,    15,    16,     6,    16,     3,    14,
      -1,    15,    16,     6,    16,     3,    16,     7,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    88,    94,   113,   124,   134,   136,   138,
     143,   150,   196,   197,   199,   200,   202,   203,   205,   207,
     208,   211,   212,   214,   215,   217,   221,   232,   245,   253,
     260,   268,   279,   284,   290,   291,   293,   322,   323,   325,
     326,   328,   333,   338,   349,   361,   362,   364,   369,   376,
     381,   386,   387,   389,   394,   401,   406,   411,   417,   422
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TOKEN", "TOKEN", "CHR_TOKEN",
  "TID_TOKEN", "TOKEN_S", "DATA_TOKEN", "H_OTHER", "H_CONTENT_OTHER",
  "SEMICOLON_TOKEN", "TOKEN_AT", "END_LINE", "CRLF", "MSRP_TOKEN", "SP",
  "DASH", "SLASH", "DT_DSLASH", "COLON", "SEMICOLON", "EQ", "CRLFCRLF",
  "H_SUCCES_REPORT", "H_MESSAGE_ID", "H_FAILURE_REPORT", "H_BYTE_RANGE",
  "H_STATUS", "H_TO_PATH", "H_FROM_PATH", "H_CONTENT_TYPE", "H_CONTENT_ID",
  "H_CONTENT_DESCRIPTION", "H_CONTENT_DISPOSITION", "$accept",
  "msrp_message", "request", "response", "MsrpHeaders", "to_path",
  "from_path", "MsrpPath", "MsrpUri", "userinfo", "portField", "sessionId",
  "transport", "uriParameter", "msrp_headers", "msrp_header_list",
  "MsrpHeader_union", "MsrpEndLine", "MsrpContentStuff",
  "MsrpContentStuffbody", "otherMimeHeaders", "otherMimeHeader_list",
  "otherMimeHeader_union", "dispos_params", "dispos_paramlist",
  "disposPram", "genParams", "genPramlist", "genPram", "MsrpRequestStart",
  "MsrpResponseStart", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    38,    39,    40,    41,    42,
      42,    43,    44,    44,    45,    45,    46,    46,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     4,     3,     3,     4,     4,     1,
       3,     8,     0,     1,     0,     2,     0,     2,     1,     0,
       1,     0,     1,     1,     2,     4,     4,     4,     8,     6,
       8,     4,     4,     3,     0,     1,     9,     0,     1,     1,
       2,     4,     4,     5,     4,     0,     1,     1,     2,     4,
       2,     0,     1,     1,     2,     4,     2,     6,     6,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     0,     0,     1,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,     0,    38,    39,     0,    21,     0,     0,     5,     0,
       0,     0,     9,     0,     0,     0,     0,     4,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     6,    22,    23,
       0,     0,     0,     0,    12,     7,     0,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      33,     0,    58,     0,    57,    13,     0,    10,    44,    41,
      42,     0,     0,    46,    47,     0,     8,     0,     0,     0,
       0,     0,     0,    32,     0,    14,    50,    43,    48,     0,
      31,    26,    25,    27,     0,     0,    59,     0,    16,     0,
      51,     0,     0,    15,     0,     0,    49,     0,     0,    52,
      53,     0,    29,     0,    17,    18,    19,    56,     0,    54,
       0,     0,    20,    11,     0,    36,    28,    30,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    25,    31,    32,    76,
     108,   115,   126,   133,    47,    48,    49,    28,    19,    20,
      21,    22,    23,    82,    83,    84,   118,   119,   120,     5,
       6
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int8 yypact[] =
{
       0,    12,    29,   -39,   -39,     2,     2,    24,   -39,    16,
     -10,     3,    -4,    18,    31,    20,    21,    22,    23,    -4,
     -39,     9,    -7,   -39,    25,    -8,    38,    37,   -39,     1,
      26,    -9,   -39,    39,    40,    43,    44,   -39,    33,   -39,
      31,    34,    35,    36,    41,    42,    45,   -39,    -8,   -39,
      46,    49,    -6,    48,    47,   -39,    31,    50,    51,    52,
      53,    59,    -3,    60,    64,    65,    66,    67,    68,   -39,
     -39,    61,   -39,    69,   -39,   -39,    73,   -39,   -39,   -39,
     -39,    74,    70,    53,   -39,    55,   -39,    71,    72,    75,
      76,    62,    77,   -39,    78,    63,    32,   -39,   -39,    83,
     -39,   -39,   -39,   -39,    84,    79,   -39,    87,    80,    90,
      81,    82,    -2,   -39,    91,    85,   -39,    93,    57,    81,
     -39,    95,   -39,    94,   -39,   -39,    92,    86,    96,   -39,
      97,    98,   -39,   -39,   101,   -39,   -39,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,   100,   -39,   -39,    15,    54,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,     8,    88,   -39,   -39,
     -39,   -39,    99,   -39,   -39,    30,   -39,   -39,   -38,   -39,
     -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      15,    41,    26,    15,    52,    55,    53,    56,    72,    27,
      73,    86,   122,    56,   123,     1,    42,    43,    44,    45,
      46,   -37,    16,    17,    18,    16,    17,    18,     7,     8,
      13,     9,    14,    24,    29,    30,    33,    34,    35,    36,
      38,    40,    50,    51,    58,    54,    57,    59,    60,    61,
      63,    64,    65,    71,   109,    62,    69,    66,    67,    75,
      70,    68,    74,    85,    78,    79,    80,    87,    88,    89,
      90,    91,    92,    99,    81,    93,    94,    95,    96,   104,
     128,   129,   112,   107,    97,   100,   101,   110,   111,   102,
     103,   113,   106,   105,   116,   124,   125,   127,   114,   130,
     121,   131,   117,   132,   135,   138,    12,    37,   134,     0,
      77,   136,   137,    98,     0,     0,     0,     0,     0,     0,
       0,    39
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-39))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      10,     9,     6,    10,     3,    14,     5,    16,    14,    13,
      16,    14,    14,    16,    16,    15,    24,    25,    26,    27,
      28,    31,    32,    33,    34,    32,    33,    34,    16,     0,
       6,    29,    16,    30,    16,     4,    16,    16,    16,    16,
      31,    16,     4,     6,     4,    19,     7,     4,     4,    16,
      16,    16,    16,     4,    22,    40,    48,    16,    16,    12,
      14,    16,    14,     4,    14,    14,    14,     7,     4,     4,
       4,     4,     4,    18,    21,    14,     7,     4,     4,    17,
      23,   119,     3,    20,    14,    14,    14,     4,     4,    14,
      14,     4,    14,    16,     4,     4,    11,     4,    18,     4,
      18,     7,    21,    11,     8,     4,     6,    19,    22,    -1,
      56,    14,    14,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    36,    37,    38,    64,    65,    16,     0,    29,
      39,    40,    39,     6,    16,    10,    32,    33,    34,    53,
      54,    55,    56,    57,    30,    41,     6,    13,    52,    16,
       4,    42,    43,    16,    16,    16,    16,    52,    31,    57,
      16,     9,    24,    25,    26,    27,    28,    49,    50,    51,
       4,     6,     3,     5,    19,    14,    16,     7,     4,     4,
       4,    16,    42,    16,    16,    16,    16,    16,    16,    51,
      14,     4,    14,    16,    14,    12,    44,    43,    14,    14,
      14,    21,    58,    59,    60,     4,    14,     7,     4,     4,
       4,     4,     4,    14,     7,     4,     4,    14,    60,    18,
      14,    14,    14,    14,    17,    16,    14,    20,    45,    22,
       4,     4,     3,     4,    18,    46,     4,    21,    61,    62,
      63,    18,    14,    16,     4,    11,    47,     4,    23,    63,
       4,     7,    11,    48,    22,     8,    14,    14,     4
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
      case 3: /* "INT_TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->intnum);};

/* Line 1391 of yacc.c  */
#line 1268 "MSRP_parse_.tab.c"
	break;
      case 4: /* "TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1277 "MSRP_parse_.tab.c"
	break;
      case 5: /* "CHR_TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1286 "MSRP_parse_.tab.c"
	break;
      case 6: /* "TID_TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1295 "MSRP_parse_.tab.c"
	break;
      case 7: /* "TOKEN_S" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1304 "MSRP_parse_.tab.c"
	break;
      case 8: /* "DATA_TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1313 "MSRP_parse_.tab.c"
	break;
      case 9: /* "H_OTHER" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1322 "MSRP_parse_.tab.c"
	break;
      case 10: /* "H_CONTENT_OTHER" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1331 "MSRP_parse_.tab.c"
	break;
      case 11: /* "SEMICOLON_TOKEN" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1340 "MSRP_parse_.tab.c"
	break;
      case 12: /* "TOKEN_AT" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1349 "MSRP_parse_.tab.c"
	break;
      case 39: /* "MsrpHeaders" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpHeaders);};

/* Line 1391 of yacc.c  */
#line 1358 "MSRP_parse_.tab.c"
	break;
      case 40: /* "to_path" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpPath);};

/* Line 1391 of yacc.c  */
#line 1367 "MSRP_parse_.tab.c"
	break;
      case 41: /* "from_path" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpPath);};

/* Line 1391 of yacc.c  */
#line 1376 "MSRP_parse_.tab.c"
	break;
      case 42: /* "MsrpPath" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpPath);};

/* Line 1391 of yacc.c  */
#line 1385 "MSRP_parse_.tab.c"
	break;
      case 43: /* "MsrpUri" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpUri);};

/* Line 1391 of yacc.c  */
#line 1394 "MSRP_parse_.tab.c"
	break;
      case 44: /* "userinfo" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1403 "MSRP_parse_.tab.c"
	break;
      case 45: /* "portField" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1412 "MSRP_parse_.tab.c"
	break;
      case 46: /* "sessionId" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1421 "MSRP_parse_.tab.c"
	break;
      case 47: /* "transport" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1430 "MSRP_parse_.tab.c"
	break;
      case 48: /* "uriParameter" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->charstring);};

/* Line 1391 of yacc.c  */
#line 1439 "MSRP_parse_.tab.c"
	break;
      case 52: /* "MsrpEndLine" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpEndLine);};

/* Line 1391 of yacc.c  */
#line 1448 "MSRP_parse_.tab.c"
	break;
      case 53: /* "MsrpContentStuff" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpContentStuff);};

/* Line 1391 of yacc.c  */
#line 1457 "MSRP_parse_.tab.c"
	break;
      case 54: /* "MsrpContentStuffbody" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpContentStuff);};

/* Line 1391 of yacc.c  */
#line 1466 "MSRP_parse_.tab.c"
	break;
      case 58: /* "dispos_params" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpDispositionParm);};

/* Line 1391 of yacc.c  */
#line 1475 "MSRP_parse_.tab.c"
	break;
      case 59: /* "dispos_paramlist" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpDispositionParm);};

/* Line 1391 of yacc.c  */
#line 1484 "MSRP_parse_.tab.c"
	break;
      case 60: /* "disposPram" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->dispheader);};

/* Line 1391 of yacc.c  */
#line 1493 "MSRP_parse_.tab.c"
	break;
      case 61: /* "genParams" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpGenParamSETOF);};

/* Line 1391 of yacc.c  */
#line 1502 "MSRP_parse_.tab.c"
	break;
      case 62: /* "genPramlist" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpGenParamSETOF);};

/* Line 1391 of yacc.c  */
#line 1511 "MSRP_parse_.tab.c"
	break;
      case 63: /* "genPram" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->genpram);};

/* Line 1391 of yacc.c  */
#line 1520 "MSRP_parse_.tab.c"
	break;
      case 64: /* "MsrpRequestStart" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpRequestStart);};

/* Line 1391 of yacc.c  */
#line 1529 "MSRP_parse_.tab.c"
	break;
      case 65: /* "MsrpResponseStart" */

/* Line 1391 of yacc.c  */
#line 60 "MSRP.y"
	{ delete (yyvaluep->msrpResponseStart);};

/* Line 1391 of yacc.c  */
#line 1538 "MSRP_parse_.tab.c"
	break;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 87 "MSRP.y"
    {YYACCEPT; }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 88 "MSRP.y"
    {YYACCEPT;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 97 "MSRP.y"
    {
                MSRP_parse_parsed_message->request().requestStart()=*(yyvsp[(1) - (4)].msrpRequestStart);
                delete (yyvsp[(1) - (4)].msrpRequestStart);
                MSRP_parse_parsed_message->request().headers()=*(yyvsp[(2) - (4)].msrpHeaders);
                delete (yyvsp[(2) - (4)].msrpHeaders);
                if((yyvsp[(3) - (4)].msrpContentStuff)){
                  MSRP_parse_parsed_message->request().contentStuff()=*(yyvsp[(3) - (4)].msrpContentStuff);
                  delete (yyvsp[(3) - (4)].msrpContentStuff);
                } else {
                  MSRP_parse_parsed_message->request().contentStuff()=OMIT_VALUE;
                }
                MSRP_parse_parsed_message->request().endLine()=*(yyvsp[(4) - (4)].msrpEndLine);
                delete (yyvsp[(4) - (4)].msrpEndLine);
              }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 115 "MSRP.y"
    {
                MSRP_parse_parsed_message->response().responseStart()=*(yyvsp[(1) - (3)].msrpResponseStart);
                delete (yyvsp[(1) - (3)].msrpResponseStart);
                MSRP_parse_parsed_message->response().headers()=*(yyvsp[(2) - (3)].msrpHeaders);
                delete (yyvsp[(2) - (3)].msrpHeaders);
                MSRP_parse_parsed_message->response().endLine()=*(yyvsp[(3) - (3)].msrpEndLine);
                delete (yyvsp[(3) - (3)].msrpEndLine);
              }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 126 "MSRP.y"
    {
                (yyval.msrpHeaders)=new MsrpHeaders(*(yyvsp[(1) - (3)].msrpPath),*(yyvsp[(2) - (3)].msrpPath),*msrpHeader_parsed);
                delete (yyvsp[(1) - (3)].msrpPath);
                delete (yyvsp[(2) - (3)].msrpPath);
                delete msrpHeader_parsed;
                msrpHeader_parsed=NULL;
              }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 134 "MSRP.y"
    { (yyval.msrpPath)=(yyvsp[(3) - (4)].msrpPath); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 136 "MSRP.y"
    { (yyval.msrpPath)=(yyvsp[(3) - (4)].msrpPath); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 138 "MSRP.y"
    {
				       (yyval.msrpPath) = new MsrpPath();
				       (*(yyval.msrpPath))[0] = *(yyvsp[(1) - (1)].msrpUri);
				       delete (yyvsp[(1) - (1)].msrpUri);
             }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 143 "MSRP.y"
    {
           				int fmt_num = (*(yyvsp[(1) - (3)].msrpPath)).size_of();
          				(*(yyvsp[(1) - (3)].msrpPath))[fmt_num] = *(yyvsp[(3) - (3)].msrpUri);
          				delete (yyvsp[(3) - (3)].msrpUri);
          				(yyval.msrpPath) = (yyvsp[(1) - (3)].msrpPath);
             }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 157 "MSRP.y"
    {
               (yyval.msrpUri)=new MsrpUri(*(yyvsp[(1) - (8)].charstring),Authority(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE),OMIT_VALUE,*(yyvsp[(7) - (8)].charstring),OMIT_VALUE);
               delete (yyvsp[(1) - (8)].charstring);
               delete (yyvsp[(7) - (8)].charstring);
               
               if((yyvsp[(3) - (8)].charstring)){
                 (yyval.msrpUri)->authority().userinfo()=*(yyvsp[(3) - (8)].charstring);
                 delete (yyvsp[(3) - (8)].charstring);
               }
               if(ipv6_br){
                 const char* chr=(const char*)*(yyvsp[(4) - (8)].charstring);
                 int chrl=(*(yyvsp[(4) - (8)].charstring)).lengthof();
                 if(chr[0]=='[' && chr[chrl-1]==']'){
                   (yyval.msrpUri)->authority().host()=CHARSTRING(chrl-2,chr+1);
                 } else {
                   (yyval.msrpUri)->authority().host()=*(yyvsp[(4) - (8)].charstring);
                 }
               } else {
                 (yyval.msrpUri)->authority().host()=*(yyvsp[(4) - (8)].charstring);
               }
               delete (yyvsp[(4) - (8)].charstring);
               if((yyvsp[(5) - (8)].charstring)){
                 (yyval.msrpUri)->authority().portField()=*(yyvsp[(5) - (8)].charstring);
                 delete (yyvsp[(5) - (8)].charstring);
               }
               if((yyvsp[(6) - (8)].charstring)){
                 (yyval.msrpUri)->sessionId()=*(yyvsp[(6) - (8)].charstring);
                 delete (yyvsp[(6) - (8)].charstring);
               }
               if((yyvsp[(8) - (8)].charstring)){
                 (yyval.msrpUri)->uriParameter()=*(yyvsp[(8) - (8)].charstring);
                 delete (yyvsp[(8) - (8)].charstring);
               }
             }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 196 "MSRP.y"
    {(yyval.charstring)=NULL;}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 197 "MSRP.y"
    {(yyval.charstring)=(yyvsp[(1) - (1)].charstring);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 199 "MSRP.y"
    {(yyval.charstring)=NULL;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 200 "MSRP.y"
    {(yyval.charstring)=(yyvsp[(2) - (2)].charstring);}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 202 "MSRP.y"
    {(yyval.charstring)=NULL;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 203 "MSRP.y"
    {(yyval.charstring)=(yyvsp[(2) - (2)].charstring);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 205 "MSRP.y"
    {(yyval.charstring)=(yyvsp[(1) - (1)].charstring);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 207 "MSRP.y"
    {(yyval.charstring)=NULL;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 208 "MSRP.y"
    { (yyval.charstring)=(yyvsp[(1) - (1)].charstring); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 211 "MSRP.y"
    { /* empty */ }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 212 "MSRP.y"
    { /* empty */ }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 214 "MSRP.y"
    { /* empty */ }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 215 "MSRP.y"
    { /* empty */ }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 217 "MSRP.y"
    {
               msrpHeader_parsed->messageId()=*(yyvsp[(3) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 221 "MSRP.y"
    {
               if(!strcmp((const char*)*(yyvsp[(3) - (4)].charstring),"yes")){
                 msrpHeader_parsed->successReport()()=MsrpSuccessReportENUM::successYes;
               } else if (!strcmp((const char*)*(yyvsp[(3) - (4)].charstring),"no")) {
                 msrpHeader_parsed->successReport()()=MsrpSuccessReportENUM::successNo;
               } else {
                 TTCN_warning("Invalid Success-Report header value \"%s\"",(const char*)*(yyvsp[(3) - (4)].charstring));
                 error_occured=1;
               }
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 232 "MSRP.y"
    {
               if(!strcmp((const char*)*(yyvsp[(3) - (4)].charstring),"yes")){
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failureYes;
               } else if (!strcmp((const char*)*(yyvsp[(3) - (4)].charstring),"no")) {
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failureNo;
               } else if (!strcmp((const char*)*(yyvsp[(3) - (4)].charstring),"partial")) {
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failurePartial;
               } else {
                 TTCN_warning("Invalid Failure-Report header value \"%s\"",(const char*)*(yyvsp[(3) - (4)].charstring));
                 error_occured=1;
               }
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 245 "MSRP.y"
    {
               msrpHeader_parsed->byteRange()().rangeStart()=INTEGER(*(yyvsp[(3) - (8)].charstring));
               delete (yyvsp[(3) - (8)].charstring);
               msrpHeader_parsed->byteRange()().rangeEnd()=*(yyvsp[(5) - (8)].charstring);
               delete (yyvsp[(5) - (8)].charstring);
               msrpHeader_parsed->byteRange()().total()=*(yyvsp[(7) - (8)].charstring);
               delete (yyvsp[(7) - (8)].charstring);
             }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 253 "MSRP.y"
    {
               msrpHeader_parsed->status()().namespace_()=*(yyvsp[(3) - (6)].charstring);
               delete (yyvsp[(3) - (6)].charstring);
               msrpHeader_parsed->status()().statusCode()=*(yyvsp[(5) - (6)].intnum);
               delete (yyvsp[(5) - (6)].intnum);
               msrpHeader_parsed->status()().textReason()=OMIT_VALUE;
             }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 260 "MSRP.y"
    {
               msrpHeader_parsed->status()().namespace_()=*(yyvsp[(3) - (8)].charstring);
               delete (yyvsp[(3) - (8)].charstring);
               msrpHeader_parsed->status()().statusCode()=*(yyvsp[(5) - (8)].intnum);
               delete (yyvsp[(5) - (8)].intnum);
               msrpHeader_parsed->status()().textReason()=*(yyvsp[(7) - (8)].charstring);
               delete (yyvsp[(7) - (8)].charstring);
             }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 268 "MSRP.y"
    {
               int a=0;
               if(msrpHeader_parsed->extHeader().ispresent()){
                 a=msrpHeader_parsed->extHeader()().size_of();
               }
               msrpHeader_parsed->extHeader()()[a].hname()=*(yyvsp[(1) - (4)].charstring);
               msrpHeader_parsed->extHeader()()[a].hval()=*(yyvsp[(3) - (4)].charstring);
               delete (yyvsp[(1) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 279 "MSRP.y"
    {
               (yyval.msrpEndLine)= new MsrpEndLine(*(yyvsp[(2) - (4)].charstring),*(yyvsp[(3) - (4)].charstring));
               delete (yyvsp[(2) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 284 "MSRP.y"
    {
               (yyval.msrpEndLine)= new MsrpEndLine(*(yyvsp[(1) - (3)].charstring),*(yyvsp[(2) - (3)].charstring));
               delete (yyvsp[(1) - (3)].charstring);
               delete (yyvsp[(2) - (3)].charstring);
             }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 290 "MSRP.y"
    {(yyval.msrpContentStuff)=NULL;}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 291 "MSRP.y"
    {(yyval.msrpContentStuff)=(yyvsp[(1) - (1)].msrpContentStuff);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 295 "MSRP.y"
    {
               (yyval.msrpContentStuff)=new MsrpContentStuff();
               
               if(msrpOtherMimeHeader_parsed){
                 (yyval.msrpContentStuff)->otherMimeHeader()=*msrpOtherMimeHeader_parsed;
                 delete msrpOtherMimeHeader_parsed;
                 msrpOtherMimeHeader_parsed=NULL;
               } else {
                 (yyval.msrpContentStuff)->otherMimeHeader()=OMIT_VALUE;
               }
               
               (yyval.msrpContentStuff)->contentType().typeX()=*(yyvsp[(4) - (9)].charstring);
               delete (yyvsp[(4) - (9)].charstring);
               (yyval.msrpContentStuff)->contentType().subtype()=*(yyvsp[(6) - (9)].charstring);
               delete (yyvsp[(6) - (9)].charstring);
               
               if((yyvsp[(7) - (9)].msrpGenParamSETOF)){
                 (yyval.msrpContentStuff)->contentType().genParam()=*(yyvsp[(7) - (9)].msrpGenParamSETOF);
                 delete (yyvsp[(7) - (9)].msrpGenParamSETOF);
               } else {
                 (yyval.msrpContentStuff)->contentType().genParam()=OMIT_VALUE;
               }
               (yyval.msrpContentStuff)->data()=*(yyvsp[(9) - (9)].charstring);
               delete (yyvsp[(9) - (9)].charstring);
               
             }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 322 "MSRP.y"
    { /* empty */ }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 323 "MSRP.y"
    { /* empty */ }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 325 "MSRP.y"
    { /* empty */ }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 326 "MSRP.y"
    { /* empty */ }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 328 "MSRP.y"
    {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentId()=*(yyvsp[(3) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 333 "MSRP.y"
    {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentDescription()=*(yyvsp[(3) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 338 "MSRP.y"
    {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentDisposition()().dispositionType()=*(yyvsp[(3) - (5)].charstring);
               if((yyvsp[(4) - (5)].msrpDispositionParm)){
                 msrpOtherMimeHeader_parsed->contentDisposition()().dispositionParm()=*(yyvsp[(4) - (5)].msrpDispositionParm);
                 delete (yyvsp[(4) - (5)].msrpDispositionParm);
               } else {
                 msrpOtherMimeHeader_parsed->contentDisposition()().dispositionParm()=OMIT_VALUE;
               }
               delete (yyvsp[(3) - (5)].charstring);
             }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 349 "MSRP.y"
    {
               init_msrpOtherMimeHeader_parsed();
               int a=0;
               if(msrpOtherMimeHeader_parsed->mimeExtensionField().ispresent()){
                 a=msrpOtherMimeHeader_parsed->mimeExtensionField()().size_of();
               }
               msrpOtherMimeHeader_parsed->mimeExtensionField()()[a].hname()=*(yyvsp[(1) - (4)].charstring);
               msrpOtherMimeHeader_parsed->mimeExtensionField()()[a].hval()=*(yyvsp[(3) - (4)].charstring);
               delete (yyvsp[(1) - (4)].charstring);
               delete (yyvsp[(3) - (4)].charstring);
             }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 361 "MSRP.y"
    {(yyval.msrpDispositionParm)=NULL;}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 362 "MSRP.y"
    {(yyval.msrpDispositionParm)=(yyvsp[(1) - (1)].msrpDispositionParm);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 364 "MSRP.y"
    {
				       (yyval.msrpDispositionParm) = new MsrpDispositionParm();
				       (*(yyval.msrpDispositionParm))[0] = *(yyvsp[(1) - (1)].dispheader);
				       delete (yyvsp[(1) - (1)].dispheader);
             }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 369 "MSRP.y"
    {
           				int fmt_num = (*(yyvsp[(1) - (2)].msrpDispositionParm)).size_of();
          				(*(yyvsp[(1) - (2)].msrpDispositionParm))[fmt_num] = *(yyvsp[(2) - (2)].dispheader);
          				delete (yyvsp[(2) - (2)].dispheader);
          				(yyval.msrpDispositionParm) = (yyvsp[(1) - (2)].msrpDispositionParm);
             }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 376 "MSRP.y"
    {
               (yyval.dispheader)=new dispHeader(*(yyvsp[(2) - (4)].charstring),*(yyvsp[(4) - (4)].charstring));
               delete (yyvsp[(2) - (4)].charstring);
               delete (yyvsp[(4) - (4)].charstring);
             }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 381 "MSRP.y"
    {
               (yyval.dispheader)=new dispHeader(*(yyvsp[(2) - (2)].charstring),OMIT_VALUE);
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 386 "MSRP.y"
    {(yyval.msrpGenParamSETOF)=NULL;}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 387 "MSRP.y"
    {(yyval.msrpGenParamSETOF)=(yyvsp[(1) - (1)].msrpGenParamSETOF);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 389 "MSRP.y"
    {
				       (yyval.msrpGenParamSETOF) = new MsrpGenParamSETOF();
				       (*(yyval.msrpGenParamSETOF))[0] = *(yyvsp[(1) - (1)].genpram);
				       delete (yyvsp[(1) - (1)].genpram);
             }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 394 "MSRP.y"
    {
           				int fmt_num = (*(yyvsp[(1) - (2)].msrpGenParamSETOF)).size_of();
          				(*(yyvsp[(1) - (2)].msrpGenParamSETOF))[fmt_num] = *(yyvsp[(2) - (2)].genpram);
          				delete (yyvsp[(2) - (2)].genpram);
          				(yyval.msrpGenParamSETOF) = (yyvsp[(1) - (2)].msrpGenParamSETOF);
             }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 401 "MSRP.y"
    {
               (yyval.genpram)=new MsrpHeaderPAR(*(yyvsp[(2) - (4)].charstring),*(yyvsp[(4) - (4)].charstring));
               delete (yyvsp[(2) - (4)].charstring);
               delete (yyvsp[(4) - (4)].charstring);
             }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 406 "MSRP.y"
    {
               (yyval.genpram)=new MsrpHeaderPAR(*(yyvsp[(2) - (2)].charstring),OMIT_VALUE);
               delete (yyvsp[(2) - (2)].charstring);
             }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 411 "MSRP.y"
    {
                (yyval.msrpRequestStart)=new MsrpRequestStart(*(yyvsp[(3) - (6)].charstring),*(yyvsp[(5) - (6)].charstring));
                delete (yyvsp[(3) - (6)].charstring);
                delete (yyvsp[(5) - (6)].charstring);
              }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 417 "MSRP.y"
    {
                (yyval.msrpResponseStart)=new MsrpResponseStart(*(yyvsp[(3) - (6)].charstring),*(yyvsp[(5) - (6)].intnum),OMIT_VALUE);
                delete (yyvsp[(3) - (6)].charstring);
                delete (yyvsp[(5) - (6)].intnum);
              }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 422 "MSRP.y"
    {
                (yyval.msrpResponseStart)=new MsrpResponseStart(*(yyvsp[(3) - (8)].charstring),*(yyvsp[(5) - (8)].intnum),*(yyvsp[(7) - (8)].charstring));
                delete (yyvsp[(3) - (8)].charstring);
                delete (yyvsp[(5) - (8)].intnum);
                delete (yyvsp[(7) - (8)].charstring);
              }
    break;



/* Line 1806 of yacc.c  */
#line 2475 "MSRP_parse_.tab.c"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 428 "MSRP.y"


/*Additional C code*/


