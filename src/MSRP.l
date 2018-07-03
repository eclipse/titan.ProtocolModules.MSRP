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
//  File:               MSRP.l
//  Rev:                R8A
//  Prodnr:             CNL 113 467


#include "MSRP_parse.h"
#include "MSRP_parse_.tab.h"

using namespace MSRP__Types;

bool ipv6_br;

extern PDU__MSRP* MSRP_parse_parsed_message;
extern MsrpUri* MsrpUri_parse_parsed_message;
extern MsrpOtherMimeHeader* msrpOtherMimeHeader_parsed;
extern MsrpHeader* msrpHeader_parsed;
extern int MSRP_parse_debug;
extern int MSRP_parse_parse();
int chr_pos;
int error_occured;
int MSRP_parse_error(const char *s) {
	if (MSRP_parse_text[0]=='\n') {
      	TTCN_warning("MSRP EncDec:  %s in \"\\n\" at position %d",s,chr_pos);
  }
	else if (MSRP_parse_text[0]=='\r') {
       	TTCN_warning("MSRP EncDec:  %s in \"\\r\" at position %d",s,chr_pos);
  }
 	else {
        TTCN_warning("MSRP EncDec:  %s in \"%s\" -> unexpected token at position %d",s,MSRP_parse_text,chr_pos);
  }
  error_occured=1;
	return 0;
}

%}

%option noyywrap
%option nounput

%x STARTLINE
%x STARTLINE2
%x STARTLINE3
%x MSRPURI
%x MSRPURI2
%x MSRPURI3
%x MSRPURIPAR
%x GENHEADER
%x IDHEADER
%x BRHEADER
%x SHEADER
%x SHEADER2
%x SHEADER3
%x OHEADER
%x CONTHEADER
%x DATAST
%x ENDHEADER


CR      [\r]
LF      [\n]
A       [Aa]
B       [Bb]
C       [Cc]
D       [Dd]
E       [Ee]
F       [Ff]
G       [Gg]
H       [Hh]
I       [Ii]
J       [Jj]
K       [Kk]
L       [Ll]
M       [Mm]
N       [Nn]
O       [Oo]
P       [Pp]
Q       [Qq]
R       [Rr]
S       [Ss]
T       [Tt]
U       [Uu]
V       [Vv]
W       [Ww]
X       [Xx]
Y       [Yy]
Z       [Zz]
DIGIT   [0-9]
COLON   [:]
CRLF    {CR}{LF}


