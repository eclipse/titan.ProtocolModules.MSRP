/******************************************************************************
* Copyright (c) 2000-2018 Ericsson Telecom AB
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
//  File:               MSRP_parse.h
//  Rev:                R8C
//  Prodnr:             CNL 113 467
#ifndef MSRP_parse_parser_H
#define MSRP_parse_parser_H
#include "MSRP_Types.hh"
int MSRP_parse_parse();

int MSRP_parse_lex();

int MSRP_parse_error(const char *s);

#endif

