#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>  returner;

        // Base step, first window
        for (int i = 0; i < k; ++i)
            addNum(nums[i]);
        returner.push_back(findMedian());

        // Inductive step, traverse through windows
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            removeNum(nums[i - 1]);
            removeToDelete();
            normalizeHeaps();
            addNum(nums[i + k - 1]);
            removeToDelete();
            returner.push_back(findMedian());
        }

        return (returner);
    }

    double findMedian() {
        if (lower_size > higher_size)
            return (lower.top());
        else if (lower_size < higher_size)
            return (higher.top());
        else
            return ((double)higher.top() / 2 + (double)lower.top() / 2);
    }

    void    removeToDelete() {
        while (lower.empty() == false && lower_toDelete[lower.top()] != 0) {
            lower_toDelete[lower.top()] -= 1;
            lower.pop();
        }
        while (higher.empty() == false && higher_toDelete[higher.top()] != 0) {
            higher_toDelete[higher.top()] -= 1;
            higher.pop();
        }
    }

    void    normalizeHeaps() {
        if (lower_size > higher_size + 1) {
            higher.push(lower.top());
            higher_size++;
            higher_contains[lower.top()] += 1;
            lower_contains[lower.top()] -= 1;
            lower.pop();
            lower_size--;
        }
        else if (higher_size > lower_size + 1) {
            lower.push(higher.top());
            lower_size++;
            lower_contains[higher.top()] += 1;
            higher_contains[higher.top()] -= 1;
            higher.pop();
            higher_size--;
        }
    }

    void removeNum(int myNum) {
        int size = 0;

        if (higher.empty() == false && higher_contains[myNum] != 0) {
            higher_toDelete[myNum] += 1;
            higher_size--;
            higher_contains[myNum] -= 1;

        }
        else if (lower.empty() == false) {
            lower_toDelete[myNum] += 1;
            lower_size--;
            lower_contains[myNum] -= 1;
        }
    }

    void addNum(int num) {
        if (lower_size == higher_size) {
            if (higher.empty() == false && num > higher.top()) {
                higher.push(num);
                higher_contains[num] += 1;
                higher_size++;
            }
            else { // num < lower.top() || (higher.top() > num > lower.top())
                lower.push(num);
                lower_contains[num] += 1;
                lower_size++;
            }  
        }
        else if (lower_size > higher_size) {
            if (lower.top() < num) {
                higher.push(num);
                higher_contains[num] += 1;
            }
            else {
                higher.push(lower.top());
                higher_contains[lower.top()] += 1;
                lower_contains[lower.top()] -= 1;
                lower.pop();
                lower.push(num);
                lower_contains[num] += 1;    
            }
            higher_size++;
        }
        else {  // lower.size() < higher.size()
            if (higher.top() > num) {
                lower.push(num);
                lower_contains[num] += 1;
            }
            else {
                lower.push(higher.top());
                lower_contains[higher.top()] += 1;
                higher_contains[higher.top()] -= 1;
                higher.pop();
                higher.push(num);
                higher_contains[num] += 1;
            }
            lower_size++;
        }
    }

private:
    priority_queue<int>                             lower;  // maxHeap, 0
    priority_queue<int, vector<int>, greater<int>>  higher; // minHeap, 1
    unordered_map<int, int>                         lower_contains;
    unordered_map<int, int>                         higher_contains;
    unordered_map<int, int>                         lower_toDelete;
    unordered_map<int, int>                         higher_toDelete;
    int                                             lower_size = 0;
    int                                             higher_size = 0;
};

int main(void) {
    // Recreate the example
    /*
        [1,3,-1,-3,5,3,6,7]
        [1,2,3,4,2,3,1,4,2]
        [7,9,3,8,0,2,4,8,3,9]
        [2147483647,1,2,3,4,5,6,7,2147483647]
        [9,7,0,3,9,8,6,5,7,6]
        [7,8,8,3,8,1,5,3,5,4]
    */

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // vector<int> nums2 = {1,2,3,4,2,3,1,4,2};
    // vector<int> nums3 = {7,9,3,8,0,2,4,8,3,9};
    // vector<int> nums4 = {2147483647,1,2,3,4,5,6,7,2147483647};
    // vector<int> nums5 = {9,7,0,3,9,8,6,5,7,6};
    vector<int> nums6 = {7,8,8,3,8,1,5,3,5,4};
    int         k = 3;

    Solution    sol;
    vector<double>  result = sol.medianSlidingWindow(nums6, 3);

    for (auto& r : result)
        cout << r << " ";
}