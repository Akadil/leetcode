#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            // Preprocess: Store the number of occurences of each number
            unordered_map<int, int> count;
            for (int num : answers) {
                count[num + 1]++;
            }
    
            // Step 1: iterate through the values. If the count is more than the number
            //          it means it's the next color
            int ans = 0;
            
            for (auto it = count.begin(); it != count.end(); it++) { // MAYBE change to ++it
                int key = it->first, value = it->second;
                
                ans += key * ((value - 1) / key + 1);
            }
            return ans;
        }
    };