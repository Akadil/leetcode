#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost) {
            int l = 0;
            int cost = 0;
            int ans = 0;
    
            // sliding window
            for (int r = 0; r < s.size(); ++r) {
                cost += abs(s[r] - t[r]);
    
                while (l <= r && cost > maxCost) {
                    cost -= abs(s[l] - t[l]);
                    l++;
                }
    
                if (cost <= maxCost)
                    ans = max(ans, r - l + 1);
            }
            return ans;
        }
};