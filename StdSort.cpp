/*
Author: Ibrahim Moftah
*/

#include "StdSort.hpp"

// Function to calculate percentiles using std::sort
void stdSort(const std::string & header, std::vector<int> data) {
    // Timing the process
    const auto t1_start = std::chrono::steady_clock::now();

    // Sort it
    std::sort(data.begin(), data.end());
    
    // Calculate the percentiles using the positions for the 25th, 50th, and 75th percentiles
    int size = data.size();
    int min = data[0];
    int p25 = data[(size - 1) / 4];
    int median = data[(size - 1) / 2];
    int p75 = data[3 * (size - 1) / 4];
    int max = data[data.size() - 1];

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    // std::cout << "std::sort method completed in " << t1 << " microseconds." << std::endl;
    
    // Print the percentiles
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}
