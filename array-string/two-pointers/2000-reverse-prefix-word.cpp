#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string reversePrefix(string word, char ch) {
            size_t index = word.find(ch);
    
            // base case if char doesn't exist
            if (index == string::npos)
                return word;
    
            int l = 0;
            int r = int(index);
    
            while (l < r) {
                swap(word, l, r);
                l++; r--;
            }
            return word;
        }
    
        void swap(string& word, int l, int r) {
            char temp = word[l];
            word[l] = word[r];
            word[r] = temp;
        }
    };