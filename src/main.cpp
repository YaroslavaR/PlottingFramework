/*
 * main.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/ParsingController.h"
#include "../include/CalculatingController.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

using namespace std;

int main() {

	ParsingController pc;
	vector<RowModel> rm_vector;
	//cout << 'here';
	rm_vector = pc.parse_input();
	CalculatingController cc;
	//cout << 'here';
	cc.calculate_plotting_data(rm_vector);



//	istringstream ss("2011-Februar-18 23:12:34");
//	    ss.imbue(locale("de_DE.utf-8"));
//	    ss >> get_time(&t, "%Y-%b-%d %H:%M:%S");
//	    if (ss.fail()) {
//	        cout << "Parse failed\n";
//	    } else {
//	        cout << std::put_time(&t, "%c") << '\n';
//	    }

	return 0;
}


