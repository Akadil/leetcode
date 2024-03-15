#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int longest = (nums.size() != 0) ? 1 : 0;
        int curr_length = 1;

        for (unsigned int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1) {
                curr_length++;
            } else {
                curr_length = 1;
            }
            longest = max(longest, curr_length);
        }
        return (longest);
    }
};