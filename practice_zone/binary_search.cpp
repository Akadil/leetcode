#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (target > nums[mid])
            l = mid + 1;
        else // target <= nums[mid]
            r = mid;
    }
    return l;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 3;

    int index = binary_search(nums, target);
    cout << "The index of the first element greater than " << target << " is: " << index << endl;

    return 0;
}