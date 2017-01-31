/*
 * AccessLogRequestsCalculator.h
 *
 *  Created on: Jan 29, 2017
 *      Author: romay
 */

#ifndef INCLUDE_ACCESSLOGREQUESTSCALCULATOR_H_
#define INCLUDE_ACCESSLOGREQUESTSCALCULATOR_H_
#include "Calculator.h"
#include "AccessLogInputModel.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class AccessLogRequestsCalculator : public Calculator<AccessLogInputModel> {
  public:
	virtual map<time_t, vector<int>> calculate_data(vector<AccessLogInputModel> input);
};

#endif /* INCLUDE_ACCESSLOGREQUESTSCALCULATOR_H_ */
