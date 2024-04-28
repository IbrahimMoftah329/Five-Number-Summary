/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

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
void quickselectFunction(std::vector<int>& data, int left, int right, std::set<int>& keys);

#endif