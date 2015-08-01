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
//  File:               MSRP_EncDec.cc
//  Rev:                R8A
//  Prodnr:             CNL 113 467
//  Reference:          
 
#include "MSRP_Types.hh"
#include "memory.h"
#include <string.h>

namespace MSRP__Types {

CHARSTRING f__MsrpUri__Enc(const MsrpUri& pl__msg, const BOOLEAN& pl__IPv6__bracketing)
{
	TTCN_Buffer bb;
  MsrpUri *cp=NULL;
  const char* chr=pl__msg.authority().host()();
  if(strchr(chr,':')){
    cp= new MsrpUri(pl__msg);
    cp->authority().host()= "[" + pl__msg.authority().host()() + "]";
    cp->encode(MsrpUri_descr_ ,bb, TTCN_EncDec::CT_TEXT);
    delete cp;
  } else {
    pl__msg.encode(MsrpUri_descr_ ,bb, TTCN_EncDec::CT_TEXT);
  }

	return CHARSTRING (bb.get_len(),(char *)bb.get_data());

}

CHARSTRING f__MSRP__Enc(const PDU__MSRP& pl__msg, const BOOLEAN& pl__IPv6__bracketing)
{
	
  if(pl__msg.ischosen(PDU__MSRP::ALT_raw__message)){
    return pl__msg.raw__message();
  }
	
  TTCN_Buffer bb;
  PDU__MSRP *cp=NULL;
  
  if(pl__IPv6__bracketing){
    const MsrpHeaders *mh;
    MsrpHeaders *mh2=NULL;
    if(pl__msg.ischosen(PDU__MSRP::ALT_request)){
      mh=&(pl__msg.request().headers());
    } else {
      mh=&(pl__msg.response().headers());
    }


    for(int a=0;a<mh->toPath().size_of();a++){
      if(mh->toPath()[a].authority().host().ispresent()){
        const char* chr=mh->toPath()[a].authority().host()();
        if(strchr(chr,':')){
          if(cp==NULL){
            cp= new PDU__MSRP(pl__msg);
            if(pl__msg.ischosen(PDU__MSRP::ALT_request)){
              mh2=&(cp->request().headers());
            } else {
              mh2=&(cp->response().headers());
            }
          }
          mh2->toPath()[a].authority().host()= "[" + mh->toPath()[a].authority().host()() + "]"; ;
        }
      }
    }
    for(int a=0;a<mh->fromPath().size_of();a++){
      if(mh->fromPath()[a].authority().host().ispresent()){
        const char* chr=mh->fromPath()[a].authority().host()();
        if(strchr(chr,':')){
          if(cp==NULL){
            cp= new PDU__MSRP(pl__msg);
            if(pl__msg.ischosen(PDU__MSRP::ALT_request)){
              mh2=&(cp->request().headers());
            } else {
              mh2=&(cp->response().headers());
            }
          }
          mh2->fromPath()[a].authority().host()= "[" + mh->fromPath()[a].authority().host()() + "]"; ;
        }
      }
    }
  }
  
  if(cp){
    cp->encode(PDU__MSRP_descr_ ,bb, TTCN_EncDec::CT_TEXT);
    delete cp;
  } else {
    pl__msg.encode(PDU__MSRP_descr_ ,bb, TTCN_EncDec::CT_TEXT);
  }

  return CHARSTRING (bb.get_len(),(char *)bb.get_data());
}


OCTETSTRING f__MSRP__Enc__binary(const PDU__MSRP& pl__msg, const OCTETSTRING& pl__content__data, const BOOLEAN& pl__IPv6__bracketing)
{
  CHARSTRING str;	
  if(!pl__msg.ischosen(PDU__MSRP::ALT_request)){
    str = f__MSRP__Enc(pl__msg,pl__IPv6__bracketing);
    return OCTETSTRING(str.lengthof(),(const unsigned char*)(const char*)str);
  }
  else {
    if(pl__msg.request().contentStuff().ispresent()){
      PDU__MSRP temp = pl__msg;
      int id_length = temp.request().requestStart().transactId().lengthof();
      
      temp.request().contentStuff()().data() = "";
      str = f__MSRP__Enc(temp,pl__IPv6__bracketing);      
      OCTETSTRING msg = OCTETSTRING(str.lengthof(),(const unsigned char*)(const char*)str);
      int data_pos = msg.lengthof() - id_length - 12; /*12: 2*<cr>+"-------"+continuationFlag*/

      return substr(msg, 0, data_pos) + pl__content__data + substr(msg, data_pos, msg.lengthof() - data_pos);
    } else {
      str = f__MSRP__Enc(pl__msg,pl__IPv6__bracketing);
      return OCTETSTRING(str.lengthof(),(const unsigned char*)(const char*)str);
    }
  }	
}


PDU__MSRP f__MSRP__Dec__TEXT(const CHARSTRING& pl__stream, const BOOLEAN& pl__IPv6__bracketing)
{

  if ((boolean)tsp__MSRP__EncDec__debug && TTCN_Logger::log_this_event(TTCN_DEBUG))  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding message: ");
    pl__stream.log();
    TTCN_Logger::end_event();
    };
	
  PDU__MSRP retv;
  TTCN_Buffer bb(pl__stream);
  
  
  TTCN_EncDec::error_behavior_t	eb=TTCN_EncDec::get_error_behavior(TTCN_EncDec::ET_LOG_MATCHING);

