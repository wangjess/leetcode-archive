//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75

#include <string>
#include <cassert>
#include <unordered_set>

using namespace std;

// O(n * k) time -> Causes Time Limit Exceeded on exceptionally large inputs
// O(1) space
int maxVowels_Inefficient(string s, int k) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int ptrA = 0, ptrB = 0 + k - 1;
    int max_streak = 0;

    while (ptrB < s.length()) {
        int read = ptrA;
        int streak = 0;

        while (read <= ptrB) {
            if (vowels.contains(s[read])) { streak++; read++; }
            else { read++; }
        }

        max_streak = max(streak, max_streak);
        ptrA++;
        ptrB++;
    }

    return max_streak;
}

// O(n) time -> Efficient sliding window solution, maintains count
// O(1) space
int maxVowels(string s, int k) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int count = 0, max_streak = 0;

    for (int i = 0; i < k; i++) {
        if (vowels.contains(s[i])) { count++; }
    }

    max_streak = count;

    for (int i = k; i < s.length(); i++) {
        if (vowels.contains(s[i])) { count++; }
        if (vowels.contains(s[i-k])) { count--; }
        max_streak = max(max_streak, count);
    }

    return max_streak;
}

int main() {
    // Example 1
    string s1 = "abciiidef";
    int k1 = 3;

    // Example 2
    string s2 = "aeiou";
    int k2 = 2;

    // Example 3
    string s3 = "leetcode";
    int k3 = 2;

    assert(3 == maxVowels(s1, k1));
    assert(2 == maxVowels(s2, k2));
    assert(2 == maxVowels(s3, k3));

    return 0;
}