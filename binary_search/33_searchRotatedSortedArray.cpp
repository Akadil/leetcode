#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l_index = 0;
        int r_index = nums.size() - 1;

        while (l_index <= r_index) {
            int m_index = l_index + (r_index - l_index) / 2;

            if (nums[m_index] == target)
                return (m_index);

            if (nums[l_index] <= nums[m_index]) {
                if (nums[l_index] <= target && target <= nums[m_index])
                    r_index = m_index - 1;
                else
                    l_index = m_index + 1;
            }
            else {
                if (nums[m_index] <= target && target <= nums[r_index])
                    l_index = m_index + 1;
                else
                    r_index = m_index - 1;
            }
        }
        return (-1);
    }
};