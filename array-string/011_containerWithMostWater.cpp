#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;

        while (l < r) {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));

            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return (maxArea);
    }
};