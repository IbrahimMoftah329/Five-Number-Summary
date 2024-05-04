/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

#include "QuickSelect2.hpp"

// Function to perform the Quickselect algorithm
void quickSelectFunction(std::vector<int>& data, int left, int right, std::set<int>& keys) {
    // Base case: If the range is invalid or empty, return
    if (left >= right) {
        return;
    }

    // If the range is small, switch to insertion sort
    if (right - left <= 20) {
        // Insertion sort
        for (int i = left + 1; i <= right; ++i) {
            int key = data[i];
            int j = i - 1;
            // Move elements greater than key to the right
            while (j >= left && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            // Insert key into correct position
            data[j + 1] = key;
        }
        return;
    }

    // Choose pivot randomly
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = data[pivotIndex];
    // Move pivot to the end
    std::swap(data[pivotIndex], data[right]);
    int storeIndex = left;
    // Partition the array around the pivot
    for (int i = left; i < right; ++i) {
        if (data[i] < pivotValue) {
            std::swap(data[i], data[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(data[storeIndex], data[right]);

    // Check which keys are needed on the left and right sides
    std::set<int> leftKeys, rightKeys;
    for (int key : keys) {
        if (key < storeIndex - left) {
            // Key belongs to the left side
            leftKeys.insert(key);
        } else if (key > storeIndex - left) {
            // Key belongs to the right side
            rightKeys.insert(key - (storeIndex - left) - 1);
        }
    }

    // Recurse on the appropriate sides
    quickSelectFunction(data, left, storeIndex - 1, leftKeys);   // Left side
    quickSelectFunction(data, storeIndex + 1, right, rightKeys); // Right side
}

// Function to calculate percentiles using Quickselect
void quickSelect2(const std::string & header, std::vector<int> data) {
    std::vector<int> data_copy = data; // Make a copy of the data

    // Timing the process
    auto t1_start = std::chrono::steady_clock::now();

    // Calculate the positions for the keys
    int size = data_copy.size();
    std::set<int> keys = {0, static_cast<int>(0.25 * (size - 1)), static_cast<int>(0.5 * (size - 1)), static_cast<int>(0.75 * (size - 1)), size - 1};

    // Perform the modified quickselect
    quickSelectFunction(data_copy, 0, size - 1, keys);

    // Extract the values at the keys
    std::vector<int> results;
    for (int key : keys) {
        results.push_back(data_copy[key]);
    }

    auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    std::cout << "Quickselect recurse method completed in " << t1 << " microseconds." << std::endl;

    // Print the results
    std::cout << header << std::endl;
    std::cout << "Min: " << results[0] << std::endl;
    std::cout << "P25: " << results[1] << std::endl;
    std::cout << "P50: " << results[2] << std::endl;
    std::cout << "P75: " << results[3] << std::endl;
    std::cout << "Max: " << results[4] << std::endl;
}