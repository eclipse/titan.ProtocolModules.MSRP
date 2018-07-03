%{
/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
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

%}
%union {
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
}

%destructor { delete $$;} <*>

%token <intnum> INT_TOKEN
%token <charstring> TOKEN CHR_TOKEN TID_TOKEN TOKEN_S DATA_TOKEN H_OTHER H_CONTENT_OTHER SEMICOLON_TOKEN TOKEN_AT
%token END_LINE CRLF MSRP_TOKEN SP DASH SLASH DT_DSLASH COLON SEMICOLON EQ CRLFCRLF
%token H_SUCCES_REPORT H_MESSAGE_ID H_FAILURE_REPORT H_BYTE_RANGE H_STATUS H_TO_PATH H_FROM_PATH H_CONTENT_TYPE
%token H_CONTENT_ID H_CONTENT_DESCRIPTION H_CONTENT_DISPOSITION

%type <msrpResponseStart>  MsrpResponseStart
%type <msrpRequestStart>  MsrpRequestStart
%type <genpram> genPram
%type <msrpGenParamSETOF> genParams genPramlist
%type <dispheader> disposPram
%type <msrpDispositionParm> dispos_paramlist dispos_params
%type <msrpContentStuff> MsrpContentStuffbody MsrpContentStuff
%type <msrpEndLine> MsrpEndLine
%type <msrpUri> MsrpUri
%type <msrpPath> MsrpPath to_path from_path
%type <msrpHeaders> MsrpHeaders

%type <charstring> uriParameter transport sessionId userinfo
%type <charstring> portField

%start msrp_message 

%%

msrp_message: request {YYACCEPT; }
           |  response {YYACCEPT;}
//           |  msrp_uri{YYACCEPT;}
           ;

// msrp_uri:  MsrpUri { *MsrpUri_parse_parsed_message=*$1; delete $1;};

request:      MsrpRequestStart
              MsrpHeaders
              MsrpContentStuff
              MsrpEndLine {
                MSRP_parse_parsed_message->request().requestStart()=*$1;
                delete $1;
                MSRP_parse_parsed_message->request().headers()=*$2;
                delete $2;
                if($3){
                  MSRP_parse_parsed_message->request().contentStuff()=*$3;
                  delete $3;
                } else {
                  MSRP_parse_parsed_message->request().contentStuff()=OMIT_VALUE;
                }
                MSRP_parse_parsed_message->request().endLine()=*$4;
                delete $4;
              };


response:     MsrpResponseStart
              MsrpHeaders
              MsrpEndLine {
                MSRP_parse_parsed_message->response().responseStart()=*$1;
                delete $1;
                MSRP_parse_parsed_message->response().headers()=*$2;
                delete $2;
                MSRP_parse_parsed_message->response().endLine()=*$3;
                delete $3;
              };

MsrpHeaders:  to_path
              from_path
              msrp_headers {
                $$=new MsrpHeaders(*$1,*$2,*msrpHeader_parsed);
                delete $1;
                delete $2;
                delete msrpHeader_parsed;
                msrpHeader_parsed=NULL;
              };

to_path:     H_TO_PATH SP MsrpPath CRLF { $$=$3; };

from_path:   H_FROM_PATH SP MsrpPath CRLF { $$=$3; };  

MsrpPath:    MsrpUri {
				       $$ = new MsrpPath();
				       (*$$)[0] = *$1;
				       delete $1;
             }
           | MsrpPath SP MsrpUri {
           				int fmt_num = (*$1).size_of();
          				(*$1)[fmt_num] = *$3;
          				delete $3;
          				$$ = $1;
             };

MsrpUri:     TOKEN
             DT_DSLASH
             userinfo
             TOKEN
             portField
             sessionId
             transport
             uriParameter {
               $$=new MsrpUri(*$1,Authority(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE),OMIT_VALUE,*$7,OMIT_VALUE);
               delete $1;
               delete $7;
               
               if($3){
                 $$->authority().userinfo()=*$3;
                 delete $3;
               }
               if(ipv6_br){
                 const char* chr=(const char*)*$4;
                 int chrl=(*$4).lengthof();
                 if(chr[0]=='[' && chr[chrl-1]==']'){
                   $$->authority().host()=CHARSTRING(chrl-2,chr+1);
                 } else {
                   $$->authority().host()=*$4;
                 }
               } else {
                 $$->authority().host()=*$4;
               }
               delete $4;
               if($5){
                 $$->authority().portField()=*$5;
                 delete $5;
               }
               if($6){
                 $$->sessionId()=*$6;
                 delete $6;
               }
               if($8){
                 $$->uriParameter()=*$8;
                 delete $8;
               }
             };

