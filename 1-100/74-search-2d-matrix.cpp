#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int num_r = matrix.size();
            int num_c = matrix[0].size();
    
            // find good row
            int l = 0;
            int r = num_r;
    
            while (l < r) {
                int mid = l + (r - l) / 2;
    
                if (target == matrix[mid][num_c - 1])
                    return true;
                else if (target > matrix[mid][num_c - 1])
                    l = mid + 1;
                else 
                    r = mid;
            }
            int row = l;
            if (row == num_r)
                return false;
    
            // find good column
            l = 0;
            r = num_c;
    
            while (l < r) {
                int mid = l + (r - l) / 2;
    
                if (target == matrix[row][mid])
                    return true;
                else if (target > matrix[row][mid])
                    l = mid + 1;
                else
                    r = mid;
            }
            return false;
        }
    };