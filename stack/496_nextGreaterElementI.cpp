#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
    public:
        /*
            @brute_force: 
            The naive solution is to iterate through each element in nums1, and for each one, 
            scan nums2 to find its next greater element. 
            This results in O(n * m) time complexity, where n = nums1.size() and m = nums2.size().
    
            @optimized_approach:
            Instead, we use a **monotonic stack** to preprocess nums2 and find the next greater element 
            for each number. Then, we map results for nums1 using a hash map in O(1) time for each query.
    
            Time Complexity: O(n + m), where 
              - m = nums2.size() (for stack-based preprocessing)
              - n = nums1.size() (for mapping result)
            
            Space Complexity: O(m), for the hash map and stack.
        */
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            // Step 1: Preprocess nums2 to build a map of next greater elements
            unordered_map<int, int> next_greater_element; // maps each element in nums2 to its next greater element
            stack<int> descending_stack; // stores indices of nums2 in a decreasing order
    
            for (int i = 0; i < nums2.size(); ++i) {
                // While the current number is greater than the number corresponding to the top index in stack,
                // it means we've found the next greater element for that number.
                while (!descending_stack.empty() && nums2[descending_stack.top()] < nums2[i]) {
                    next_greater_element[nums2[descending_stack.top()]] = nums2[i];
                    descending_stack.pop();   
                }
                descending_stack.push(i);
            }
    
            // Step 2: Build the answer for nums1 using the preprocessed map
            vector<int> ans(nums1.size(), -1); // initialize all values to -1 (default if no greater element exists)
            for (int i = 0; i < nums1.size(); ++i) {
                if (next_greater_element.find(nums1[i]) != next_greater_element.end()) {
                    ans[i] = next_greater_element[nums1[i]];
                }
            }
    
            return ans;
        }
    };
    