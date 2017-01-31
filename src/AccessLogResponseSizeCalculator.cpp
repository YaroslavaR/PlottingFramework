/*
 * AccessLogResponseSizeCalculator.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: romay
 */
#include "../include/AccessLogResponseSizeCalculator.h"
#include <iostream>
#include <time.h>

using namespace std;

map<time_t, vector<int> > AccessLogResponseSizeCalculator::calculate_data(vector<AccessLogInputModel> input) {

	map<time_t, vector<int>> result;

	sort (input.begin(), input.end(),
		[] (const AccessLogInputModel& lhs, const AccessLogInputModel& rhs) {
			return lhs.timestamp < rhs.timestamp;
		}
	);

	vector< pair<time_t, int> > response_size_series;
	for (auto it = input.begin(); it != input.end(); ++it) {
		int response_size = it->response_size == "-" ? 0 : stoi(it->response_size);
		response_size_series.push_back(make_pair(it->timestamp, response_size));
	}
	vector< pair<time_t, int> > max_response_size_per_hour = summarize_series<Calculator::Max, 60*60>(response_size_series);
	vector< pair<time_t, int> > avg_response_size_per_hour = summarize_series<Calculator::Avg, 60*60>(response_size_series);
	vector< pair<time_t, int> > min_response_size_per_hour = summarize_series<Calculator::Min, 60*60>(response_size_series);

	for (int i=0; i < max_response_size_per_hour.size(); i++) {
		vector<int> values;
		values.push_back(max_response_size_per_hour[i].second);
		values.push_back(avg_response_size_per_hour[i].second);
		values.push_back(min_response_size_per_hour[i].second);
		result.insert(make_pair(max_response_size_per_hour[i].first, values));
	}

	return result;
}

