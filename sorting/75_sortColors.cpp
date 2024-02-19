#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int myBucket[3] = {0};


        for (int i = 0; i < nums.size(); ++i) {
            ++myBucket[nums[i]];
        }

        int k = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < myBucket[i]; ++j) {
                nums[k] = i;
                ++k;
            }
        }
    }
};