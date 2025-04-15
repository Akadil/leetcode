#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int l = 0;
            int ans = 0;
            int used_bits = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                while ((used_bits & nums[r]) != 0)
                    used_bits ^= nums[l++];
    
                used_bits |= nums[r];
    
                ans = max(ans, r - l + 1);
            }
            return ans;
        }
};