TOKEN   ([[:alnum:]]|[-]|[.]|[!]|[%]|[\*]|[_]|[\+]|[`]|[']|[~])+
HEX     [A-Fa-f]|{DIGIT}
AT      [@]

USERIN  ({USER}|[:])*{AT}
USER    ({UR}|{ESCAPED}|{USER_UR})*
USER_UR [&]|[=]|[\+]|[\$]|[,]|[;]|[\077]|[/] 
UR      [[:alnum:]]|[-]|[_]|[.]|[!]|[~]]|[\*]|[']|[(]|[)]
ESCAPED [%]{HEX}{HEX}

HOST    ({HOSTNAM}|{IPVFOUR}|{IPVSIXR}|{TELURI})
TELURI  ([\+]?)(({TURICHR}|[(]{TURICHR})*)
TURICHR ({HEX}|[)]|[\*]|[-]|[.]|[#])
HOSTNAM (({DOMNLBL}[.])*){TOPLBL}([.]?)
DOMNLBL [[:alnum:]]|([[:alnum:]](([[:alnum:]]|[-])*)[[:alnum:]])
TOPLBL  [[:alpha:]]|([[:alnum:]](([[:alnum:]]|[-])*)[[:alnum:]])
IPVFOUR {DIGIT}{1,3}[.]{DIGIT}{1,3}[.]{DIGIT}{1,3}[.]{DIGIT}{1,3}
IPVSIXR [\133]{IPVSIXA}[\135]
IPVSIXA {HEXPART}(({COLON}{IPVFOUR})?)
HEXPART {HEXSEQ}|{OTHRTWO}
OTHRTWO ({HEXSEQ}({COLON}{2})({HEXSEQ}?))|({COLON}{2}({HEXSEQ}?))
HEXSEQ  {HEXFOUR}(({COLON}{HEXFOUR})*)
HEXFOUR {HEX}{1,4}

TID     [[:alnum:]]([[:alnum:]]|[.]|[-]|[\+]|[%]|[=])+
TID2     [[:alnum:]]([[:alnum:]]|[.]|[-]|[\+]|[%]|[=])*([[:alnum:]]|[.]|[-]|[%]|[=])

%%

<INITIAL>"MSRP" {chr_pos+=MSRP_parse_leng;BEGIN(STARTLINE);return MSRP_TOKEN;}

<STARTLINE>{TID}  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);BEGIN(STARTLINE2);return TID_TOKEN;}

<STARTLINE2>[A-Z]+  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return CHR_TOKEN;}
<STARTLINE2>{DIGIT}+  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.intnum = new INTEGER(MSRP_parse_text);BEGIN(STARTLINE3);return INT_TOKEN;}
<STARTLINE3>[^ \r\n][^\r\n]*  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN_S;}

<INITIAL>{T}{O}[-]{P}{A}{T}{H}{COLON} {chr_pos+=MSRP_parse_leng;BEGIN(MSRPURI);return H_TO_PATH;}
<INITIAL>{F}{R}{O}{M}[-]{P}{A}{T}{H}{COLON} {chr_pos+=MSRP_parse_leng;BEGIN(MSRPURI);return H_FROM_PATH;}

<MSRPURI>{TOKEN} {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<MSRPURI>"://" {chr_pos+=MSRP_parse_leng;BEGIN(MSRPURI3);return DT_DSLASH;}
<MSRPURI2>"/" {chr_pos+=MSRP_parse_leng;BEGIN(MSRPURI);return DT_DSLASH;}

<MSRPURI3>{HOST} {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<MSRPURI3>{USERIN} {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng-1,MSRP_parse_text);return TOKEN_AT;}
<MSRPURI3>"/" {chr_pos+=MSRP_parse_leng;return SLASH;}
<MSRPURI3>":" {chr_pos+=MSRP_parse_leng;return COLON;}
<MSRPURI3>[;]{TOKEN} {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng-1,MSRP_parse_text+1);BEGIN(MSRPURIPAR);return SEMICOLON_TOKEN;}
<MSRPURIPAR>[;]([[:alnum:]]|[-]|[.]|[;]|[=]|[!]|[%]|[\*]|[_]|[\+]|[`]|[']|[~])+ {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng-1,MSRP_parse_text+1);return SEMICOLON_TOKEN;}

<INITIAL>{M}{E}{S}{S}{A}{G}{E}[-]{I}{D}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(IDHEADER);return H_MESSAGE_ID;}
<IDHEADER>{TID}  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}

<INITIAL>{B}{Y}{T}{E}[-]{R}{A}{N}{G}{E}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(BRHEADER);return H_BYTE_RANGE;}
<BRHEADER>({DIGIT}|[\*])+  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<BRHEADER>"/" {chr_pos+=MSRP_parse_leng;return SLASH;}
<BRHEADER>"-" {chr_pos+=MSRP_parse_leng;return DASH;}

<INITIAL>{S}{T}{A}{T}{U}{S}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(SHEADER);return H_STATUS;}
<SHEADER>{TOKEN}  {chr_pos+=MSRP_parse_leng;BEGIN(SHEADER2);MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<SHEADER2>{DIGIT}+  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.intnum = new INTEGER(MSRP_parse_text);BEGIN(SHEADER3);return INT_TOKEN;}
<SHEADER3>[^ \r\n][^\r\n]*  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN_S;}


