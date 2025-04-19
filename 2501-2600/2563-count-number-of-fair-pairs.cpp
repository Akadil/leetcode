#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            long long count = 0;
    
            for (int i = 0; i < n; ++i) {
                int lo = lower - nums[i]; // Lower bound for nums[j]
                int hi = upper - nums[i]; // Upper bound for nums[j]
    
                // Binary search to find the range of j's in nums[i+1:] that satisfy the condition
                auto left = lower_bound(nums.begin() + i + 1, nums.end(), lo); // First element >= lo
                auto right = upper_bound(nums.begin() + i + 1, nums.end(), hi); // First element > hi
    
                count += distance(left, right);  // Number of valid j's for the current i
            }
    
            return count;
        }
    };