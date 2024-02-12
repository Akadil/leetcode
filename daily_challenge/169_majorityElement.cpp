#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int, int>   myMap;
        int              max_index = -1;

        // traverse through the values of nums
        for (int i = 0; i < nums.size(); ++i) {
            // fill the book with values
            if (myMap.contains(nums[i])) {
                myMap[nums[i]] += 1;
            } else {
                myMap[nums[i]] = 1;
            }

            // update the maximum number
            if (max_index == -1) {
                max_index = i;
            } else {
                if (myMap[nums[i]] > myMap[nums[max_index]])
                    max_index = i;
            }
        }
        return (nums[max_index]);
    }
};