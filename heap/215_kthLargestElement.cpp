#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p_queue(nums.begin(), nums.end());

        while (k > 1) {
            p_queue.pop();
            k--;
        }
        return (p_queue.top());
    }
};