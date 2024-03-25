#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;

        for (unsigned int i = 0; i < nums.size(); ++i)
            target += nums[i];

        if (target % 2 == 1) {
            return false;
        }
        target = target / 2;

        unordered_set<int>  dp;
        dp.insert(0);

        for (unsigned int i = 0; i < nums.size(); ++i) {

            unordered_set<int>  dp_next;
            for (auto iter = dp.begin(); iter != dp.end(); iter++) {
                if (*iter + nums[i] == target)
                    return true;
                
                dp_next.insert(*iter + nums[i]);
                dp_next.insert(*iter);
            }

            dp = dp_next;
        }
        return false;
    }
};