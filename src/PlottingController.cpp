/*
 * PlottingController.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#include "../include/PlottingController.h"
#include "../include/PlotConfig.h"
#include <fstream>


void PlottingController::create_gnuplot_file(PlotConfig plot_config, string output_filename) {
	ofstream output_file;
	output_file.open(output_filename);

	output_file << "#!/usr/bin/gnuplot\n";
	output_file << "reset\n";
	output_file << "set terminal postscript eps enhanced color font 'Helvetica,10'\n";
	output_file << "set output '" << plot_config.eps_filename << "'\n";

	output_file << "set xdata time\n";
	output_file << "set timefmt '\%s'\n";
	output_file << "set format x \"" << plot_config.x_format << "\"\n";

	output_file << "set xlabel '" << plot_config.x_label << "'\n";
	output_file << "set ylabel '" << plot_config.y_label << "'\n";

	output_file << "set title '" << plot_config.title << "'\n";
	output_file << "set key below\n";
	output_file << "set grid\n";

	output_file << "set key outside\n";

	output_file << "plot ";
	int nol = plot_config.number_of_lines;
	for (int i = 1; i < nol; ++i) {
		output_file << "'" << plot_config.dat_file << "' using 1:" << i+1 << " with lines title '" << plot_config.line_titles[i-1] << "',\\\n";
	}
	output_file << "'" << plot_config.dat_file << "' using 1:" << nol+1 << " with lines title '" << plot_config.line_titles[nol-1] << "'\n";

	output_file.close();

	return;
}