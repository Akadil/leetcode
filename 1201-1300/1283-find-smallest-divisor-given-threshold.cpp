#include <iostream>

using namespace std;

class Solution {
    public:
        int smallestDivisor(vector<int>& nums, int threshold) {
            // Step 1: find upper bound
            int r = 0;
    
            for (int& num: nums) {
                r = max(r, num);
            }
    
            // Step 2: binary search to find the smallest divisor
            int l = 1;
    
            while (l < r) {
                int mid = l + (r - l) / 2;
    
                if (threshold < get_sum_after_divison(nums, mid)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
                // cout << "l: " << l << ", r: " << r << endl;
            }
            return l;
        }
    
        int get_sum_after_divison(vector<int>& nums, int divisor) {
            int sum = 0;
    
            for (int &num : nums) {
                sum += ceil((double)num / divisor);
            }
            // cout << "sum: " << sum << endl;
            return sum;
        }
    };