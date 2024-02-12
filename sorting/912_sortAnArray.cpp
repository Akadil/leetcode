#include <vector>

using namespace std;

class Solution {
public:
    // vector<int> sortArray_insertion(vector<int>& nums) {
    //     for (int i = 1; i < nums.size(); ++i) {
    //         int j = i;
    //         while (j != 0 && nums[j - 1] > nums[j]) {
    //             int temp = nums[j];

    //             nums[j] = nums[j - 1];
    //             nums[j - 1] = temp;
    //             j--;
    //         }
    //     }
    //     return (nums);
    // }

    void    sortArray_merge(vector<int>& nums, int i_begin, int i_middle, int i_end) {
        vector<int> array_left(nums.begin() + i_begin, nums.begin() + i_middle + 1);
        vector<int> array_right(nums.begin() + i_middle + 1, nums.begin() + i_end + 1);
    
        int j_left = 0;
        int j_right = 0;
        int k = i_begin;

        while (j_left != array_left.size() && j_right != array_right.size()) {
            if (array_left[j_left] < array_right[j_right]) 
                nums[k++] = array_left[j_left++];
            else 
                nums[k++] = array_right[j_right++];
        }

        while (j_left != array_left.size())
            nums[k++] = array_left[j_left++];
        while (j_right != array_right.size())
            nums[k++] = array_right[j_right++];
    }

    void sortArray_mergeSort(vector<int>& nums, int i_begin, int i_end) {
        if (i_begin == i_end)
            return ;

        int i_middle = (i_end - i_begin) / 2 + i_begin;

        sortArray_mergeSort(nums, i_begin, i_middle);
        sortArray_mergeSort(nums, i_middle + 1, i_end);
        sortArray_merge(nums, i_begin, i_middle, i_end);
        return ;
    }

    vector<int> sortArray(vector<int>& nums) {
        sortArray_mergeSort(nums, 0, nums.size() -1);
        return (nums);
    }
};