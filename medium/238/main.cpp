//https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan-v2&envId=leetcode-75

#include <vector>
#include <cassert>

using namespace std;

// O(n) time
// O(n) space
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix, suffix, result;
        suffix.reserve(nums.size());
        
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            product = (i > 0 ? product * nums[i-1] : 1);
            prefix.push_back(product);
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product = (i < nums.size() - 1 ? product * nums[i+1] : 1);
            suffix[i] = product;
        }

        for (int i = 0; i < nums.size(); i++) {
            result.push_back(prefix[i] * suffix[i]);
        }

        return result; 
}

int main() {
    // Example 1
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v1_sol = {24, 12, 8, 6};

    // Example 2
    vector<int> v2 = {-1, 1, 0, -3, 3};
    vector<int> v2_sol = {0, 0, 9, 0, 0};

    vector<int> my_v1_sol = productExceptSelf(v1);
    vector<int> my_v2_sol = productExceptSelf(v2);

    assert(my_v1_sol == v1_sol);
    assert(my_v2_sol == v2_sol);

    return 0;
}