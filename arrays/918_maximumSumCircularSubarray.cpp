#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int currSumMax = -30000;
        int minSum = nums[0];
        int currSumMin = 30000;
        int total = 0;

        for (auto num : nums) {
            currSumMax = max(currSumMax + num, num);
            currSumMin = min(currSumMin + num, num);

            total += num;

            maxSum = max(maxSum, currSumMax);
            minSum = min(minSum, currSumMin);
        }
        if (maxSum <= 0)
            return (maxSum);
        if (total - minSum > maxSum)
            return (total - minSum);
        return (maxSum);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-3, -2, -3};
    cout << solution.maxSubarraySumCircular(nums) << endl;
    return 0;
}