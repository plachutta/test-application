// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <numeric> 
#include <gtest/gtest.h> 
using namespace std;
int count_occurrences(const std::vector<double>& v, double value) {
    return std::count(v.begin(), v.end(), value);
}
vector<pair<double, int>> summarize(vector<double> v) 
     {
    vector<pair<double, int>> result;
    
    // Checks if the input vector is empty
    if (v.empty()) {
        cerr << "Error: Input vector is empty in summarize function." << endl;
        exit(EXIT_FAILURE);
    }

    // Sorts the input vector
    sort(v.begin(), v.end());

    // Counts occurrences of each unique value
    for (size_t i = 0; i < v.size(); ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            int count = count_occurrences(v, v[i]);
            result.push_back({v[i], count});
        }
    }

    return result;
}
int count(vector<double> v) {
    // Checks if the input vector is empty
    if (v.empty()) {
        cerr << "Error: Input vector is empty in count function." << endl;
        exit(EXIT_FAILURE);
    }

    // Returns the size of the input vector, which represents the count of elements
    return v.size();
}

double sum(vector<double> v) {
    // Checks if the input vector is empty
    if (v.empty()) {
        cerr << "Error: Input vector is empty in sum function." << endl;
        exit(EXIT_FAILURE);
    }

    // Calculates the sum using accumulate function from <numeric> header
    double result = accumulate(v.begin(), v.end(), 0.0);
    
    return result;
}


double mean(vector<double> v) {
    // Checks if the input vector is empty
    if (v.empty()) {
        cerr << "Error: Input vector is empty in mean function." << endl;
        exit(EXIT_FAILURE);
    }

    // Calculates the mean by dividing the sum by the count
    double sum_result = sum(v);
    double mean_result = sum_result / count(v);

    return mean_result;
}

double median(vector<double> v) {
    // Checks if the input vector is empty
    if (v.empty()) {
        cerr << "Error: Input vector is empty in median function." << endl;
        exit(EXIT_FAILURE);
    }

    // Sorts the input vector
    sort(v.begin(), v.end());

    // Calculates the median based on the sorted vector
    size_t size = v.size();
    double median_result;
    if (size % 2 == 0) {
        median_result = (v[size / 2 - 1] + v[size / 2]) / 2.0;
    } else {
        median_result = v[size / 2];
    }

    return median_result;
}
double mode(vector<double> v) {
    if (v.empty()) {
        cerr << "Error: Cannot calculate mode for an empty vector.\n";
        exit(EXIT_FAILURE);
    }

    unordered_map<double, int> freq_map;
    for (const auto &num : v) {
        freq_map[num]++;
    }

    double mode_value = v[0];
    int max_freq = 1;

    for (const auto &entry : freq_map) {
        if (entry.second > max_freq) {
            max_freq = entry.second;
            mode_value = entry.first;
        }
    }

    return mode_value;
}

double min(vector<double> v) {
    if (v.empty()) {
        cerr << "Error: Cannot calculate minimum for an empty vector.\n";
        exit(EXIT_FAILURE);
    }

    double min_value = v[0];
    for (const auto &num : v) {
        if (num < min_value) {
            min_value = num;
        }
    }

    return min_value;
}

double max(vector<double> v) {
    if (v.empty()) {
        cerr << "Error: Cannot calculate maximum for an empty vector.\n";
        exit(EXIT_FAILURE);
    }

    double max_value = v[0];
    for (const auto &num : v) {
        if (num > max_value) {
            max_value = num;
        }
    }

    return max_value;
}

double stdev(vector<double> v) {
    if (v.empty()) {
        cerr << "Error: Cannot calculate standard deviation for an empty vector.\n";
        exit(EXIT_FAILURE);
    }

    double sum = 0.0;
    double mean_value = mean(v);

    for (const auto &num : v) {
        sum += pow(num - mean_value, 2);
    }

    double variance = sum / v.size();
    double stdev_value = sqrt(variance);

    return stdev_value;
}

double percentile(std::vector<double> v, double p) {
    if (v.empty()) {
        std::cerr << "Error: Cannot calculate percentile for an empty vector.\n";
        exit(EXIT_FAILURE);
    }

    if (p < 0.0 || p > 100.0) {
        std::cerr << "Error: Percentile value must be between 0.0 and 100.0.\n";
        exit(EXIT_FAILURE);
    }

    //sorting vector
    std::sort(v.begin(), v.end());

    // This calculates the index in the sorted vector
    double index = (p / 100.0) * (v.size() - 1);
    double integralPart;
    double fractionalPart = modf(index, &integralPart);

    // Converts integral part to integer
    int lower_index = static_cast<int>(integralPart);
    int upper_index = lower_index + 1;

    // Validates index bounds
    if (lower_index < 0 || upper_index >= v.size()) {
        std::cerr << "Error: Percentile calculation resulted in out-of-bounds index.\n";
        exit(EXIT_FAILURE);
    }

    double result;

    if (fractionalPart == 0.0) {
        
        result = v[lower_index];
    } else {
        // Interpolates between values
        double lower_value = v[lower_index];
        double upper_value = v[upper_index];
        result = lower_value + fractionalPart * (upper_value - lower_value);
    }

    return result;
}