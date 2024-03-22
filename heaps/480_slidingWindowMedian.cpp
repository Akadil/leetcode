#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
            normalizeHeaps();
            addNum(nums[i + k - 1]);
            returner.push_back(findMedian());
        }

        return (returner);
    }

    double findMedian() {
        if (lower.size() > higher.size())
            return (lower.top());
        else if (lower.size() < higher.size())
            return (higher.top());
        else
            return ((double)higher.top() / 2 + (double)lower.top() / 2);
    }


    void    normalizeHeaps() {
        if (lower.size() > higher.size() + 1) {
            higher.push(lower.top());
            higher_contains[lower.top()] += 1;
            lower_contains[lower.top()] -= 1;
            lower.pop();
        }
        else if (higher.size() > lower.size() + 1) {
            lower.push(higher.top());
            lower_contains[higher.top()] += 1;
            higher_contains[higher.top()] -= 1;
            higher.pop();
        }
    }

    void removeNum(int myNum) {
        int size = 0;
        int num;

        if (higher.empty() == false && higher_contains[myNum] != 0) {
            num = higher.top();
            higher.pop();

            while (num != myNum) {
                lower.push(num);
                size++;

                if (higher.empty() == true)
                    break;
                num = higher.top();
                higher.pop();
            }
            while (size != 0) {
                higher.push(lower.top());
                lower.pop();
                size--;
            }
            if (num == myNum) {
                higher_contains[num] -= 1;
                return;
            }
        }
        if (lower.empty() == false) {
            num = lower.top();
            lower.pop();

            while (num != myNum) {
                higher.push(num);
                size++;

                num = lower.top();
                lower.pop();
            }
            while (size != 0) {
                lower.push(higher.top());
                higher.pop();
                size--;
            }
            lower_contains[num] -= 1;
        }
    }

    void addNum(int num) {
        if (lower.size() == higher.size()) {
            if (higher.empty() == false && num > higher.top()) {
                higher.push(num);
                higher_contains[num] += 1;
            }
            else { // num < lower.top() || (higher.top() > num > lower.top())
                lower.push(num);
                lower_contains[num] += 1;
            }  
        }
        else if (lower.size() > higher.size()) {
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
        }
    }

private:
    priority_queue<int>                             lower;  // maxHeap, 0
    priority_queue<int, vector<int>, greater<int>>  higher; // minHeap, 1
    unordered_map<int, int>                              lower_contains;
    unordered_map<int, int>                              higher_contains;
};

int main(void) {
    // Recreate the example
    /*
        [1,3,-1,-3,5,3,6,7]
        [1,2,3,4,2,3,1,4,2]
        [7,9,3,8,0,2,4,8,3,9]
        [2147483647,1,2,3,4,5,6,7,2147483647]
    */

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // vector<int> nums2 = {1,2,3,4,2,3,1,4,2};
    // vector<int> nums3 = {7,9,3,8,0,2,4,8,3,9};
    vector<int> nums4 = {2147483647,1,2,3,4,5,6,7,2147483647};
    int         k = 3;

    Solution    sol;
    vector<double>  result = sol.medianSlidingWindow(nums4, 2);

    for (auto& r : result)
        cout << r << " ";
}
