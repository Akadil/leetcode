#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
    *   @brief      search the matrix
    *
    *   @details    1. traverse through rows, 2. Traverse through values of a row
    *
    *   @todo       There is even shorter solution. We can see that the 
                    numbers are in ascending order, so if we take l_index = 0, 
                    r_index = n * m - 1, we can do it even shorter
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return (false);

        int l_index = 0;
        int r_index = matrix.size() - 1;
        int row_index = -1;

        // Traverse through the rows
        while (l_index <= r_index) {
            int mid_index = (l_index + r_index) / 2;

            if (isInRow(matrix, mid_index, target) == true) {
                row_index= mid_index;
                break;
            }
            else if (target < matrix[mid_index][0]) {
                r_index = mid_index - 1;
            }
            else {                                  // target > nums[mid_index][0]
                l_index = mid_index + 1;
            }
        }

        if (row_index == -1)
            return (false);

        // Use binary search to find the index
        if (binarySearch(matrix[row_index], target) == true)
            return (true);
        return (false);
    }

    bool    binarySearch(vector<int>& nums, int target) {
        
        // Debug: nums = [-1], target = 2 
        int l_index = 0;    // 0
        int r_index = nums.size() - 1;  // 1

        while (l_index <= r_index) {    // 0 <= 1
            int mid_index = (r_index + l_index) / 2;    // 0

            if (target < nums[mid_index]) {
                r_index = mid_index - 1;
            }
            else if (target > nums[mid_index]) {    // 2 > -1
                l_index = mid_index + 1;    // 0 -> 1
            }
            else {
                return (true);
            }
        }
        return (false);
    }

    /**
    *   @brief  check if the "target" is in the given row "[index]" by checking the first 
                value "[0]" of the next row "[index + 1]"
    */
    bool isInRow(vector<vector<int>>& matrix, int index, int target) {
        if (target >= matrix[index][0]) {
            if (index == matrix.size() - 1)
                return (true);
            if (target < matrix[index + 1][0])
                return (true);
        }
        return (false);
    }
};