Project: Five-Number Summary Calculation and Benchmarking

Objective

Given an input file containing integer values, compute a five-number summary: the minimum value, the 25th percentile (P25), the median (P50), the 75th percentile (P75), and the maximum value. The input integers, sampled from a gamma distribution, will have unique properties: as input size increases, unique values grow slowly, but duplicates increase, making hash-based counting sort an effective method.

Methods

You will implement and benchmark the following methods to compute the five-number summary:

std::sort
Quickselect 3 times, then calculate min and max separately
Modified quickselect to recurse if any of the 5 values are in the subrange
Modified counting sort using hashes

Method 1: std::sort
Use std::sort to sort the data.
Extract the minimum, P25, P50, P75, and maximum values from the sorted data.
This provides a baseline for correctness and benchmarking.

Method 2: Quickselect 3 times
Call quickselect on the entire input to find the median (P50).
Use the partitioned vector to call quickselect on the left half to find P25 and on the right half to find P75.
Search for the minimum in the subrange below P25 and the maximum in the subrange above P75.
Default to insertion sort for subranges of size 20 or less.

Method 3: Modified Quickselect
Modify quickselect to accept a list of keys to find the five-number summary values.
Recurse on both sides if needed, or just one side depending on the positions of the keys.
Use insertion sort for subranges of size 20 or less.

Method 4: Counting Sort Using Hashes
Read integers into a hash map where the key is the integer and the value is its count.
Sort the hash map keys using std::sort.
Iterate through the sorted keys, accounting for the counts to find P25, P50, and P75.
Find the minimum and maximum values directly from the hash map keys.

Input and Output
Each method should:
Print the header from the input file.
Print the minimum, P25, P50, P75, and maximum values in the following format:
Min: [value]
P25: [value]
P50: [value]
P75: [value]
Max: [value]

For counting sort, additionally print the number of unique values:
Unique: [number]

Benchmarking
Run each method on input sizes of 1K, 100K, and 10M. Measure the time taken for each method on each input size.

Report

A table showing the size, number of unique values for each input, and the time taken for each implementation.
Complexity analysis of each method in O-notation.
Discussion of how having fewer unique values and more duplicates affected the performance, with hypotheses on why each algorithm performed as it did.
Additional observations during the project.
