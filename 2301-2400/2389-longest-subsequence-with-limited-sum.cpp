#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    public:
        vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
            // Preprocess: create a prefix of a sorted array
            vector<int> prefix(nums.size());
    
            int sum = 0;
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i];
                prefix[i] = sum;
                // cout << ": " << sum << endl;
            }
    
    
            // Step 1: with binary search, find the sum that is less or equal to q[i]
            vector<int> ans(queries.size(), 0);
    
            for (int i = 0; i < queries.size(); ++i) {
                ans[i] = binary_search(prefix, queries[i]);
            }
            return ans;
        }
    
        int binary_search(vector<int>& nums, int target) {
            int l = 0; 
            int r = nums.size();
    
            while (l < r) {
               
                int mid = l + (r - l) / 2;
    
                if (target < nums[mid])
                    r = mid;
                else 
                    l = mid + 1;
                // cout << "l: " << l << ", r: " << r << endl;
            }
            // cout << endl;
            return l;
        }
    };