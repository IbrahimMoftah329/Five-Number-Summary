/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

#include "QuickSelect1.hpp"

// Function to perform the Quickselect algorithm
int quickSelectFunction(std::vector<int>& data, int left, int right, int k) {
    // Base case: If the range contains only one element, return it
    if (left == right) {
        return data[left];
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
        // Return the kth element
        return data[left + k];
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

    // Check if the pivot is the kth element
    if (k == storeIndex - left) {
        return data[storeIndex];
    } else if (k < storeIndex - left) { // Recurse on the left side
        return quickSelectFunction(data, left, storeIndex - 1, k);
    } else { // Recurse on the right side
        return quickSelectFunction(data, storeIndex + 1, right, k - (storeIndex - left) - 1);
    }
}

// Function to calculate percentiles using Quickselect
void quickSelect1(const std::string& header, std::vector<int> data) {
    // Timing the process
    auto t1_start = std::chrono::steady_clock::now();

    // Calculate the position for the median (P50)
    int size = data.size();
    int pos50 = static_cast<int>(0.5 * (size - 1));

    // Find the median (P50)
    int median = quickSelectFunction(data, 0, size - 1, pos50);

    // Calculate the positions for the 25th and 75th percentiles
    int pos25 = static_cast<int>(0.25 * size);
    int pos75 = static_cast<int>(0.75 * (size - 1));

    // Calculate P25 and P75 using Quickselect on the appropriate halves
    int p25 = quickSelectFunction(data, 0, pos50 - 1, pos25 - 1);
    int p75 = quickSelectFunction(data, pos50 + 1, size - 1, pos75 - pos50 - 1);

    // Find min and max in the sections below P25 and above P75
    int min = data[0];
    int max = data[0];

    // Find min
    for (int i = 0; i < pos25; ++i) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    // Find max
    for (size_t i = pos75; i < data.size(); ++i) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    // std::cout << "Quickselect method completed in " << t1 << " microseconds." << std::endl;

    // Print the percentiles
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << p25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << p75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}