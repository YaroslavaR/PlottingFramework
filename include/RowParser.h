/*
 * RowParser.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "RowModel.h"
#ifndef INCLUDE_ROWPARSER_H_
#define INCLUDE_ROWPARSER_H_

class RowParser {
public:
	RowModel parse(string input);
	time_t parse_timestamp(string datetime);
	string parse_method(string method);

};



#endif /* INCLUDE_ROWPARSER_H_ */
