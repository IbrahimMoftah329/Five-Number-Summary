#ifndef QUICKSELECTRECURSE_HPP
#define QUICKSELECTRECURSE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <set>

// Function to calculate percentiles using Quickselect
void quickSelect2(const std::string & header, std::vector<int> data);

// Function to perform the Quickselect algorithm
void quickSelectFunction(std::vector<int>& data, int left, int right, std::set<int>& keys);

#endif
