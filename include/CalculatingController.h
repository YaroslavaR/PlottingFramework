/*
 * CalculatingController.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_CALCULATINGCONTROLLER_H_
#define INCLUDE_CALCULATINGCONTROLLER_H_
#include "RowModel.h"
#include <map>
#include <vector>

using namespace std;

class CalculatingController {
public:
	//template <typename T>
	map<string,string> calculate_plotting_data(vector<RowModel> rm);

};



#endif /* INCLUDE_CALCULATINGCONTROLLER_H_ */
