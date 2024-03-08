#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;

        while (l <= r) {

            if (nums[l] == nums[l - 1] && l - 2 >= 0 && nums[l] == nums[l - 2]) {
                int i = l;
                
                while (i != r + 1 && i != nums.size() - 1) {
                    nums[i] = nums[i + 1];
                    i++;
                }
                r--;
            }
            else {
                l++;
            }
        }
        return (r + 1);
    }
};