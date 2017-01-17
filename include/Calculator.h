/*
 * Calculator.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_CALCULATOR_H_
#define INCLUDE_CALCULATOR_H_
#include "RowModel.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Calculator {
	int sum;
public:
	map<time_t, string> map_time_to_request_type(vector<RowModel> rm);
};





#endif /* INCLUDE_CALCULATOR_H_ */
