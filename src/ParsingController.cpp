/*
 * ParsingController.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/ParsingController.h"
#include "../include/RowParser.h"
#include <fstream>

vector<RowModel> ParsingController::parse_input() {
	vector<RowModel> rm_vector;
	RowParser rp;
	string input;
	 ifstream myfile ("resources/access_log");

		  if (myfile.is_open())
		  {
		    while ( getline (myfile,input) )
		    {
		      //cout << input << '\n';
		      rm_vector.push_back(rp.parse(input));
		      //cout << rm_vector[0].requestor;

		    }

		    myfile.close();
		  }

		  else cout << "Unable to open file";



		  	  //cout << '\n';

		  return rm_vector;

}


