/*
 * AccessLogInputModel.h
 *
 *  Created on: Jan 28, 2017
 *      Author: romay
 */

#ifndef INCLUDE_ACCESSLOGINPUTMODEL_H_
#define INCLUDE_ACCESSLOGINPUTMODEL_H_

#include "InputModel.h"
#include <iostream>
#include <time.h>

using namespace std;

class AccessLogInputModel : public InputModel {
public:
	time_t timestamp;
	string url;
	string response_http_code;
	string http_method;
	string requestor;
	string response_size;
	virtual void print();
};




#endif /* INCLUDE_ACCESSLOGINPUTMODEL_H_ */
