#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string reverseOnlyLetters(string s) {
            int l = 0, r = s.size() - 1;
    
            while (l < r) {
                while (l < s.size() && is_ascii(s[l]) == false) // skip until ascii found
                    l++;
                while (r > -1 && is_ascii(s[r]) == false) // skip 
                    r--;
    
                if (l < r)
                    swap(s, l, r);
                l++; r--;
            }
            return s;
        }
    
        bool    is_ascii(char c) {
            if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
                return true;
            return false;
        }
    
        void    swap(string&s, int l, int r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
        }
    };