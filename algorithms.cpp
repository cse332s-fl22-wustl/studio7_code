/* algorithms.cpp
Author: Jon Shidal

Purpose: definitions for algorithms used throughout this program. Algorithm descriptions can be found in algorithms.h
*/

#include "algorithms.h"
#include<vector>   // this include could be left out because <vector> is included in "algorithms.h"

using namespace std;

void insertion_sort(vector<int> & arr) {
	unsigned int i = 1; // start at the 2nd element in the array, the first insertion is already sorted
    int v[10];
	while (i < arr.size()) {
		unsigned int j = i; // insert the next element into the end of the array
        v[i] = j;
        i++;
		while ((j > 0) && (v[j] < v[j - 1])) { // shift left if needed
			int temp = v[j - 1];
			v[j - 1] = v[j];
			v[j] = temp;
			--j;
		}

	}
}

// helper function for performing binary search recursively. This function checks the midpoint of start and end
// to see if it is the value being searched for. If so, true is returned. Otherwise, recursively search 
// the upper or lower half
bool binary_search_helper(const vector<int> & v, int value, unsigned int start, unsigned int end) {
	if (start >= end) { // make sure we are still in bounds
		return false;
	}
	unsigned int middle_index = (start + end)/2;
	int middle_value = v[middle_index];
	if (middle_value == value) { // check the midpoint for value
		return true;
	}
	else if (value < middle_value) { // search the lower half
		return binary_search_helper(v, value, start, middle_index);
	}
	else { // search the upper half
		return binary_search_helper(v, value, middle_index + 1, end);
	}
}

// function visible to the rest of the program through algorithms.h. simply calls binary_search_helper on the entire vector
// as long as the vector is non-empty
bool binary_search(const vector<int> & v, int value) {
	
	return ( !v.empty() && binary_search_helper(v, value, 0, v.size()) ); // the right operand of the && operator
	// is only evaluated if the left operand evaluates to true.
}