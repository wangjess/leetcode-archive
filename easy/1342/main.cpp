//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/
#include <iostream>

using namespace std;

int numberOfSteps(int num) {
	int steps = 0;

	while (num != 0) {
		// Bit-wise arithmetic. This is faster than modulo on modern compilers/CPUs.
		// Modulo takes 20-30 cycles on x86; Bit-wise takes 1 cycle.
		if ((num & 1) == 0) {
		// Modulo operator
		//if(num % 2 == 0) { 
			num /= 2;

		} else {
			num -= 1;

		}

		steps += 1;
	}

	return steps;
}

void check_answer(int a, int b) {
	if (a == b) {
		cout << "Equal\n";
	} else {
		cerr << "Failure\n";
	}
}

int main() {
	cout << "Init...\n";

	// Example 1
	int ex_1 = 14;
	int ans_1 = 6;

	// Example 2
	int ex_2 = 8;
	int ans_2 = 4;

	// Example 3
	int ex_3 = 123;
	int ans_3 = 12;

	// Testing...
	int steps_1 = numberOfSteps(ex_1);
	check_answer(steps_1, ans_1);

	int steps_2 = numberOfSteps(ex_2);
	check_answer(steps_2, ans_2);

	int steps_3 = numberOfSteps(ex_3);
	check_answer(steps_3, ans_3);

	return 0;
}
