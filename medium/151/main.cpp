//https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=leetcode-75

#include <sstream>
#include <cassert>

using namespace std;

// O(n) time
// O(n) space
string reverseWords(string s) {
	istringstream iss(s);
	string word;
	vector<string> words;

	while (iss >> word) {
		words.push_back(word);
	}

	string reversed;
	for (int i = words.size() - 1; i >= 0; i--) {
		reversed += words[i] + (i > 0 ? " " : "");
	}

	return reversed;
}

int main() {
	// Example 1
	string s1 = "the sky is blue";
	string s1_sol = "blue is sky the";

	// Example 2
	string s2 = "   hello world  ";
	string s2_sol = "world hello";

	// Example 3
	string s3 = "a good     example";
	string s3_sol = "example good a";

	string my_s1_sol = reverseWords(s1);
	string my_s2_sol = reverseWords(s2);
	string my_s3_sol = reverseWords(s3);

	assert(s1_sol == my_s1_sol);
	assert(s2_sol == my_s2_sol);
	assert(s3_sol == my_s3_sol);


	return 0;
}
