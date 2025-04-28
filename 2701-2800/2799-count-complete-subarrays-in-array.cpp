#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            // Step 1: record all available numbers
            unordered_set<int>  all_numbers;
    
            for (int num : nums) {
                all_numbers.insert(num);
            }
    
            // Step 2: sliding window
            unordered_map<int, int> window; // number to its num of occurences
            int ans = 0, l = 0;
    
            for (int r = 0; r < nums.size(); ++r) {
                window[nums[r]]++;
    
                // if (window.size() == all_numbers.size())
                //     ans += nums.size() - r;
    
                while (!window.empty() && window.size() == all_numbers.size()) {
                    ans += nums.size() - r;
                    delete_from_window(window, nums[l++]);
                }
            }
            return ans;
        }
    
        void    delete_from_window(unordered_map<int, int>& window, int num) {
            if (window[num] > 1)
                window[num]--;
            else
                window.erase(num);
        }
    };