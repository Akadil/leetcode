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
            addNum(nums, i);
        returner.push_back(findMedian(nums));

        // Inductive step, traverse through windows
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            removeNum(nums, i - 1);
            normalizeHeaps();
            addNum(nums, i + k - 1);
            returner.push_back(findMedian(nums));
        }

        return (returner);
    }

    double findMedian(vector<int>& nums) {
        if (lower.size() > higher.size())
            return (nums[lower.top()]);
        else if (lower.size() < higher.size())
            return (nums[higher.top()]);
        else
            return ((double)(nums[higher.top()] + nums[lower.top()]) / 2);
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

    void removeNum(vector<int>& nums, int index) {
        vector<int> container;  // vector of indexes
        int         num;

        if (map[index] == 1) {
            // Work with higher one
            num = higher.top();
            higher.pop();
            map.erase(num);

            while (num != index) {
                container.push_back(num);

                num = higher.top();
                higher.pop();
                map.erase(num);
            }
            while (container.empty() == false) {
                higher.push(container.back());
                container.pop_back();
            }
        } else {
            num = lower.top();
            lower.pop();
            map.erase(num);

            while (num != index) {
                container.push_back(num);

                num = lower.top();
                lower.pop();
                map.erase(num);
            }
            while (container.empty() == false) {
                lower.push(container.back());
                container.pop_back();
            }
        }
    }

    void addNum(vector<int>& nums, int index) {
        // lower.push(num);
        if (lower.size() == higher.size()) {
            if (higher.empty() == false && nums[index] > higher.top()) {
                higher.push(index);
                map[index] = 1;
            }
            else { // num < lower.top() || (higher.top() > num > lower.top())
                lower.push(index);
                map[index] = 0;
            }  
        }
        else if (lower.size() > higher.size()) {
            if (lower.top() < nums[index]) {
                higher.push(index);
                map[index] = 1;
            }
            else {
                map[lower.top()] = 0; 
                higher.push(lower.top());
                lower.pop();
                lower.push(index);
            }
        }
        else {  // lower.size() < higher.size()
            if (higher.top() > nums[index]) {
                lower.push(index);
                map[index] = 0;
            }
            else {
                map[higher.top()] = 1;
                lower.push(higher.top());
                higher.pop();
                higher.push(index);
            }
        }
    }

private:
    priority_queue<int>                             higher;  // maxHeap - 0
    priority_queue<int, vector<int>, greater<int>>  lower; // minHeap - 1
    unordered_map<int, bool>                        map;   // index to heap
};

int main(void) {
    // Recreate the example
    /*
        [1,3,-1,-3,5,3,6,7]
        [1,2,3,4,2,3,1,4,2]
    */

    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums2 = {1,2,3,4,2,3,1,4,2};
    int         k = 3;

    Solution    sol;
    vector<double>  result = sol.medianSlidingWindow(nums2, k);

    for (auto& r : result)
        cout << r << " ";
}
