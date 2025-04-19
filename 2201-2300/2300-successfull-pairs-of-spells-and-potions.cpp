#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * @brief Count the number of successful pairs of spells and potions
 * 
 * @details Given two integer arrays spells and potions, the ith spell and jth potion have a success pair if the product of the spell and potion is greater than or equal to success.
 * 
 * @param spells The array of spells
 * @param potions The array of potions
 * @param success The success threshold
 * @return A vector containing the number of successful pairs for each spell
 */
class Solution {
    public:
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            // Preprocess to use binary search
            sort(potions.begin(), potions.end());
    
            vector<int> ans (spells.size(), 0);
    
            for (int i = 0; i < spells.size(); ++i) {
                ans[i] = potions.size() - binary_search(potions, success / double(spells[i]));
            }
            return ans;
        }
    
        int    binary_search(vector<int>& potions, double target) {
            int l = 0; 
            int r = potions.size();
    
            while (l < r) {
                int mid = l + (r - l) / 2;
    
                if (target > potions[mid])
                    l = mid + 1;
                else // target <= potions[mid]
                    r = mid;
            }
            return l;
        }
    };

int main() {
    // Solution solution;
    // vector<int> spells = {1, 2, 3};
    // vector<int> potions = {4, 5, 6};
    // long long success = 10;

    // vector<int> result = solution.successfulPairs(spells, potions, success);
    
    // for (int i : result) {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}