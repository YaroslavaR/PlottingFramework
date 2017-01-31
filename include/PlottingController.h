/*
 * PlottingController.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_PLOTTINGCONTROLLER_H_
#define INCLUDE_PLOTTINGCONTROLLER_H_

#include "PlotConfig.h"
#include <string>

using namespace std;

class PlottingController {
public:
	void create_gnuplot_file(PlotConfig plot_config, string output_filename);
};



#endif /* INCLUDE_PLOTTINGCONTROLLER_H_ */
