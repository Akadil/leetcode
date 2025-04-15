#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // Preprocess: sort the values 
            sort(nums.begin(), nums.end());
    
            // Start the algorithm
            vector<vector<int>> ans;
    
            // iterate through fixed valud
            for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) { // non descreasing feature 
                if (i != 0 && nums[i] == nums[i - 1]) // avoid duplicates
                    continue;
    
                // run regular 2sum algorithm for target = -nums[i]
                two_sum(nums, i, ans);
            }
            return ans;
        }
    
        void    two_sum(vector<int>& nums, int i, vector<vector<int>>& ans) {
            int target = -1 * nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
    
            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    
                    // avoid duplicates
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                } else if (sum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    };