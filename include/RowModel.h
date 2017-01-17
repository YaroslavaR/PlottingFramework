/*
 * RowModel.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_ROWMODEL_H_
#define INCLUDE_ROWMODEL_H_
#include <iostream>
#include <time.h>

using namespace std;

class RowModel {
public:
	time_t timestamp;
	string url;
	string response;
	string http_method;
	string requestor;
	string request_duration;
};




#endif /* INCLUDE_ROWMODEL_H_ */
