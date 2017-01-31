/*
 * RowModel.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_INPUTMODEL_H_
#define INCLUDE_INPUTMODEL_H_
#include <iostream>
#include <time.h>

using namespace std;

class InputModel {
public:
	virtual void print() = 0;
	virtual ~InputModel() {};
};




#endif /* INCLUDE_INPUTMODEL_H_ */
