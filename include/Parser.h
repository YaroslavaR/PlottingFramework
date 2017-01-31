/*
 * Parser.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#ifndef INCLUDE_PARSER_H_
#define INCLUDE_PARSER_H_

#include <string>

using namespace std;

template <class IM>
class Parser {
public:
	virtual IM parse(string input) = 0;
	virtual ~Parser() {};
};



#endif /* INCLUDE_PARSER_H_ */