/*authority:   userinfo
             TOKEN
             portField {};
*/
userinfo:    /* empty */ {$$=NULL;}
           | TOKEN_AT {$$=$1;};

portField:    /* empty */ {$$=NULL;} 
           | COLON TOKEN {$$=$2;};

sessionId:    /* empty */ {$$=NULL;}
           | SLASH TOKEN {$$=$2;};

transport:    SEMICOLON_TOKEN {$$=$1;};

uriParameter:    /* empty */ {$$=NULL;}
           | SEMICOLON_TOKEN { $$=$1; };


msrp_headers:  /* empty */ { /* empty */ }
           | msrp_header_list { /* empty */ };

msrp_header_list:  MsrpHeader_union { /* empty */ }
           | msrp_header_list MsrpHeader_union { /* empty */ };

MsrpHeader_union: H_MESSAGE_ID SP TOKEN CRLF {
               msrpHeader_parsed->messageId()=*$3;
               delete $3;
             }
           | H_SUCCES_REPORT SP TOKEN CRLF {
               if(!strcmp((const char*)*$3,"yes")){
                 msrpHeader_parsed->successReport()()=MsrpSuccessReportENUM::successYes;
               } else if (!strcmp((const char*)*$3,"no")) {
                 msrpHeader_parsed->successReport()()=MsrpSuccessReportENUM::successNo;
               } else {
                 TTCN_warning("Invalid Success-Report header value \"%s\"",(const char*)*$3);
                 error_occured=1;
               }
               delete $3;
             }
           | H_FAILURE_REPORT SP TOKEN CRLF {
               if(!strcmp((const char*)*$3,"yes")){
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failureYes;
               } else if (!strcmp((const char*)*$3,"no")) {
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failureNo;
               } else if (!strcmp((const char*)*$3,"partial")) {
                 msrpHeader_parsed->failureReport()()=MsrpFailureReportENUM::failurePartial;
               } else {
                 TTCN_warning("Invalid Failure-Report header value \"%s\"",(const char*)*$3);
                 error_occured=1;
               }
               delete $3;
             }
           | H_BYTE_RANGE SP TOKEN DASH TOKEN SLASH TOKEN CRLF {
               msrpHeader_parsed->byteRange()().rangeStart()=INTEGER(*$3);
               delete $3;
               msrpHeader_parsed->byteRange()().rangeEnd()=*$5;
               delete $5;
               msrpHeader_parsed->byteRange()().total()=*$7;
               delete $7;
             }
           | H_STATUS SP TOKEN SP INT_TOKEN CRLF {
               msrpHeader_parsed->status()().namespace_()=*$3;
               delete $3;
               msrpHeader_parsed->status()().statusCode()=*$5;
               delete $5;
               msrpHeader_parsed->status()().textReason()=OMIT_VALUE;
             }
           | H_STATUS SP TOKEN SP INT_TOKEN SP TOKEN_S CRLF {
               msrpHeader_parsed->status()().namespace_()=*$3;
               delete $3;
               msrpHeader_parsed->status()().statusCode()=*$5;
               delete $5;
               msrpHeader_parsed->status()().textReason()=*$7;
               delete $7;
             }
           | H_OTHER SP TOKEN_S CRLF {
               int a=0;
               if(msrpHeader_parsed->extHeader().ispresent()){
                 a=msrpHeader_parsed->extHeader()().size_of();
               }
               msrpHeader_parsed->extHeader()()[a].hname()=*$1;
               msrpHeader_parsed->extHeader()()[a].hval()=*$3;
               delete $1;
               delete $3;
             };

MsrpEndLine:  END_LINE TID_TOKEN TOKEN CRLF {
               $$= new MsrpEndLine(*$2,*$3);
               delete $2;
               delete $3;
             }
           | TID_TOKEN TOKEN CRLF {
               $$= new MsrpEndLine(*$1,*$2);
               delete $1;
               delete $2;
             };
              
MsrpContentStuff: /* empty */ {$$=NULL;}
           | MsrpContentStuffbody {$$=$1;};

