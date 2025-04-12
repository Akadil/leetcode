#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Save our previous numbers
        unordered_map<int, int> memory;

        // Add the variables inside of hash
        for (unsigned int i = 0; i < min(k, (int)nums.size()); ++i) {
            if (memory.find(nums[i]) != memory.end())
                return (true);
            memory[nums[i]] = 1;
        }

        // Traverse through the vector
        for (unsigned int i = min(k, (int)nums.size()); i < nums.size(); ++i) {
            if (memory.find(nums[i]) != memory.end())
                return (true);
            memory[nums[i]] = 1;
            memory.erase(nums[i - k]);
        }
        return (false);
    }
};