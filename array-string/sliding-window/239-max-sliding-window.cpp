#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans (nums.size() - k + 1); // to avoid resizing
            
            // Step 1: [Base step] prepare the first window
            priority_queue<int> window = get_window(nums, 0, k);
            ans[0] = window.top();
    
            // Step 2: [Inductive Step] move the window
            priority_queue<int> to_be_deleted;
        
            for (int i = k; i < nums.size(); ++i) {
                // update the window
                if (nums[i] != nums[i - k]) { // just to avoid repetition
                    window.push(nums[i]); // move r index
                    to_be_deleted.push(nums[i - k]); // move l index
                }
    
                // delete cashed values from to_be_deleted
                while (!window.empty() && !to_be_deleted.empty() && window.top() == to_be_deleted.top()) {
                    window.pop();
                    to_be_deleted.pop();
                }
    
                ans[i - k + 1] = window.top();
            }
            return ans;
        }
    
        priority_queue<int> get_window(vector<int>& nums, int l, int r) {
            priority_queue<int> window;
    
            for (int i = l; i < r; ++i) {
                window.push(nums[i]);
            }
            return window;
        }
    };