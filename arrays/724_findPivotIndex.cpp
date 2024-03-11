#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for(int x: nums){
            total += x;
        }
        
        int leftSum = 0;
        int rightSum;

        for(int i = 0; i < nums.size(); i++){
            rightSum = total - nums[i] - leftSum;

            if(leftSum == rightSum){
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};