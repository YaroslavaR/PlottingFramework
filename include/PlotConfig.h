/*
 * PlotConfig.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_PLOTCONFIG_H_
#define INCLUDE_PLOTCONFIG_H_

#include <string>
#include <vector>

using namespace std;

class PlotConfig {
public:
	string dat_file;
	string eps_filename;
	string x_format;
	string x_label;
	string y_label;
	string title;
	int number_of_lines;
	vector<string> line_titles;
};



#endif /* INCLUDE_PLOTCONFIG_H_ */
