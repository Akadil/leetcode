#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            // Preprocess: prefix sum
            long max = 0;
            long min = 0;
            long sum = 0;
            for (int num : differences) {
                sum += num;
                max = std::max(max, sum);
                min = std::min(min, sum);
            }
    
            // Step 1: identify how many valid combinations till lower and upper
            long sum_lower = -1 * (lower - min);
            long sum_higher = (upper - max + 1);
            // cout << sum_lower << " and " << sum_higher << endl;
    
            return std::max(int(sum_lower + sum_higher), 0);
        }
    };