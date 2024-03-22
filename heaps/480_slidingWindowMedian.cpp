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
            lower.pop();
        }
        else if (higher.size() > lower.size() + 1) {
            lower.push(higher.top());
            higher.pop();
        }
    }

    void removeNum(int myNum) {
        int size = 0;
        int num;

        if (higher.empty() == false) {
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
            if (num == myNum) 
                return;
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
        }
    }

    void addNum(int num) {
        if (lower.size() == higher.size()) {
            if (higher.empty() == false && num > higher.top()) {
                higher.push(num);
            }
            else { // num < lower.top() || (higher.top() > num > lower.top())
                lower.push(num);
            }  
        }
        else if (lower.size() > higher.size()) {
            if (lower.top() < num) {
                higher.push(num);
            }
            else {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
        }
        else {  // lower.size() < higher.size()
            if (higher.top() > num) {
                lower.push(num);
            }
            else {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
        }
    }

private:
    priority_queue<int>                             lower;  // maxHeap - 0
    priority_queue<int, vector<int>, greater<int>>  higher; // minHeap - 1
};

int main(void) {
    // Recreate the example
    /*
        [1,3,-1,-3,5,3,6,7]
        [1,2,3,4,2,3,1,4,2]
        [7,9,3,8,0,2,4,8,3,9]
    */

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    // vector<int> nums2 = {1,2,3,4,5,6, 7, 8, 9};
    vector<int> nums3 = {7,9,3,8,0,2,4,8,3,9};
    int         k = 3;

    Solution    sol;
    vector<double>  result = sol.medianSlidingWindow(nums3, 1);

    for (auto& r : result)
        cout << r << " ";
}
