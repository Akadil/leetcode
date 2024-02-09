#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> returner(nums.size() * 2);

        for (int i = 0; i < nums.size(); i++) {
            returner[i] = nums[i];
            returner[i + nums.size()] = nums[i];
        }
        return (returner);
    }
};

/**
 * @brief Concantenation of an array
 * 
 * @link https://leetcode.com/problems/concatenation-of-array/description/
 * 
 * @result 93.8% speed, 21.1% memory
 * 
 */

