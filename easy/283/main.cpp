//https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>

using namespace std;

// O(n^2) time -> each erase() shifts the values in the vector over
// O(1) space
// Unoptimal answer, optimized result at the bottom
void moveZeroes_Inefficient(vector<int>& nums) {
    int zeroes = 0;

    for (auto it = nums.begin(); it != nums.end(); ) {
        if (*it == 0) {
            it = nums.erase(it);
            zeroes++;
        } else {
            it++;
        }
    }

    while (zeroes > 0) {
        nums.push_back(0);
        zeroes--;
    }
}

// O(n) time
// O(1) space
void moveZeroes(vector<int>& nums) {
    int write = 0;
    int size = nums.size();

    for (int read = 0; read < size; read++) {
        if (nums[read] != 0) {
            nums[write++] = nums[read];
        }
    }

    while (write < size) {
        nums[write++] = 0;
    }
}

int main() {
    // Example 1
    vector<int> v1 = {0, 1, 0, 3, 12};
    vector<int> v1_sol = {1, 3, 12, 0, 0};

    // Example 2
    vector<int> v2= {0};
    vector<int> v2_sol = {0};

    moveZeroes(v1);
    moveZeroes(v2);

    assert(v1_sol == v1);
    assert(v2_sol == v2);

    return 0;
}