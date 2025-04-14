#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief 209. Minimum Size Subarray Sum
     * 
     * Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray 
     * [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
     */
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 2147483647;
        int sum = 0;
        int l = 0;

        // Sliding window
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];

            // Shrink the window until the window is valid
            while (sum >= target) {
                if (sum >= target)
                    length = min(length, r - l + 1);
                sum -= nums[l++];
            }
        }
        return (length == 2147483647) ? 0 : length;
    }
};