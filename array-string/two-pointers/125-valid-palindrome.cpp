#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int l = 0, r = s.size() - 1;
    
            while (l < r) {
                while (l < s.size() - 1 && isalnum(s[l]) == false)
                    l++;
                while (r > 0 && isalnum(s[r]) == false)
                    r--;
    
                if (l < r && tolower(s[l]) != tolower(s[r])) {
                    // cout << "l: " << l << s[l] << ", r: " << r << s[r] << endl;
                    return false;
                }
                l++; r--;
            }
            return true;
        }
    };