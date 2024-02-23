#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >    returner = {{}};

        for (unsigned int i = 0; i < nums.size(); ++i) {
            int currSize = returner.size();

            for (unsigned j = 0; j < currSize; ++j) {
                vector<int> newVector(returner[j]);
                
                newVector.push_back(nums[i]);
                returner.push_back(newVector);
            }
        }
        return (returner);
    }

    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int> >    returner;
    //     vector<int>             current;

    //     dfs(returner, current, 0, nums);
    //     return (returner);
    // }

    // void    dfs(vector<vector<int> >& returner, vector<int>& current, int index, vector<int>& nums) {
    //     returner.push_back(current);

    //     for (unsigned int i = index; i < nums.size(); i++) {
    //         current.push_back(nums[i]);
    //         dfs(returner, current, i + 1, nums);
    //         current.pop_back();
    //     }
    // }
};