MsrpContentStuffbody: otherMimeHeaders
             H_CONTENT_TYPE SP TOKEN SLASH TOKEN genParams CRLFCRLF
             DATA_TOKEN {
               $$=new MsrpContentStuff();
               
               if(msrpOtherMimeHeader_parsed){
                 $$->otherMimeHeader()=*msrpOtherMimeHeader_parsed;
                 delete msrpOtherMimeHeader_parsed;
                 msrpOtherMimeHeader_parsed=NULL;
               } else {
                 $$->otherMimeHeader()=OMIT_VALUE;
               }
               
               $$->contentType().typeX()=*$4;
               delete $4;
               $$->contentType().subtype()=*$6;
               delete $6;
               
               if($7){
                 $$->contentType().genParam()=*$7;
                 delete $7;
               } else {
                 $$->contentType().genParam()=OMIT_VALUE;
               }
               $$->data()=*$9;
               delete $9;
               
             };

otherMimeHeaders: /* empty */ { /* empty */ }
           | otherMimeHeader_list { /* empty */ };

otherMimeHeader_list:  otherMimeHeader_union { /* empty */ }
           | otherMimeHeader_list otherMimeHeader_union { /* empty */ };

otherMimeHeader_union: H_CONTENT_ID SP TOKEN CRLF {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentId()=*$3;
               delete $3;
             }
           | H_CONTENT_DESCRIPTION SP TOKEN CRLF {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentDescription()=*$3;
               delete $3;
             }
           | H_CONTENT_DISPOSITION SP TOKEN dispos_params CRLF {
               init_msrpOtherMimeHeader_parsed();
               msrpOtherMimeHeader_parsed->contentDisposition()().dispositionType()=*$3;
               if($4){
                 msrpOtherMimeHeader_parsed->contentDisposition()().dispositionParm()=*$4;
                 delete $4;
               } else {
                 msrpOtherMimeHeader_parsed->contentDisposition()().dispositionParm()=OMIT_VALUE;
               }
               delete $3;
             }
           | H_CONTENT_OTHER SP TOKEN_S CRLF {
               init_msrpOtherMimeHeader_parsed();
               int a=0;
               if(msrpOtherMimeHeader_parsed->mimeExtensionField().ispresent()){
                 a=msrpOtherMimeHeader_parsed->mimeExtensionField()().size_of();
               }
               msrpOtherMimeHeader_parsed->mimeExtensionField()()[a].hname()=*$1;
               msrpOtherMimeHeader_parsed->mimeExtensionField()()[a].hval()=*$3;
               delete $1;
               delete $3;
             };

dispos_params: /* empty */ {$$=NULL;}
           | dispos_paramlist {$$=$1;};

dispos_paramlist:   disposPram {
				       $$ = new MsrpDispositionParm();
				       (*$$)[0] = *$1;
				       delete $1;
             }
           | dispos_paramlist disposPram {
           				int fmt_num = (*$1).size_of();
          				(*$1)[fmt_num] = *$2;
          				delete $2;
          				$$ = $1;
             };

disposPram:     SEMICOLON TOKEN EQ TOKEN {
               $$=new dispHeader(*$2,*$4);
               delete $2;
               delete $4;
             }
           | SEMICOLON TOKEN {
               $$=new dispHeader(*$2,OMIT_VALUE);
               delete $2;
             };

genParams:    /* empty */ {$$=NULL;}
           | genPramlist {$$=$1;};

genPramlist:   genPram {
				       $$ = new MsrpGenParamSETOF();
				       (*$$)[0] = *$1;
				       delete $1;
             }
           | genPramlist genPram {
           				int fmt_num = (*$1).size_of();
          				(*$1)[fmt_num] = *$2;
          				delete $2;
          				$$ = $1;
             };

genPram:     SEMICOLON TOKEN EQ TOKEN {
               $$=new MsrpHeaderPAR(*$2,*$4);
               delete $2;
               delete $4;
             }
           | SEMICOLON TOKEN {
               $$=new MsrpHeaderPAR(*$2,OMIT_VALUE);
               delete $2;
             };

MsrpRequestStart: MSRP_TOKEN SP TID_TOKEN SP CHR_TOKEN CRLF {
                $$=new MsrpRequestStart(*$3,*$5);
                delete $3;
                delete $5;
              };

MsrpResponseStart: MSRP_TOKEN SP TID_TOKEN SP INT_TOKEN CRLF {
                $$=new MsrpResponseStart(*$3,*$5,OMIT_VALUE);
                delete $3;
                delete $5;
              }
           |  MSRP_TOKEN SP TID_TOKEN SP INT_TOKEN SP TOKEN_S CRLF {
                $$=new MsrpResponseStart(*$3,*$5,*$7);
                delete $3;
                delete $5;
                delete $7;
              };
%%

/*Additional C code*/

