#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int     length = 0;

        for (int l = 0; l < s.size(); ++l) {
            char    myChar = s[l];
            int     counter = k;
            int     r = l;

            while (r < s.size() && (s[r] == myChar || counter != 0)) {
                if (s[r] != myChar)
                    counter--;
                r++;
            }
            int new_l = l;

            if (counter != 0) {
                while (new_l >= 0 && counter != 0) {
                    counter--;
                    new_l--;
                }
                new_l = max(0, new_l);
            }

            length = max(length, r - new_l);
        }
        return (length);
    }
};