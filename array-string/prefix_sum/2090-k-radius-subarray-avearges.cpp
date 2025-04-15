#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> getAverages(vector<int>& nums, int k) {
            // Step 1: identify the sum of first k-radius avg
            long r_sum = 0;
            for (int i = 0; i < 2 * k + 1 && i < nums.size(); i++) {
                r_sum += nums[i];    
            }
            
            // Step 2: iterate through
            vector<int> ans;
            
            long l_sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (i - k < 0 || i + k >= nums.size()) 
                    ans.push_back(-1);
                else {
                    ans.push_back((r_sum - l_sum) / (2 * k + 1));
                    l_sum += nums[i - k];
                    if (i + k + 1 < nums.size())
                        r_sum += nums[i + k + 1];
                }
            }
            return (ans);
        }
    };