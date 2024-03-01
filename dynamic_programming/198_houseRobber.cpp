#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
        Imagine you have 2 houses, a and b. You can 3 choices:
            1. Rob a
            2. Rob b
            3. Don't rob any of them
        
        So I have to make a dp programming for that?

        Or no, i have to run the DP on if I rob the house or not. But it is just a recursion, 
        where is the memorization? 

        Again there is 2 approaches: bottom up, and top down.
            Bottom up - I take the last house, and the one before the last.
            top down - doesn't work. It is not applicable to our situation.

        But how much space do I want to give? I think it is 3. Because of 3 choices for a and b house
    */
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return (nums[0]);
        if (nums.size() == 2)
            return (max(nums[0], nums[1]));

        int result = 0;
        int dp[2] = {nums[0], max(nums[0], nums[1])};      // allowed to take

        for (unsigned int i = 2; i < nums.size(); ++i) {
            result = max(nums[i] + dp[0], dp[1]);

            dp[0] = dp[1];
            dp[1] = result;
        }

        return (result); 
    }
};