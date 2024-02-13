#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void    sortArray_quickSort(vector<int>& nums, int i_start, int i_end) {
        /*
            sort using quicksort
        */
        if (i_start >= i_end)
            return ;
        
        // Choose a random pivot position
        int randomIndex = i_start + rand() % (i_end - i_start + 1);
        // int randomIndex = chooseRandomIndex(nums, i_start, i_end);
        swap(nums, randomIndex, i_end);

        int pivot = nums[i_end];
        int i_left = i_start;

        // Partition: position lower numbers on the left side
        for (int i = i_start; i < i_end; i++) {
            if (nums[i] < pivot) {
                if (i != i_left)
                    swap(nums, i, i_left);
                i_left++;
            }
        }

        // Position the pivot position in corresponding place
        swap(nums, i_left, i_end);

        // Conquer the divided region
        sortArray_quickSort(nums, i_start, i_left - 1);
        sortArray_quickSort(nums, i_left + 1, i_end);
    }

    void    swap(vector<int>& nums, int i_one, int i_two) {
        int temp;

        temp = nums[i_one];
        nums[i_one] = nums[i_two];
        nums[i_two] = temp;
    }

    int     chooseRandomIndex(vector<int> &nums, int i_start, int i_end) {
        int index1 = i_start + rand() % (i_end - i_start + 1);
        int index2 = (i_end + i_start) / 2;

        int lowestIndex = index1;

        // Compare the values at index2, index3, and index4
        if (nums[index2] < nums[lowestIndex]) {
            lowestIndex = index2;
        }
        if (nums[i_start] < nums[lowestIndex]) {
            lowestIndex = i_start;
        }
        if (nums[i_end] < nums[lowestIndex]) {
            lowestIndex = i_end;
        }
        return(lowestIndex);
    }
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

    // void    sortArray_merge(vector<int>& nums, int i_begin, int i_middle, int i_end) {
    //     vector<int> array_left(nums.begin() + i_begin, nums.begin() + i_middle + 1);
    //     vector<int> array_right(nums.begin() + i_middle + 1, nums.begin() + i_end + 1);
    
    //     int j_left = 0;
    //     int j_right = 0;
    //     int k = i_begin;

    //     while (j_left != array_left.size() && j_right != array_right.size()) {
    //         if (array_left[j_left] < array_right[j_right]) 
    //             nums[k++] = array_left[j_left++];
    //         else 
    //             nums[k++] = array_right[j_right++];
    //     }

    //     while (j_left != array_left.size())
    //         nums[k++] = array_left[j_left++];
    //     while (j_right != array_right.size())
    //         nums[k++] = array_right[j_right++];
    // }

    // void sortArray_mergeSort(vector<int>& nums, int i_begin, int i_end) {
    //     if (i_begin == i_end)
    //         return ;

    //     int i_middle = (i_end - i_begin) / 2 + i_begin;

    //     sortArray_mergeSort(nums, i_begin, i_middle);
    //     sortArray_mergeSort(nums, i_middle + 1, i_end);
    //     sortArray_merge(nums, i_begin, i_middle, i_end);
    //     return ;
    // }

    vector<int> sortArray(vector<int>& nums) {
        // sortArray_insertion(nums);
        // sortArray_mergeSort(nums, 0, nums.size() -1);
        sortArray_quickSort(nums, 0, nums.size() - 1);
        return (nums);
    }
};