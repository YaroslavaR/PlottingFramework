/*
 * main.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */
#include "../include/ParsingController.h"
#include "../include/CalculatingController.h"
#include "../include/PlottingController.h"
#include "../include/PlotConfig.h"
#include "../include/AccessLogInputModel.h"
#include "../include/Parser.h"
#include "../include/AccessLogParser.h"
#include "../include/AccessLogRequestsCalculator.h"
#include "../include/AccessLogResponseSizeCalculator.h"

using namespace std;

void create_number_of_requests_plot();
void create_response_size_plot();

int main() {

	create_number_of_requests_plot();
	create_response_size_plot();

	return 0;
}

void create_number_of_requests_plot() {
	shared_ptr< Parser<AccessLogInputModel> > access_log_parser(new AccessLogParser());
	ParsingController<AccessLogInputModel> parsing_controller(access_log_parser);
	vector<AccessLogInputModel> parsed_input = parsing_controller.parse_input("resources/access_log");

	CalculatingController<AccessLogInputModel, AccessLogRequestsCalculator> calculating_controller;
	calculating_controller.calculate_plotting_data(parsed_input, "output/requests.dat");

	PlottingController plotting_controller;
	PlotConfig plot_config;
	plot_config.dat_file = "output/requests.dat";
	plot_config.eps_filename = "output/requests.eps";
	plot_config.x_format = "\%d-\%m \%H:\%M";
	plot_config.x_label = "Time";
	plot_config.y_label = "# of requests";
	plot_config.title = "Number of requests (all vs success) over time";
	plot_config.number_of_lines = 2;
	plot_config.line_titles = {"All", "Success"};
	plotting_controller.create_gnuplot_file(plot_config, "output/requests.gp");
}

void create_response_size_plot() {
	shared_ptr< Parser<AccessLogInputModel> > access_log_parser(new AccessLogParser());
	ParsingController<AccessLogInputModel> parsing_controller(access_log_parser);
	vector<AccessLogInputModel> parsed_input = parsing_controller.parse_input("resources/access_log");

	CalculatingController<AccessLogInputModel, AccessLogResponseSizeCalculator> calculating_controller;
	calculating_controller.calculate_plotting_data(parsed_input, "output/response_size.dat");

	PlottingController plotting_controller;
	PlotConfig plot_config;
	plot_config.dat_file = "output/response_size.dat";
	plot_config.eps_filename = "output/response_size.eps";
	plot_config.x_format = "\%d-\%m \%H:\%M";
	plot_config.x_label = "Time";
	plot_config.y_label = "Response size";
	plot_config.title = "Response size (max, avg, min) over time";
	plot_config.number_of_lines = 3;
	plot_config.line_titles = {"Max", "Avg", "Min"};
	plotting_controller.create_gnuplot_file(plot_config, "output/response_size.gp");
}

