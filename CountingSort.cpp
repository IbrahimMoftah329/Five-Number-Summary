/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

#include "CountingSort.hpp"

// Function to calculate percentiles using counting sort
void countingSort(const std::string & header, std::vector<int> data) {
    // Create a hash map to store counts of each unique data value
    std::unordered_map<int, int> hash;

    // Timing the process
    auto t1_start = std::chrono::steady_clock::now();
    
    // Count the occurrences of each data value
    for (int value : data) {
        hash[value]++;
    }

    // Create a vector of pairs to store (value, count)
    std::vector<std::pair<int, int>> counts;
    for (const auto& pair : hash) {
        counts.emplace_back(pair.first, pair.second);
    }

    // Sort the vector based on the value
    std::sort(counts.begin(), counts.end()); //*

    // Calculate cumulative counts for quartiles
    int total = 0;
    for (auto& pair : counts) {
        total += pair.second;
        pair.second = total;
    }

    // Calculate quartiles
    int size = data.size();
    int p25Index = size / 4;
    int p50Index = size / 2;
    int p75Index = (3 * size) / 4;

    // Initialize variables to store quartile values
    int min = counts.front().first;
    int max = counts.back().first;
    int p25 = 0, median = 0, p75 = 0;

    // Find quartile values based on cumulative counts
    for (const auto& pair : counts) {
        if (pair.second >= p25Index && p25 == 0) {
            p25 = pair.first;
        }
        if (pair.second >= p50Index && median == 0) {
            median = pair.first;
        }
        if (pair.second >= p75Index && p75 == 0) {
            p75 = pair.first;
        }
    }

    // Measure the time taken for sorting and calculations
    auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    // std::cout << "Counting sort method completed in " << t1 << " microseconds." << std::endl;

    // Print the percentiles and number of unique elements
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Unique: " << counts.size() << std::endl;
}