#include <vector>

using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            int l = 0;
            long long curr_sum = 0;
            long long ans = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                curr_sum += nums[r];
    
                while (curr_sum != 0 && curr_sum * (r - l + 1) >= k) {
                    curr_sum -= nums[l];
                    l++;
                }
    
                if (l != r + 1) {
                    // cout << "l: " << l << ", r: " << r << endl;
                    ans += (r - l + 1);
                }
            }
            return ans;
        }
    };