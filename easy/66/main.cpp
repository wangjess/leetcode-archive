//https://leetcode.com/problems/plus-one/description/?difficulty=EASY
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// O(n) time complexity
// O(1) space
vector<int> plusOne(vector<int>& digits) {
	int n = digits.size() - 1;

	for (int i = n; i >= 0; i--) {
		if (digits[i] == 9) {
			digits[i] = 0;
		} else {
			digits[i] += 1;
			return digits;
		}
	}

	digits.push_back(0);
	digits[0] = 1;
	return digits;
}

int main() {
	// Example 1
	vector<int> digits1 = {1, 2, 3};
	vector<int> sol1 = {1, 2, 4};

	// Example 2
	vector<int> digits2 = {4, 3, 2, 1};
	vector<int> sol2 = {4, 3, 2, 2};

	// Example 3
	vector<int> digits3 = {9};
	vector<int> sol3 = {1, 0};

	// Testing ...
	vector<int> mysol1 = plusOne(digits1);
	vector<int> mysol2 = plusOne(digits2);
	vector<int> mysol3 = plusOne(digits3);

	assert(sol1 == mysol1);
	assert(sol2 == mysol2);
	assert(sol3 == mysol3);

	return 0;
}
