/*
 * AccessLogParser.h
 *
 *  Created on: Jan 28, 2017
 *      Author: romay
 */
#ifndef INCLUDE_ACCESSLOGPARSER_H_
#define INCLUDE_ACCESSLOGPARSER_H_

#include "Parser.h"
#include "AccessLogInputModel.h"

class AccessLogParser : public Parser<AccessLogInputModel> {
public:
	virtual AccessLogInputModel parse(string input);
	time_t parse_timestamp(string datetime);
	string parse_method(string method);
};



#endif /* INCLUDE_ACCESSLOGPARSER_H_ */
