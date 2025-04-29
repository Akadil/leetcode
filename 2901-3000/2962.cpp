#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // 2962. Count Subarrays with Fixed Bounds
        // https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
        long long countSubarrays(vector<int>& nums, int k) {
            int max_elem = find_max_elem(nums);
    
            long long ans = 0;
            int l = 0, count = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                if (nums[r] == max_elem)
                    count++;
                
                while (l != r + 1 && count == k) {
                    // cout << "l: " << l << ", r: " << r << ". sum: " << nums.size() - r << endl;
                    ans += nums.size() - r;
                    if (nums[l++] == max_elem)
                        count--;
                }
            }
            return ans;
        }
    
        int find_max_elem(vector<int>& nums) {
            int max = 0;
    
            for (int& num : nums) {
                max = std::max(max, num);
            }
            // cout << "Max is " << max << endl;
            return max;
        }
    };