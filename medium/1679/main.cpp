//https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// O(nlogn) time -> sort()
// O(1) space
int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ptrA = 0, ptrB = nums.size() - 1;
    int pairs = 0;

    while (ptrA < ptrB) {
        int sum = nums[ptrA] + nums[ptrB];
        if (sum == k) {
            pairs++;
            ptrA++;
            ptrB--;
        } else if (sum <= k ) {
            ptrA++;
        } else {
            ptrB--;
        }
    }

    return pairs;
}

int main() {
    // Example 1
    vector<int> v1 = {1, 2, 3, 4};
    int k1 = 5;

    // Example 2
    vector<int> v2 = {3, 1, 3, 4, 3};
    int k2 = 6;

    assert(2 == maxOperations(v1, k1));
    assert(1 == maxOperations(v2, k2));

    return 0;
}