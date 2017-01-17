/*
 * CalculatingController.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/CalculatingController.h"
#include "../include/Calculator.h"

map<string,string> CalculatingController::calculate_plotting_data(vector<RowModel> rm) {
	Calculator calc;
	return calc.map_time_to_request_type(rm);
}




