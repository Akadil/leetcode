#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // Debug: nums = [-1], target = 2 
        int l_index = 0;    // 0
        int r_index = nums.size() - 1;  // 1

        while (l_index <= r_index) {    // 0 <= 1
            int mid_index = (r_index + l_index) / 2;    // 0

            if (target < nums[mid_index]) {
                r_index = mid_index - 1;
            }
            else if (target > nums[mid_index]) {    // 2 > -1
                l_index = mid_index + 1;    // 0 -> 1
            }
            else {
                return (mid_index);
            }
        }
        return (-1);
    }
};