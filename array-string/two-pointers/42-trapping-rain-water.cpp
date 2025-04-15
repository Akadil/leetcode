#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
            int water_level = min(height[l], height[r]);
            int sum = 0;
    
            while (l < r) {
                // 1. collect water drops
                if (water_level > min(height[l], height[r])) {
                    if (height[l] < height[r]) 
                        sum += water_level - height[l];
                    else 
                        sum += water_level - height[r];
                }
    
                // 2. set new water level
                water_level = max(water_level, min(height[l], height[r]));
    
                // 3. move the pointers
                if (height[l] < height[r])
                    ++l;
                else
                    --r;
            }
            return sum;
        }
    };