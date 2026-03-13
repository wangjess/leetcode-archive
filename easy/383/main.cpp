//https://leetcode.com/problems/ransom-note/description/
#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

// O(m + n) time
// O(1) space; magazine's possible characters are lower-case English alphabets.
// This is a constant 26 characters.
bool canConstruct(string ransomNote, string magazine) {
	unordered_map<char, int> map;

	for (auto c : magazine) {
		map[c] += 1;
	}

	for (auto c : ransomNote) {
		auto it = map.find(c);
		if (it != map.end() && it->second >= 1) {
			map[c] -= 1;
		} else {
			return false;
		}
	}

	return true;
	// string::find()  -> O(n * m) time complexity 
	// string::erase() -> O(n) time complexity
	// Because this is doing repeated find + erase in a loop,
	// the total complexity becomes O(n^2 * m).
	/*
	for (auto c : ransomNote) {
		size_t pos = magazine.find(c); 
		if (pos != string::npos) {
			magazine.erase(pos, 1);
		} else {
			return false;
		}
	}

	return true;
	*/
}

int main() {
	// Example 1
	string ransomNote_1 = "a";
	string mag_1 = "b";

	// Example 2
	string ransomNote_2 = "aa";
	string mag_2 = "ab";

	// Example 3
	string ransomNote_3 = "aa";
	string mag_3 = "aab";

	// Example 4
	string ransomNote_4 = "bg";
	string mag_4 = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";

	// Testing...
	bool ans = canConstruct(ransomNote_1, mag_1);
	bool ans2 = canConstruct(ransomNote_2, mag_2);
	bool ans3 = canConstruct(ransomNote_3, mag_3);
	bool ans4 = canConstruct(ransomNote_4, mag_4);

	assert(ans == false);
	assert(ans2 == false);
	assert(ans3 == true);
	assert(ans4 == true);

	return 0;
}
