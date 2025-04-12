#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> memory;
        int                     count = 0;  // Count number of appearences
        int                     sum = 0;    // prefix sum variable

        for (unsigned int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sum == k)
                count++;
            if (memory.find(sum - k) != memory.end())
                count += memory[sum - k];
            memory[sum]++;
        }
        return (count);
    }
};