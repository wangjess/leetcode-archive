//https://leetcode.com/problems/fizz-buzz/description/
#include <iostream>
#include <string>

using namespace std;

// Helper function
string divisible_by_what(int n) {
	string s;

	if (n % 3 == 0 && n % 5 == 0) {
		s = "FizzBuzz";	
	}
	else if (n % 3 == 0) {
		s = "Fizz";
	}
	else if (n % 5 == 0) {
		s = "Buzz";
	}
	else {
		s = to_string(n);
	}

	return s;
}

vector<string> fizzBuzz(int n) {
	vector<string> result;	
	result.reserve(n);

	for (int i = 1; i <= n; i++) {
		result.push_back(divisible_by_what(i));
	}

	return result;
}

void check_answer(vector<string> &vec1, vector<string> &vec2) {
	if (vec1 == vec2) {
		cout << "Equal\n";
		return;
	} else {
		cerr << "Failure\n";
	}
}

int main() {
	cout << "Init...\n";

	// Example 1
	int n1 = 3;
	vector<string> ans_1 = {"1", "2", "Fizz"};

	// Example 2
	int n2 = 5;
	vector<string> ans_2 = {"1", "2", "Fizz", "4", "Buzz"};

	// Example 3
	int n3 = 15;
	vector<string> ans_3 = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};

	// Testing
	vector<string> my_ans1 = fizzBuzz(n1);
	check_answer(ans_1, my_ans1);	

	vector<string> my_ans2 = fizzBuzz(n2);
	check_answer(ans_2, my_ans2);	

	vector<string> my_ans3 = fizzBuzz(n3);
	check_answer(ans_3, my_ans3);	

	return 0;
}
