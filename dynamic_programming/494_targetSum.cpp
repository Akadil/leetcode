#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, target, 0, 0);
    }

private:
    map<pair<int, int>, int> dp;
    
    int backtrack(vector<int>& nums, int target, int i, int total) {
        if (i == nums.size()) {
            return total == target ? 1 : 0;
        }
        if (dp.find({i, total}) != dp.end()) {
            return dp[{i, total}];
        }
        
        dp[{i, total}] = backtrack(nums, target, i + 1, total + nums[i])
                       + backtrack(nums, target, i + 1, total - nums[i]);
        
        return dp[{i, total}];
    }

    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int sum = 0;
    //     for (unsigned int i = 0; i < nums.size(); ++i)
    //         sum += nums[i];

    //     if (sum < target)
    //         return 0;

    //     // vector<vector<int>> map (nums.size(), vector<int>(nums));
    //     vector<unordered_map<int, int>> map (nums.size(), unordered_map<int, int>());

    //     return (dfs(nums, map, 0, sum, target));
    // }

    // int dfs(vector<int>& nums, vector<unordered_map<int, int>>& map, int index, int sum, int target) {
    //     if (index == nums.size()) {
    //         if (sum == target) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }

    //     int result[2];

    //     if (map[index].find(sum) == map[index].end()) {
    //         result[0] = dfs(nums, map, index + 1, sum - 2 * nums[index], target);
    //         result[1] = dfs(nums, map, index + 1, sum, target);
    //     } else {
    //         return map[index][sum];
    //     }

    //     return (result[0] + result[1]);
    // }
};