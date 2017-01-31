/*
 * Calculator.h
 *
 *  Created on: Jan 14, 2017
 *      Author: romay
 */

#ifndef INCLUDE_CALCULATOR_H_
#define INCLUDE_CALCULATOR_H_
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <class IM>
class Calculator {
  protected:
	template <class OP, int INTERVAL> // INTERVAL in seconds
	vector< pair<time_t, int> > summarize_series(vector< pair<time_t, int> > series) {
		OP operation;
		vector< pair<time_t, int> > result;
		time_t range_low = (time_t)(series.front().first / INTERVAL);
		time_t current_bucket = range_low; // bucket index since the beginning of Unix time
		for (auto it = series.begin(); it != series.end(); ++it) {
			time_t timestamp = it->first;
			int value = it->second;
			time_t bucket = (time_t)(timestamp / INTERVAL);
			if (bucket > current_bucket) {
				result.push_back(make_pair(current_bucket * INTERVAL, operation.flush()));
				current_bucket = bucket;
			}
			operation.put(value);
		}
		result.push_back(make_pair(current_bucket * INTERVAL, operation.flush()));
		return result;
	}

  public:
    virtual map<time_t, vector<int> > calculate_data(vector<IM> input) = 0;

    class Sum {
      private:
        int sum = 0;
      public:
        void put(int a) {sum += a;}
        int flush() {
            int result = sum;
            sum = 0;
            return result;
        }
    };

    class Max {
      private:
        int max = 0;
      public:
        void put(int a) { if (a > max) max = a;}
        int flush() {
            int result = max;
            max = 0;
            return result;
        }
    };

    class Min {
      private:
        int min = 0;
      public:
        void put(int a) { if (min == 0 || a < min) min = a;}
        int flush() {
            int result = min;
            min = 0;
            return result;
        }
    };

    class Avg {
      private:
        int number_of_entries = 0;
        int sum = 0;
      public:
        void put(int a) {
            number_of_entries++;
            sum += a;
        }
        int flush() {
            int result = sum / number_of_entries;
            number_of_entries = 0;
            sum = 0;
            return result;
        }
    };
};

#endif /* INCLUDE_CALCULATOR_H_ */
