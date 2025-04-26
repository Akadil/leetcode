#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        /**
        *   [solved] edge case: I don't take the last array
        */
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            // Find a potential valid array that doesn't contain outer bound values
            this->minK = minK; this->maxK = maxK;
            long long ans = 0, l = 0;
    
            for (int r = 0; r < nums.size() + 1; ++r) {
                if (r == nums.size() || nums[r] < minK || nums[r] > maxK) {
                    // cout << "Starting the algo with [" << l << "," << r << "]\n";
                    ans += count_valid_arrays(nums, l, r);
                    l = r + 1;
                }
            }
            return ans;
        }
    
    private:
        int minK = 0;
        int maxK = 0;
    
        bool    is_outer_value(int num, int mindK, int maxK) {
            if (num < minK || num > maxK)
                return true;
            return false;
        }
    
        /**
        *   @param l_bound - nums[l_bound] is valid 
        *   @param r_bound - nums[r_bound] is invalid
        */
        long long count_valid_arrays(vector<int>& nums, int l_bound, int r_bound) {
            long long ans = 0;
            int l = l_bound, r = l_bound;
            queue<int>  pos_minK;
            queue<int>  pos_maxK;
    
            for (int r = l_bound; r != r_bound; ++r) {
                if (nums[r] == minK)
                    pos_minK.push(r);
                if (nums[r] == maxK)
                    pos_maxK.push(r);
    
                while (!pos_minK.empty() && !pos_maxK.empty()) {
                    ans += r_bound - r;
                    if (nums[l] == minK)
                        pos_minK.pop();
                    if (nums[l] == maxK)
                        pos_maxK.pop();
                    l++;
                }
            }
            return ans;
        }
    };