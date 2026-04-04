//https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>

using namespace std;

// O(n) time
// O(1) space
// Two-pointer approach
// Basic area calculation
// If both heights are same, we arbitrarily move ptrA
// Checks every pair
int maxArea(vector<int>& height) {
    int max_area = INT_MIN;
    int size = height.size();
    int ptrB = size - 1;

    for (int ptrA = 0; ptrA < size && ptrA < ptrB; ) {
        int dist = ptrB - ptrA;
        int minH = min(height[ptrA], height[ptrB]);

        max_area = max((dist * minH), max_area);

        if (height[ptrA] <= height[ptrB]) {
            ptrA++;
        } else {
            ptrB--;
        }
    }

    return max_area;
}

int main() {
    // Example 1
    vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Example 2
    vector<int> v2 = {1, 1};

    int ans1 = maxArea(v1);
    int ans2 = maxArea(v2);

    assert(ans1 == 49);
    assert(ans2 == 1);

    return 0;
}