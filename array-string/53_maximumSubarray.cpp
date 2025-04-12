#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = -10000;

        for (auto num : nums) {
            currSum = max(currSum, 0);
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return (maxSum);
    }
};