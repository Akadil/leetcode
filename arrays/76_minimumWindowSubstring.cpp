#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int>    contains;

        for (unsigned int i = 0; i < t.size(); ++i) {
            contains[t[i]]++;
        }

        int counter = t.size();
        int minLength = 2147483647;
        int minStart = 0;
        int i = 0;
        int j = 0;

        while (j < s.size()) {
            if (contains[s[j]] > 0)
                counter--;
            
            contains[s[j]]--;

            while (counter == 0) {
                if (j + 1 - i < minLength) {
                    minLength = j + 1 - i;
                    minStart = i;
                }

                contains[s[i]]++;

                if (contains[s[i]] > 0) 
                    counter++;
                i++;
            }
            j++;
        }
        // cout << minStart << " " << minLength << endl;
        if (minLength != 2147483647)
            return (s.substr(minStart, minLength));
        return "";
    }
};