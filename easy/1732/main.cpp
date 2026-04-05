//https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>

using namespace std;

// O(n) time
// O(1) space
int largestAltitude(vector<int>& gain) {
    int max_alt = 0;
    int previous_sum = 0;

    for (int i = 0; i < gain.size(); i++) {
        previous_sum += gain[i];

        max_alt = max(previous_sum, max_alt);
    }

    return max_alt;
}

int main() {
    // Example 1
    vector<int> v1 = {-5, 1, 5, 0, -7};

    // Example 2
    vector<int> v2 = {-4, -3, -2, -1, 4, 3, 2};

    assert(1 == largestAltitude(v1));
    assert(0 == largestAltitude(v2));

    return 0;
}