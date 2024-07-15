#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"


int main() {
    // Open input file
    std::ifstream inputFile("test_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    // Step 1: Read the headers from the input file as a single line string
    std::string header;
    std::getline(inputFile, header);

    // Step 2: Read the list of numbers from the input file as a single line string
    std::string numberLine;
    std::getline(inputFile, numberLine);
    
    // Close the input file since we are done reading from it
    inputFile.close();

    // Step 3: Create a vector to store the numbers
    std::vector<int> numbers;
    std::istringstream numberStream(numberLine);
    int number;
    while (numberStream >> number) {
        numbers.push_back(number);
    }
    
    // Step 4: Call the function to calculate the percentiles
    stdSort(header, numbers);
    quickSelect1(header, numbers);
    quickSelect2(header, numbers);
    countingSort(header, numbers);
    
    return 0;
}
