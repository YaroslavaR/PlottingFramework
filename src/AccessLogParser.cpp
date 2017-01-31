/*
 * AccessLogParser.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: romay
 */
#include "../include/AccessLogParser.h"
#include "../include/AccessLogInputModel.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <iomanip>
#include <time.h>


using namespace std;

AccessLogInputModel AccessLogParser::parse(string input) {
	istringstream iss(input);
	vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
	AccessLogInputModel input_model;

	input_model.requestor = tokens[0];
	input_model.http_method = parse_method(tokens[5]);
	input_model.timestamp = parse_timestamp(tokens[3]);
	input_model.url = tokens[6];
	input_model.response_http_code = tokens[8];
	input_model.response_size = tokens[9];
	return input_model;
}

time_t AccessLogParser::parse_timestamp(string datetime) {

	tm t;

	time_t rawtime;
	tm timeinfo;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	string timestamp = datetime;
	timestamp.erase (timestamp.begin());
		istringstream ss(timestamp);
		ss.imbue(std::locale("en_US.utf-8"));
		ss >> get_time(&t, "%d/%b/%Y:%H:%M:%S");
		if (ss.fail()) {
			cerr << "Parse failed\n";
		} else {
			stringstream ssTp;
			ssTp << put_time(&t, "%Y");
			ssTp >> year;
			ssTp.clear();
			ssTp << put_time(&t, "%m");
			ssTp >> month;
			ssTp.clear();
			ssTp << put_time(&t, "%d");
			ssTp >> day;
			ssTp.clear();
			ssTp << put_time(&t, "%H");
			ssTp >> hour;
			ssTp.clear();
			ssTp << put_time(&t, "%M");
			ssTp >> minute;
			ssTp.clear();
			ssTp << put_time(&t, "%S");
			ssTp >> second;
			timestamp = ssTp.str();
		}

		timeinfo.tm_year = year-1900;
		timeinfo.tm_mon = month-1;
		timeinfo.tm_mday = day;
		timeinfo.tm_hour = hour;
		timeinfo.tm_min = minute;
		timeinfo.tm_sec = second;

		rawtime = mktime ( &timeinfo );
	return rawtime;
}

string AccessLogParser::parse_method(string method) {
	method.erase(method.begin());
	return method;
}



