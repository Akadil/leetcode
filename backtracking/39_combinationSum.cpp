#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currVector;


        backtracking(candidates, currVector, 0, target);
        return (returner);
    }

private:

    vector<vector<int>> returner;

    void    backtracking(vector<int>& candidates, vector<int>& currVector, int index, int target) {
        if (index == candidates.size() || target < 0)
            return ;
        if (target == 0) {
            returner.push_back(currVector);
            return ;
        }

        currVector.push_back(candidates[index]);
        backtracking(candidates, currVector, index, target - candidates[index]);

        currVector.pop_back();
        backtracking(candidates, currVector, index + 1, target);
    }
};