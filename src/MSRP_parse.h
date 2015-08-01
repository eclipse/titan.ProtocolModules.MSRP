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
//  File:               MSRP_parse.h
//  Rev:                R8A
//  Prodnr:             CNL 113 467
#ifndef MSRP_parse_parser_H
#define MSRP_parse_parser_H
#include "MSRP_Types.hh"
int MSRP_parse_parse();

int MSRP_parse_lex();

int MSRP_parse_error(const char *s);

#endif

