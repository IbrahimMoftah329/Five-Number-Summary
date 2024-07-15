For project 3, given an input file of integer values, you will compute all the statistics included in a five-number summary or a box plot: the minimum value, the 25th, 50th, and 75th percentiles, and the maximum value.
The integers in the input will be sampled from a gamma distribution. Because of the characteristics of gamma distributions, as the input size increases, the number of unique values will grow slowly, and there will be an increasing number of duplicates, yet there is no absolute upper limit on the values. This will make the input a good candidate for a hash-based counting sort.
You will compute the five-number summary with each of the following methods, and benchmark the time taken for each method:
1) Use std::sort
2) Use quickselect 3 times, then calculate the min and max separately
3) Modify quickselect to recurse if any of the 5 values are in the subrange
4) Use a modified counting sort that uses hashes
For method 2, find the median first. Then, on the same vector that's already partitioned around the median, call quickselect on the left half to find P25 and on the right half to find P75. Then, search the part of the vector below P25 for the min and above P75 for the max.
For method 3, modify quickselect's recursive function to take a short list of keys rather than just one key. If you refer to p.322 in the textbook, you can replace the parameter int k with a small vector or list. Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether there are positions you're searching for on both sides or only one.

Each method should print the header from the input file, followed by 5 lines stating the minimum, each quartile, and the maximum.
Here's an example showing the output from the sample input file:
Male elephant seal weights
Min: 5069
P25: 5796
P50: 6129
P75: 6548
Max: 9218
For counting sort only, also include the number of unique values. For the sample input, it would look like:
Unique: 787
To simplify determining which position you're looking for, I'm going to keep input sizes divisible by 100. So then, in a sorted list of 1000 elements, P25 is the 250th element, P50 is the 500th, P75 is the 750th, etc.

Yes, the functions all take the same parameters. They only take a reference to the header, which will just be printed out, and a copy of the data, which will be sorted or partitioned around several points depending on the method used.
The data is passed by value, since the function will sort the vector it's passed, and most of the methods are in-place.
You will need to write your own helper functions for each. In particular, for quickSelect, you will need to write the recursive quickSelect and use the function I require as a wrapper.

For method 1, just use std::sort and print out the appropriate data points. This is to ensure that you have the correct answer and are printing correctly, and to give you a baseline to time your other algorithms against.
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. This will give you the median, around which your vector will be partitioned. Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k. Then, call quickSelect on the half of the vector after the median with the 75% mark as k. Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. Default to insertion sort when quickSelect is recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).
For method 3, replace the key k in your quickSelect's parameters with a set of keys you're looking for (use whatever container you want to hold them), which will include position 0, the 25% mark, the 50% mark, the 75% mark, the the last position of the data vector. Rewrite the recursive portion of quickSelect so that it checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), or if it only needs to recurse on one side. This may be tricky to work out, but once you figure out the algorithm, it's not really much coding to implement. Again, default to insertion sort once you reach a size of 20 or less.
Method 4 (counting sort) is the only of these methods that isn't in-place. You'll need to read the integers from the data vector and insert them into a hash map, with the data value as the hash key, and a count of times that particular data value was seen as the hash value. So the first time you see a new value X in the data, you insert it into the hash using X as the key, and you set that key's hash value to 1. The second time you see X, you find that it's already in the hash, so you increment its hash value to 2. The third time you see X, you increment its hash value to 3, and so on.
Once you have a hash map of all the unique data values and the number of times each data value appeared in the data, iterate through the hash map, pushing the key-value pairs in the hash map to a vector. Then, sort that vector using std::sort (in an input with many duplicates, a vector of unique values will be much smaller than a vector of all the values). Finally, iterate through that vector finding P25, P50, and P75. You'll have to count how many data points you've seen along the way, since each element of the vector represents multiple data point, not just one. Finding the minimum and maximum should be self-explanatory.

As you did with project 2, you should time each method on inputs I will provide of size 1K, 100K, and 10M.
Along with your files, submit a report in PDF format with the following:
1) A clearly labeled table showing the size and number of unique values for each input, and the time it took for each implementation on each input.
2) A complexity analysis of each method in O-notation.
3) Discussion of how having fewer unique values and more copies of each value affected the time, along with your hypotheses of why each algorithm performed as it did.
4) Any additional observations you had during the project.
The whole thing should be about 2-3 pages.

