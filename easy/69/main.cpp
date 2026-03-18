//https://leetcode.com/problems/sqrtx/description/?difficulty=EASY
#include <iostream>
#include <cassert>

int mySqrt(int x) {
	long r = x;

	while (r * r > x) {
		r = (r + x/r) / 2;
	}

	return r;
}

int main() {
	// Example 1
	int x = 4;
	int x_sol = 2;

	// Example 2
	int y = 8;
	int y_sol = 2;

	// Example 3
	int z = 9; 
	int z_sol = 3;

	// Testing...
	int sol1 = mySqrt(x);
	int sol2 = mySqrt(y);
	int sol3 = mySqrt(z);

	assert(sol1 == x_sol);
	assert(sol2 == y_sol);
	assert(sol3 == z_sol);

	return 0;
}