  if((boolean)tsp__MSRP__EncDec__debug){
    if (TTCN_Logger::log_this_event(TTCN_DEBUG))  {
      TTCN_Logger::begin_event(TTCN_DEBUG);
      TTCN_Logger::log_event("Decode buffer: /n");
      bb.log();
      TTCN_Logger::end_event();
      }
    TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,TTCN_EncDec::EB_WARNING);
  } else {
    TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,TTCN_EncDec::EB_IGNORE);
  }
    
  retv.decode(PDU__MSRP_descr_, bb, TTCN_EncDec::CT_TEXT);
  if(retv.ischosen(PDU__MSRP::ALT_request))
      if(retv.request().contentStuff().ispresent()){
        bb.set_pos(bb.get_pos()-7);
        bb.cut();
        MsrpEndLine endl;
        endl.decode(MsrpEndLine_descr_, bb, TTCN_EncDec::CT_TEXT);
        retv.request().endLine()=endl;
      }
  
  TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,eb);
  if(pl__IPv6__bracketing){
  
    MsrpHeaders *mh;
    if(retv.ischosen(PDU__MSRP::ALT_request)){
      mh=&(retv.request().headers());
    } else {
      mh=&(retv.response().headers());
    }

    for(int a=0;a<mh->toPath().size_of();a++){
      if(mh->toPath()[a].authority().host().ispresent()){
        const char* chr=mh->toPath()[a].authority().host()();
        int chrl=mh->toPath()[a].authority().host()().lengthof();
        if(chr[0]=='[' && chr[chrl-1]==']'){
          CHARSTRING chr2(chrl-2,chr+1);
          mh->toPath()[a].authority().host()=chr2;
        }
      }
    }
    for(int a=0;a<mh->fromPath().size_of();a++){
      if(mh->fromPath()[a].authority().host().ispresent()){
        const char* chr=mh->fromPath()[a].authority().host()();
        int chrl=mh->fromPath()[a].authority().host()().lengthof();
        if(chr[0]=='[' && chr[chrl-1]==']'){
          CHARSTRING chr2(chrl-2,chr+1);
          mh->fromPath()[a].authority().host()=chr2;
        }
      }
    }
  }
  return retv;
}

MsrpUri f__MsrpUri__Dec(const CHARSTRING& pl__stream, const BOOLEAN& pl__IPv6__bracketing)
{

  if ((boolean)tsp__MSRP__EncDec__debug && TTCN_Logger::log_this_event(TTCN_DEBUG))  {
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding message: ");
    pl__stream.log();
    TTCN_Logger::end_event();
    };
	
  MsrpUri retv;
  TTCN_Buffer bb(pl__stream);
  
  
  TTCN_EncDec::error_behavior_t	eb=TTCN_EncDec::get_error_behavior(TTCN_EncDec::ET_LOG_MATCHING);

  if((boolean)tsp__MSRP__EncDec__debug){
    if (TTCN_Logger::log_this_event(TTCN_DEBUG))  {
      TTCN_Logger::begin_event(TTCN_DEBUG);
      TTCN_Logger::log_event("Decode buffer: /n");
      bb.log();
      TTCN_Logger::end_event();
      }
    TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,TTCN_EncDec::EB_WARNING);
  } else {
    TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,TTCN_EncDec::EB_IGNORE);
  }
    
  retv.decode(MsrpUri_descr_, bb, TTCN_EncDec::CT_TEXT);
  TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_LOG_MATCHING,eb);
  if(pl__IPv6__bracketing){
  
        const char* chr=retv.authority().host()();
        int chrl=retv.authority().host()().lengthof();
        if(chr[0]=='[' && chr[chrl-1]==']'){
          CHARSTRING chr2(chrl-2,chr+1);
          retv.authority().host()=chr2;
        }
  }
  return retv;
}
INTEGER f__MSRPmsg__MessageLength(const OCTETSTRING& pl__stream){
  int len = -1;
  int pos = 0;
  bool reading = true;  
  int stream_len = pl__stream.lengthof();
  const unsigned char* stream = pl__stream;
  unsigned char* pt;
  unsigned char* pt2;
  
  CHARSTRING line = "-------";
  CHARSTRING rn = "\r\n";
  OCTETSTRING msg;
  int endLine_len;

  /*Searching MSRP*/ 
  pt = (unsigned char*)memmem(stream,stream_len, "MSRP ",5);  
  if(pt != NULL){
    pos = pt - stream;
    pos += 5;    
    pt += 5;

    /*Searching Transaction ID*/  
    pt2 = (unsigned char*)memchr(pt, ' ', stream_len - pos);    
    if(pt2 != NULL){
      line += CHARSTRING(pt2 - pt, (const char*)pt);
      pos += pt2 - pt;
      endLine_len = pt2 - pt + 7;
      
      pt = pt2;  
    } else {
      return -1;
    };

    /*Searching endLine*/;       
    while(reading){
      pt2 = (unsigned char*)memchr(pt, '-', stream_len - pos - endLine_len - 1);
      if(pt2 != NULL){
        if(memcmp(pt2, (const char*)line, endLine_len) == 0){
          /*checking \r\n*/
          if(memcmp(pt2 + endLine_len + 1, (const unsigned char*)(const char*)rn, 1) == 0){
              pos += pt2 - pt;
              return pos + endLine_len + 3;
            };  
        } else {
          pos += pt2 - pt + 1;
        }
      } else return -1;
      pt = pt2 + 1;
      if(pos >= stream_len) reading = false;
    };
  };
  return len;
}

}//namespace
