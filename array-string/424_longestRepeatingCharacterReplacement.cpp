#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count (26, 0);
        int l = 0;
        int r = 0;
        int maxf = 0;

        for (r = 0; r < s.size(); ++r) {
            count[s[r] - 'A'] += 1;
            maxf = max(maxf, count[s[r] - 'A']);

            if (r - l + 1 - maxf > k) {
                count[s[l] - 'A'] -= 1;
                l += 1;
            }
        }
        return (r - l);
    }

    // int characterReplacement(string s, int k) {
    //     int     length = 0;

    //     for (int l = 0; l < s.size(); ++l) {
    //         char    myChar = s[l];
    //         int     counter = k;
    //         int     r = l;

    //         while (r < s.size() && (s[r] == myChar || counter != 0)) {
    //             if (s[r] != myChar)
    //                 counter--;
    //             r++;
    //         }
    //         int new_l = l;

    //         if (counter != 0) {
    //             while (new_l >= 0 && counter != 0) {
    //                 counter--;
    //                 new_l--;
    //             }
    //             new_l = max(0, new_l);
    //         }

    //         length = max(length, r - new_l);
    //     }
    //     return (length);
    // }
};