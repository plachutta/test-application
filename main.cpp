#include <iostream>
#include <vector>
#include "stats.hpp"  
#include <numeric>     // Include <numeric> for accumulate function

int main() {
    // Example vector
    std::vector<double> values = {1.2, 2.5, 3.1, 1.2, 2.5, 1.2, 4.0, 3.1, 3.1, 2.5};
// Count occurrences of a specific value
    double valueToCount = 1.2;
    int occurrences = count_occurrences(values, valueToCount);
    std::cout << "Occurrences of " << valueToCount << ": " << occurrences << std::endl;

    // Summarize the vector
    std::vector<std::pair<double, int>> summary = summarize(values);

    // Display the summary
    std::cout << "Summary:" << std::endl;
    for (const auto& pair : summary) {
        std::cout << "Value: " << pair.first << ", Occurrences: " << pair.second << std::endl;
    }
    // Call each function and display the results
    std::cout << "Count: " << count(values) << std::endl;
    std::cout << "Sum: " << sum(values) << std::endl;
    std::cout << "Mean: " << mean(values) << std::endl;
    std::cout << "Median: " << median(values) << std::endl;
    std::cout << "Mode: " << mode(values) << std::endl;
    std::cout << "Min: " << min(values) << std::endl;
    std::cout << "Max: " << max(values) << std::endl;
    std::cout << "Standard Deviation: " << stdev(values) << std::endl;

    // Test Percentile with different values of p
    double p_values[] = {25.0, 50.0, 75.0};
    for (double p : p_values) {
        std::cout << "Percentile (" << p << "%): " << percentile(values, p) << std::endl;
    }

    return 0;
}
