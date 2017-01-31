/*
 * AccessLogInputModel.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: romay
 */

#include "../include/AccessLogInputModel.h"

#include <iostream>

void AccessLogInputModel::print() {
	cerr << "InputModel{\n  timestamp=" << this->timestamp << ";\n  code=" << this->response_http_code << ";\n  method=" 
		<< this->http_method << ";\n  response size=" << this->response_size << ";\n}\n";
}