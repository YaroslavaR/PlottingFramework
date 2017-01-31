/*
 * CalculatingController.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_CALCULATINGCONTROLLER_H_
#define INCLUDE_CALCULATINGCONTROLLER_H_
#include "Calculator.h"
#include <map>
#include <vector>
#include <fstream>

using namespace std;

template <class IM, class CALC>
class CalculatingController {
public:
	void calculate_plotting_data(vector<IM> input, string output_filename);

};

template <class IM, class CALC>
void CalculatingController<IM, CALC>::calculate_plotting_data(vector<IM> input, string output_filename) {
	CALC calc;
	map<time_t, vector<int>> calculated_data = calc.calculate_data(input);

	ofstream output_file;
	output_file.open(output_filename);
	for(auto it = calculated_data.begin(); it != calculated_data.end(); it++) {
		output_file << it->first;
		for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
			output_file << ' ' << *iter;
		}
		output_file << '\n';
	}

	output_file.close();
}

#endif /* INCLUDE_CALCULATINGCONTROLLER_H_ */
