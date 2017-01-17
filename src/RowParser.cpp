/*
 * RowParser.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/RowParser.h"
#include "../include/RowModel.h"
#include <iostream>
#include <vector>
//#include <stdlib.h>
#include <sstream>
#include <locale>
#include <iomanip>
#include <time.h>


using namespace std;

RowModel RowParser::parse(string input) {

	vector<string> result;
	//cout << result.max_size();
	//string input="64.242.88.10 - - [07/Mar/2004:16:06:51 -0800] \"GET /twiki/bin/rdiff/TWiki/NewUserTemplate?rev1=1.3&rev2=1.2 HTTP/1.1\" 200 4523";
	RowModel rm;

	stringstream  data(input);

	    string line;
	    while(getline(data,line,' '))
	    {
	        result.push_back(line);
	       // cout << result[2];
	        //cout << line << endl;// Note: You may get a couple of blank lines
	                                // When multiple underscores are beside each other.
	    }


	string method = result[5];
	string timestamp = result[3];

	rm.requestor = result[0];
	rm.http_method = parse_method(method);
	rm.timestamp = parse_timestamp(timestamp);
	rm.url = result[6];
	rm.response = result[8];
	rm.request_duration = result[9];

	return rm;
}

// tablica zliczaczy
// 0 1 2 3 4 5
//

time_t RowParser::parse_timestamp(string datetime) {

	std::tm t; //= {};

	time_t rawtime;
	struct tm * timeinfo;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	//int *year;

	//cout << "here";
	string timestamp = datetime;
	timestamp.erase (timestamp.begin());
		istringstream ss(timestamp);
		ss.imbue(std::locale("en_US.utf-8"));
		ss >> get_time(&t, "%d/%b/%Y:%H:%M:%S");
		if (ss.fail()) {
			cout << "Parse failed\n";
		} else {
			stringstream ssTp;
			ssTp << put_time(&t, "%Y");
			//ssTp << put_time(&t, "%Y-%m-%d %H:%M:%S");
			//stringstream year;
			//year << put_time(&t, "%Y");
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
			//year = &t.tm_year;

		}

		timeinfo->tm_year = year;
		timeinfo->tm_mon = month;
		timeinfo->tm_mday = day;
		timeinfo->tm_hour = hour;
		timeinfo->tm_min = minute;
		timeinfo->tm_sec = second;

		rawtime = mktime ( timeinfo );
		//cout << year << '-' << month << '-' << day << '-' << hour << '-' << minute << '-' << second << ' ' ;
		//cout << *year << endl;
		//time ( &rawtime );
		//timeinfo = localtime ( &rawtime );
		//mktime(timeinfo);
		//cout << rawtime << endl;
	return rawtime;
}

string RowParser::parse_method(string method) {
	method.erase(method.begin());
	return method;
}




