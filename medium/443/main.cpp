//https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>

using namespace std;

// O(n) time -> read visits each character once, picks up where left off
// O(1) space
int compress(vector<char>& chars) {
    int write = 0, n = chars.size();

    for (int read = 0; read < n; ) {
        char curr = chars[read];
        int streak = 0;
        while (read < n && chars[read] == curr) { read++; streak++; }
        chars[write++] = curr;
        if (streak > 1) {
            for (char c : to_string(streak)) chars[write++] = c; 
        }
    }

    return write;
}

int main() {
    // Example 1
    vector<char> v1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    // Example 2
    vector<char> v2 = {'a'};

    // Example 3
    vector<char> v3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};

    int v1_res = compress(v1);
    int v2_res = compress(v2);
    int v3_res = compress(v3);

    assert(v1_res == 6);
    assert(v2_res == 1);
    assert(v3_res == 4);

    return 0;
}