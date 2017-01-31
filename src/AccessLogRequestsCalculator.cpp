/*
 * AccessLogRequestsCalculator.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: romay
 */
#include "../include/AccessLogRequestsCalculator.h"
#include <iostream>
#include <time.h>

using namespace std;

map<time_t, vector<int> > AccessLogRequestsCalculator::calculate_data(vector<AccessLogInputModel> input) {

	map<time_t, vector<int>> result;

	sort (input.begin(), input.end(),
		[] (const AccessLogInputModel& lhs, const AccessLogInputModel& rhs) {
			return lhs.timestamp < rhs.timestamp;
		}
	);

	vector< pair<time_t, int> > all_requests_series;
	for (auto it = input.begin(); it != input.end(); ++it) {
		all_requests_series.push_back(make_pair(it->timestamp, 1));
	}
	vector< pair<time_t, int> > all_requests_per_hour = summarize_series<Calculator::Sum, 60*60>(all_requests_series);


	vector< pair<time_t, int> > successful_requests_series;
	for (auto it = input.begin(); it != input.end(); ++it) {
		successful_requests_series.push_back(make_pair(it->timestamp, it->response_http_code == "200" ? 1 : 0));
	}
	vector< pair<time_t, int> > successful_requests_per_hour = summarize_series<Calculator::Sum, 60*60>(successful_requests_series);



	for (int i=0; i < all_requests_per_hour.size(); i++) {
		vector<int> values;
		values.push_back(all_requests_per_hour[i].second);
		values.push_back(successful_requests_per_hour[i].second);
		result.insert(make_pair(all_requests_per_hour[i].first, values));
	}

	return result;
}

