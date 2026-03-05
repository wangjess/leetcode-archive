// https://leetcode.com/problems/running-sum-of-1d-array/
#include <iostream>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
	int size = nums.size();

	vector<int> result;
	result.reserve(size);

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + nums[i];
		result.push_back(sum);
	}

	return result;
}

int main() {
	std::cout << "Init..." << std::endl;

	// Example 1
	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v1_sol = {1, 3, 6, 10};

	// Example 2
	vector<int> v2 = {1, 1, 1, 1, 1};
	vector<int> v2_sol = {1, 2, 3, 4, 5};

	// Example 3
	vector<int> v3 = {3, 1, 2, 10, 1};
	vector<int> v3_sol = {3, 4, 6, 16, 17};

	// Testing...
	vector<int> v1_m = runningSum(v1);
	if (v1_m != v1_sol) {
		std::cerr << "Test_1 failed\n";	
		return 1;
	} else {
		std::cout << "Equal\n";
	}

	vector<int> v2_m = runningSum(v2);
	if (v2_m != v2_sol) {
		std::cerr << "Test_2 failed\n";	
		return 1;
	} else {
		std::cout << "Equal\n";
	}

	vector<int> v3_m = runningSum(v3);
	if (v3_m != v3_sol) {
		std::cerr << "Test_3 failed\n";	
		return 1;
	} else {
		std::cout << "Equal\n";
	}

	return 0;
}
