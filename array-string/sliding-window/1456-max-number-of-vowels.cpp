#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxVowels(string s, int k) {
            int l = 0;
            int num_vowels = 0;
            int ans = 0; // maxum num of vowels in any substring (size == k)
    
            // sliding window (move r)
            for (int r = 0; r < s.size(); ++r) {
                if (vowels.contains(s[r]))
                    num_vowels++;
    
                // move l
                while (r - l + 1 == k) {
                    ans = max(ans, num_vowels);
                    if (vowels.contains(s[l++]))
                        num_vowels--;
                }
            }
            return ans;
        }
    
    private:
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
};
