#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // unordered_set<char> window;
            vector<bool>    window (256, 0);
            int l = 0;
            int ans = 0;
    
            // sliding window
            for (int r = 0; r < s.size(); ++r) {
                // while the window is invalid, move the left index
                // while (window.find(s[r]) != window.end())
                //     window.erase(s[l++]);
    
                while (window[s[r]] == true)
                    window[s[l++]] = false;
    
                // window.insert(s[r]);
                window[s[r]] = true;
                ans = max(ans, r - l + 1);
            }
            return ans;
        }
    };