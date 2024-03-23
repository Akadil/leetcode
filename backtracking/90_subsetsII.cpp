#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> returner;
        vector<int>         curr;

        recursion(returner, nums, curr, 0);
        
        return (returner);
    }

private:
    void    recursion(vector<vector<int>>& returner, vector<int>& nums, vector<int>& curr, int i) {
        if (i == nums.size()) {
            returner.push_back(curr);
            return ;
        }
    
        if (!curr.empty() && curr.back() == nums[i]) {
            curr.push_back(nums[i]);
            recursion(returner, nums, curr, i + 1);
            curr.pop_back();
            return ;
        }
    
        recursion(returner, nums, curr, i + 1);
        curr.push_back(nums[i]);
        recursion(returner, nums, curr, i + 1);
        curr.pop_back();
    }
};