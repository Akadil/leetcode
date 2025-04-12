#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 2147483647;
        int sum = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum >= target) {
                if (sum >= target)
                    length = min(length, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return (length == 2147483647) ? 0 : length;
    }
};