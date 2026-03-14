//https://leetcode.com/problems/roman-to-integer/description/?difficulty=EASY
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

// O(n) time
// Hash table is constant size: O(1).
int romanToInt(string s) {
	int result = 0;
	unordered_map<char, int> roman_map = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000},
	};

	for (int i = 0; i < s.length() - 1; i++) {
		if (roman_map[s[i]] < roman_map[s[i + 1]]) {
			result -= roman_map[s[i]];
		} else {
			result += roman_map[s[i]];
		}
	}

	return result + roman_map[s[s.length() - 1]];
}

int main() {
	// Example 1
	string s1 = "III";

	// Example 2
	string s2 = "LVIII";

	// Example 3
	string s3 = "MCMXCIV";

	// Example 4 (custom)
	string s4 = "IV";

	// Testing...
	int sol1 = romanToInt(s1);
	int sol2 = romanToInt(s2);
	int sol3 = romanToInt(s3);
	int sol4 = romanToInt(s4);

	assert(sol4 == 4);
	assert(sol1 == 3);
	assert(sol2 == 58);
	assert(sol3 == 1994);

	return 0;
}

