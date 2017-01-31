/*
 * AccessLogResponseSizeCalculator.h
 *
 *  Created on: Jan 29, 2017
 *      Author: romay
 */

#ifndef INCLUDE_ACCESSLOGRESPONSESIZECALCULATOR_H_
#define INCLUDE_ACCESSLOGRESPONSESIZECALCULATOR_H_
#include "Calculator.h"
#include "AccessLogInputModel.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class AccessLogResponseSizeCalculator : public Calculator<AccessLogInputModel> {
  public:
	virtual map<time_t, vector<int>> calculate_data(vector<AccessLogInputModel> input);
};

#endif /* INCLUDE_ACCESSLOGRESPONSESIZECALCULATOR_H_ */
