#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void    myFindKthLargest(vector<int>& nums, int k, int i_start, int i_end) {
        if (i_start == i_end)
            return ;

        // Choose a random pivot position
        // int randomIndex = i_start + rand() % (i_end - i_start + 1);
        // swap(nums, randomIndex, i_end);

        int pivot = nums[i_end];
        int i_left = i_start;
    
        // Partition: position lower numbers on the left side
        for (int i = i_start; i < i_end; ++i) {
            if (nums[i] > pivot) {
                // if (i != i_left)
                swap(nums[i], nums[i_left]);
                ++i_left;
            }
        }

        // Position the pivot position in corresponding place
        swap(nums[i_left], nums[i_end]);

        // Conquer the divided region
        if (i_left + 1 < k)
            myFindKthLargest(nums, k, i_left + 1, i_end);
        else if (i_left + 1 > k)
            myFindKthLargest(nums, k, i_start, i_left - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        myFindKthLargest(nums, k, 0, nums.size() - 1);
        
        return (nums[k - 1]);
    }
};