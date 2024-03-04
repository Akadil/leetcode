#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1, 0);

        for (unsigned int i = 1; i < n + 1; ++i) {
            answer[i] = answer[i / 2] + i % 2;
        }
        return (answer);
    }
};