<INITIAL>{S}{U}{C}{C}{E}{S}{S}[-]{R}{E}{P}{O}{R}{T}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(GENHEADER);return H_SUCCES_REPORT;}
<INITIAL>{F}{A}{I}{L}{U}{R}{E}[-]{R}{E}{P}{O}{R}{T}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(GENHEADER);return H_FAILURE_REPORT;}

<INITIAL>{C}{O}{N}{T}{E}{N}{T}[-]{I}{D}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(GENHEADER);return H_CONTENT_ID;}
<INITIAL>{C}{O}{N}{T}{E}{N}{T}[-]{D}{E}{S}{C}{R}{I}{P}{T}{I}{O}{N}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(GENHEADER);return H_CONTENT_DESCRIPTION;}
<INITIAL>{C}{O}{N}{T}{E}{N}{T}[-]{D}{I}{S}{P}{O}{S}{I}{T}{I}{O}{N}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(GENHEADER);return H_CONTENT_DISPOSITION;}
<INITIAL>{C}{O}{N}{T}{E}{N}{T}[-]{T}{Y}{P}{E}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(CONTHEADER);return H_CONTENT_TYPE;}

<CONTHEADER>{TOKEN}  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<CONTHEADER>"/" {chr_pos+=MSRP_parse_leng;return SLASH;}
<CONTHEADER>"=" {chr_pos+=MSRP_parse_leng;return EQ;}
<CONTHEADER>";" {chr_pos+=MSRP_parse_leng;return SEMICOLON;}
<CONTHEADER>{CRLF}{CRLF} {chr_pos+=MSRP_parse_leng;BEGIN(DATAST);return CRLFCRLF;}

<DATAST>(.|[\r]|[\n])*({CRLF}[-][-][-][-][-][-][-]) {chr_pos+=MSRP_parse_leng;BEGIN(ENDHEADER);MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng-9,MSRP_parse_text);return DATA_TOKEN;}

<INITIAL>[-][-][-][-][-][-][-]  {chr_pos+=MSRP_parse_leng;BEGIN(ENDHEADER);return END_LINE;}

<ENDHEADER>{TID2}  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TID_TOKEN;}
<ENDHEADER>([\+]|[$]|[#])  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}


<GENHEADER>{TOKEN}  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN;}
<GENHEADER>"/" {chr_pos+=MSRP_parse_leng;return SLASH;}
<GENHEADER>"=" {chr_pos+=MSRP_parse_leng;return EQ;}
<GENHEADER>";" {chr_pos+=MSRP_parse_leng;return SEMICOLON;}

<INITIAL>{C}{O}{N}{T}{E}{N}{T}[-]{TOKEN}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(OHEADER);MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return H_CONTENT_OTHER;}
<INITIAL>([a-zA-z]+){TOKEN}{COLON}  {chr_pos+=MSRP_parse_leng;BEGIN(OHEADER);MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng-1,MSRP_parse_text);return H_OTHER;}
<OHEADER>[^ \r\n][^\r\n]*  {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);return TOKEN_S;}


<*>" " {chr_pos+=MSRP_parse_leng; return SP;}
<*>"\n" {chr_pos+=MSRP_parse_leng;BEGIN(INITIAL); return CRLF;}
<*>{CRLF} {chr_pos+=MSRP_parse_leng;BEGIN(INITIAL); return CRLF;}

<*>. {chr_pos+=MSRP_parse_leng;return *MSRP_parse_text;}
%%

// <MSRPURI2>"/" {chr_pos+=MSRP_parse_leng;BEGIN(MSRPURI);return DT_DSLASH;}
// <INITIAL>{TOKEN}[:][/] {chr_pos+=MSRP_parse_leng;MSRP_parse_lval.charstring = new CHARSTRING(MSRP_parse_leng,MSRP_parse_text);BEGIN(MSRPURI2);return TOKEN;}

