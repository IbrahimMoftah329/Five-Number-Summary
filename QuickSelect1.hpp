/*
CSCI335 Spring 2024
Project 3
Ibrahim Moftah
*/

#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Function to calculate percentiles using Quickselect
void quickSelect1(const std::string & header, std::vector<int> data);

// Function to perform the Quickselect algorithm
int quickSelectFunction(std::vector<int>& data, int left, int right, int k);

#endif