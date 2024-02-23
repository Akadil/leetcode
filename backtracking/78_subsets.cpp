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
};