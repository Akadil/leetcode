#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int sum = 0;
        int waterLevel = min(height[l], height[r]);

        while (l < r) {
            if (min(height[l], height[r]) < waterLevel) {
                if (waterLevel > height[l]) {
                    sum += waterLevel - height[l];
                } else {                                //  waterLevel > height[r]
                    sum += waterLevel - height[r];
                }
            }
            waterLevel = max(waterLevel, min(height[l], height[r]));
            if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return (sum);
    }
};

int main(void) {
    // Create a test case:
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution solution;

    int result = solution.trap(height);
    cout << "Result: " << result << endl;
    return 0;
       
}