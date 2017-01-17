/*
 * Calculator.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/Calculator.h"
#include <iostream>

using namespace std;


map<string, string> Calculator::map_time_to_request_type(vector<RowModel> rm) {
	map<string, string> date_method;
	for (auto it = rm.begin(); it != rm.end(); ++it) {
		date_method.insert(pair<string, string>(it->timestamp,it->http_method));
		//cout << it->timestamp << " " << date_method[it->timestamp];
	}
	return date_method;
}

//	int count_get = 0;
//	int count_post = 0;
//	int count_head = 0;
//	int count_options = 0;
//	int count_other = 0;
//	for (auto it = rm_vector.begin() ; it != rm_vector.end(); ++it)
//		if (it->http_method == "\"GET")
//			count_get++;
//		else if (it->http_method == "\"POST")
//			count_post++;
//		else if (it->http_method == "\"HEAD")
//			count_head++;
//		else if (it->http_method == "\"OPTIONS")
//			count_options++;
//		else
//			cout << it->requestor << endl;
//
//			count_other++;
//
//	cout << count_get << endl;
//	cout << count_post << endl;
//	cout << count_head << endl;
//	cout << count_options << endl;
//	cout << count_other;
