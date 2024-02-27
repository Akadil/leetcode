#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for (unsigned int i = 0; i < nums.size(); ++i) {
            if (map[nums[i]] == 1) {
                return (true);
            }
            map[nums[i]] = 1;
        }
        return (false);
    }
};