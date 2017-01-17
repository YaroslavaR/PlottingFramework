/*
 * Calculator.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/Calculator.h"
#include <iostream>
#include <time.h>

using namespace std;


map<time_t, string> Calculator::map_time_to_request_type(vector<RowModel> rm) {
	map<time_t, string> date_method;
	vector<time_t> timestamps;
	for (auto it = rm.begin(); it != rm.end(); ++it) {
		date_method.insert(pair<time_t, string>(it->timestamp,it->http_method));
		//cout << it->timestamp << " " << date_method[it->timestamp];
		timestamps.push_back(it->timestamp);
	}
//	for (auto i = timestamps.begin(); i != timestamps.end(); ++i)
//		cout << *i << "brrrr" << endl;
//	time_t diffy = difftime(timestamps[11],timestamps[10]);
//	cout << diffy;
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
