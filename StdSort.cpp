/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

#include "StdSort.hpp"

// Function to calculate percentiles using std::sort
void stdSort(const std::string & header, std::vector<int> data) {
    // Timing the process
    const auto t1_start = std::chrono::steady_clock::now();

    // Make a copy of the data to sort it
    std::vector<int> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    
    // Calculate the positions for the 25th, 50th, and 75th percentiles
    int size = sorted_data.size();
    int pos25 = static_cast<int>(0.25 * (size - 1));
    int pos50 = static_cast<int>(0.5 * (size - 1));
    int pos75 = static_cast<int>(0.75 * (size - 1));

    // Calculate the percentiles
    int min = sorted_data[0];
    int p25 = sorted_data[pos25];
    int median = sorted_data[pos50];
    int p75 = sorted_data[pos75];
    int max = sorted_data[sorted_data.size() - 1];

    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
    std::cout << "std::sort method completed in " << t1 << " microseconds." << std::endl;
    
    // Print the percentiles
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}