#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // 
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> count; // count each remainder occurence
            
            long long ans = 0, prefix = 0;
        
            count[0] = 1; // empty array case
            for (int& num : nums) {
                prefix += (num % modulo == k);
    
                // x = (prefix - k + modulo) % modulo            
                ans += count[(prefix - k + modulo) % modulo];
    
                count[prefix % modulo]++;
            }
            return ans;
        }
    
        // Brute Force
        // long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        //     // Step 1: create a prefix array
        //     vector<int> prefix({0});
    
        //     cout << prefix[0] << ", ";
        //     for (int i = 0; i < nums.size(); ++i) {
        //         // bool interesting = nums[i] % modulo == k;
        //         prefix.push_back(prefix.back() + (nums[i] % modulo == k));
    
        //         // cout << prefix[i + 1] << ", ";
        //     }
        //     cout << endl;
    
        //     // Step 2: Brute force - check all possible arrays
        //     int ans = 0;
    
        //     for (int i = 0; i < nums.size() + 1; ++i) {
        //         for (int j = i + 1; j < nums.size() + 1; ++j) {
        //             if ((prefix[j] - prefix[i]) % modulo == k) {
        //                 // cout << "[" << i << ", " << j << "]" << endl;
        //                 ans++;
        //             }
        //         }
        //     }
        //     return ans;
        // }
    };