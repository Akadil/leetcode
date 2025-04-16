#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int l = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                // if duplicate, don't move left pointer
                if (r != 0 && nums[r] != nums[r - 1])
                    l++;
    
                if (l != r) // removed redundant assignations
                    nums[l] = nums[r];
            }
            return l + 1;
        }
    };