//https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include <climits>
#include <vector>
#include <cassert>

using namespace std;

// O(n) time
// O(1) space
// Greedy solution
bool increasingTriplet(vector<int>& nums) {
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int n : nums) {
        if (n <= min1) {
            min1 = n;
        }
        else if (n <= min2) {
            min2 = n;
        }
        else {
            return true;
        }
    }

    return false;
}

int main() {
    // Example 1
    vector<int> v1 = {1, 2, 3, 4, 5};

    // Example 2
    vector<int> v2 = {5, 4, 3, 2, 1};

    // Example 3
    vector<int> v3 = {2, 1, 5, 0, 4, 6};
    
    // Example 4
    vector<int> v4 = {20, 100, 10, 12, 5, 13};

    assert(increasingTriplet(v1) == true);
    assert(increasingTriplet(v2) == false);
    assert(increasingTriplet(v3) == true);
    assert(increasingTriplet(v4) == true);

    return 0;
}