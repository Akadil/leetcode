#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        /**
         * @brief Reverse the words in a string
         * 
         * @details Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
         */
        string reverseWords(string s) {
            int l_index = 0;
    
            for (int r_index = 0; r_index < s.size(); ++r_index) {
                if (r_index + 1 == s.size() || s[r_index + 1] == ' ') { // the end or space
                    reverse(s, l_index, r_index);
                    l_index = r_index + 2; // each word separated by 1 space
                }
            }
            return s;
        }
    
        void    reverse(string& s, int l, int r) {
            while (l < r) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
    
                l++; r--;
            }
        }
};
