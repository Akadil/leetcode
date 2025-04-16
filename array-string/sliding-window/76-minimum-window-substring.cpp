#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            // Step 1: Preprocess: transform the target into a hashmap
            unordered_map<char, int>    target;
            for (char c : t)
                target[c]++;
            
            // Step 2: sliding window technique
            unordered_map<char, int>    window;
            // string  ans = "";
            int ans_l = 0, ans_r = 0; // string represented as 2 boundry indices
            int l = 0;
    
            // keep incrementing the r index
            for (int r = 0; r < s.size(); ++r) {
                window[s[r]]++;
    
                // if the window is valid, perform operation
                while (is_valid(target, window)) {
                    // if (ans == "" || r - l + 1 < ans.size()) {
                    if (ans_r == ans_l || r - l + 1 < ans_r - ans_l) {
                        // cout << "Window: " << s.substr(l, r - l + 1) << endl;
                        // ans = s.substr(l, r - l + 1); 
                        ans_l = l; ans_r = r + 1;
                    }
                    window[s[l++]]--; // move left index
                }
            }
    
            return (ans_r == ans_l) ? "" : s.substr(ans_l, ans_r - ans_l);
        }
    
        // check if the current window is valid
        bool    is_valid(unordered_map<char, int> &target, unordered_map<char, int> &window) {
            for (const auto& pair : target) {
                if (window[pair.first] < pair.second)
                    return false;
            }
            return true;
        }
    };
    