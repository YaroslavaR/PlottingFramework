/*
 * ParsingController.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_PARSINGCONTROLLER_H_
#define INCLUDE_PARSINGCONTROLLER_H_
#include "Parser.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template <class IM>
class ParsingController {
  private:
  	shared_ptr< Parser<IM> > parser;
  public:
  	ParsingController(shared_ptr< Parser<IM> > parser) : parser(parser) {};
	vector<IM> parse_input(string input_filename);
};

template <class IM>
vector<IM> ParsingController<IM>::parse_input(string input_filename) {
	vector<IM> im_vector;
	string input;
	ifstream myfile (input_filename);
	if (myfile.is_open()) {
		while ( getline (myfile, input) ) {
			IM tmp;
			tmp = this->parser->parse(input);
			im_vector.push_back(tmp);
		}
		myfile.close();
	} else {
		cerr << "Unable to open file";
	}
	return im_vector;
}



#endif /* INCLUDE_PARSINGCONTROLLER_H_ */
