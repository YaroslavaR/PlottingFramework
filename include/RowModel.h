/*
 * RowModel.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_ROWMODEL_H_
#define INCLUDE_ROWMODEL_H_
#include <iostream>

using namespace std;

class RowModel {
public:
	string timestamp;
	string url;
	string response;
	string http_method;
	string requestor;
	string request_duration;
};




#endif /* INCLUDE_ROWMODEL_H_ */
