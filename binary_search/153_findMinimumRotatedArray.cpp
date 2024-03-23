#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l_index = 0;
        int r_index = nums.size() - 1;

        while (l_index != r_index) {
            int m_index = (r_index + l_index) / 2;

            if (isSmallest(nums, m_index))
                return (nums[m_index]);
            
            if (nums[l_index] > nums[m_index])
                r_index = m_index - 1;
            else if (nums[m_index] > nums[r_index])
                l_index = m_index + 1;
            else
                r_index = m_index;
        }
        return (nums[l_index]);
    }

    bool    isSmallest(vector<int>& nums, int index) {
        int l_index = nums.size() - 1;
        if (nums.size() == 1)
            return (true);
        
        if (index == 0) {
            if (nums.back() > nums[index])
                return true; 
        }
        else if (index == l_index) {
            if (nums[l_index - 1] > nums[l_index])
                return true;
        }
        else if (nums[index - 1] > nums[index])
            return true;
        return false;
    }
};

int main(void) {
    Solution s;
    /*
        Recreate the case:
        1. 4 5 6 7 0 1 2
        2, [11,13,15,17]
        3. [2, 1]
    */
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums2 = {11, 13, 15, 17};
    vector<int> nums3 = {2, 1};
    cout << s.findMin(nums3) << endl;
    return (0);
}