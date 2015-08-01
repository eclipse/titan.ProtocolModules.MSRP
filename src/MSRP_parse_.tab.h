/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 102 "MSRP_parse_.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE MSRP_parse_lval;


