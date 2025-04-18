#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        /*
        *   Sliding window technique
        */
        bool checkInclusion(string s1, string s2) {
            // Step 1: Prepare a window
            vector<int> window(26, 0);
            for (char c : s1) {
                window[c - 97]++;
            }
    
            // Step 2: generate the first window
            for (int i = 0; i < s1.size() && i < s2.size(); ++i) {
                window[s2[i] - 97]--;
            }
            if (is_valid(window))
                return true;
    
            // Step 3: sliding window
            for (int r = s1.size(); r < s2.size(); ++r) {
                window[s2[r] - 97]--; window[s2[r - s1.size()] - 97]++; 
                if (is_valid(window))
                    return true;
            }
            return false;
        }
    
        bool    is_valid(vector<int>& window) {
            for (int &num : window)
                if (num != 0)
                    return false;
            return true;
        }
    };