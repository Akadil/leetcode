#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        /// use binary search to find the maximum total sweatness 
        int maximizeSweetness(vector<int>& sweetness, int k) {
            // remove all edge cases
    
            // Step 1: calculate upper bound
            int r = get_sum(sweetness) / (k + 1) + 1; // +1 because not inclusive
    
            // Step 2: run binary search (not inclusive)
            int l = 1;
    
            while (l < r) {
                int mid = l + (r + 1 - l) / 2;
                // cout << "l: " << l << ", r: " << r << ", mid: " << mid << endl;
    
                if (is_valid(sweetness, mid, k + 1))
                    l = mid;
                else
                    r = mid - 1;
            }
            return l;
        }
    
        bool    is_valid(vector<int>& nums, int sweetness_level, int num_friends) {
            int i = 0; // track current index
    
            while (num_friends != 0) {
                // get enough portion for all your friends
                int sweetness_portion = 0;
                
                while (sweetness_portion < sweetness_level) {
                    if (i == nums.size())
                        return false;
                    sweetness_portion += nums[i++];
                }
                num_friends--;
            }
            return true;
        }
    
        int get_sum(vector<int>& nums) {
            int sum = 0;
            for (int& num : nums)
                sum += num;
            return sum;
        }
    };