#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_set<char>     memory2;      // char to its position  
        vector<bool>            memory (256, 0);
        int                     length = 0;  // returner
        int                     l = 0;

        for (int r = 0; r < s.size(); ++r) {
            // if (memory.find(s[r]) != memory.end()) {
            if (memory[s[r]] == true) {
                while (s[l] != s[r]) {
                    // memory.erase(s[l]);
                    memory[s[l]] = false;
                    l++;
                }
                memory[s[l++]] = false;
                // memory.erase(s[l++]);
            }
            memory[s[r]] = true;
            // memory.insert(s[r]);
            length = max(length, r - l + 1);
        }
        return (length);
    }
    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char, int>    memory;      // char to its position  
    //     int                         length = 0;  // returner
    //     int                         l = 0;

    //     for (int r = 0; r < s.size(); ++r) {
    //         if (memory.find(s[r]) != memory.end()) {
    //             int new_l = memory[s[r]] + 1;
                
    //             // I have to clear all the prevvious ones
    //             while (l != new_l) {
    //                 memory.erase(s[l]);
    //                 l++;
    //             }
    //         }
    //         memory[s[r]] = r;
    //         length = max(length, r - l + 1);
                // cout << "Data: s[i] " << s[r] << " | l: " << l << " | r: " << r << endl;
    //     }
    //     return (length);
    // }
};