PDU__MSRP MSRP__Types::f__MSRP__Dec(const CHARSTRING& pl__stream, const BOOLEAN& pl__IPv6__bracketing)
{

  if ((boolean)tsp__MSRP__EncDec__debug && TTCN_Logger::log_this_event(TTCN_DEBUG))  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding message: ");
    pl__stream.log();
    TTCN_Logger::end_event();
    };
	
  PDU__MSRP retv;
  MSRP_parse_parsed_message = &retv;

  chr_pos=0;
  error_occured=0;
  MSRP_parse_debug=0;
  ipv6_br=pl__IPv6__bracketing;
  msrpOtherMimeHeader_parsed=NULL;
  msrpHeader_parsed=new MSRP__Types::MsrpHeader(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE);
  
  MSRP_parse__scan_bytes (pl__stream, pl__stream.lengthof());      
  MSRP_parse_parse();
  MSRP_parse_lex_destroy();
  
  if(error_occured){    
    retv.raw__message()=pl__stream;
  };
  return retv;
}


PDU__MSRP MSRP__Types::f__MSRP__Dec__binary(const OCTETSTRING& pl__stream, OCTETSTRING& pl__content__data, const BOOLEAN& pl__IPv6__bracketing)
{

  if ((boolean)tsp__MSRP__EncDec__debug && TTCN_Logger::log_this_event(TTCN_DEBUG))  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding message: ");
    pl__stream.log();
    TTCN_Logger::end_event();
    };
	
  PDU__MSRP retv;
  MSRP_parse_parsed_message = &retv;

  chr_pos=0;
  error_occured=0;
  MSRP_parse_debug=0;
  ipv6_br=pl__IPv6__bracketing;
  msrpOtherMimeHeader_parsed=NULL;
  msrpHeader_parsed=new MSRP__Types::MsrpHeader(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE);
  
  MSRP_parse__scan_bytes ((const char*)(const unsigned char*)pl__stream, pl__stream.lengthof());      
  MSRP_parse_parse();
  MSRP_parse_lex_destroy();      
      
  if(!error_occured){
    if(retv.ischosen(PDU__MSRP::ALT_request) && retv.request().contentStuff().ispresent()){
      pl__content__data = OCTETSTRING(retv.request().contentStuff()().data().lengthof(),(const unsigned char*)(const char*)retv.request().contentStuff()().data());
      
      bool isOCT = false;
      bool reading = true;
      unsigned char* data = (unsigned char*)(const unsigned char*)pl__content__data;
      unsigned char* oct = data;
      int len = pl__content__data.lengthof();
      while(!isOCT and reading){
        if((int)oct[0] == 0 or (int)oct[0] > 127) isOCT = true;
        if((oct - data) > len - 2) reading = false;
        oct ++;
      }; 
     
      if(isOCT)retv.request().contentStuff()().data()="";
    } else {
      pl__content__data = OCTETSTRING(0,(const unsigned char*)"");
    }
  } else {
    retv.raw__message()=(const char*)(const unsigned char*)pl__stream;
  };
  return retv;
}
/*
MsrpUri MSRP__Types::f__MsrpUri__Dec_Flex(const CHARSTRING& pl__stream, const BOOLEAN& pl__IPv6__bracketing)
{

  if ((boolean)tsp__MSRP__EncDec__debug && TTCN_Logger::log_this_event(TTCN_DEBUG))  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding message: ");
    pl__stream.log();
    TTCN_Logger::end_event();
    };
	
  MsrpUri retv;
  MsrpUri_parse_parsed_message = &retv;

	chr_pos=0;
	error_occured=0;
	MSRP_parse_debug=0;
	ipv6_br=pl__IPv6__bracketing;
	msrpOtherMimeHeader_parsed=NULL;
	msrpHeader_parsed=new MSRP__Types::MsrpHeader(OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE,OMIT_VALUE);
	
	MSRP_parse__scan_bytes ((const char*)pl__stream, pl__stream.lengthof());
	MSRP_parse_parse();
	MSRP_parse_lex_destroy();

  return retv;
}*/

