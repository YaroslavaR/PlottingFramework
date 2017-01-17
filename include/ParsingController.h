/*
 * ParsingController.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_PARSINGCONTROLLER_H_
#define INCLUDE_PARSINGCONTROLLER_H_
#include <vector>
#include "RowModel.h"

class ParsingController {
public:
	vector<RowModel> parse_input();
};



#endif /* INCLUDE_PARSINGCONTROLLER_H_ */
