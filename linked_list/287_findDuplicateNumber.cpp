#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            We are going to use that formula. The duplicate numver will be the entry point 
            of our cycle
        */
        int slow = nums[0];
        int fast = nums[nums[0]];

        // Detect the cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        // Use the formula
        int cop = 0;

        while (cop != slow) {
            cop = nums[cop];
            slow = nums[slow];
        }
        return (slow);
    }
};