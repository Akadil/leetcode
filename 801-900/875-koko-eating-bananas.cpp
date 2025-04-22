#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /**
    *   @brief  Find the highest number of bananas (n), and run binary search on 
                the values "< n" 
    */
    int minEatingSpeed(vector<int>& piles, int h) {

        // Idenitfy the highest number
        int max_bananas = 0;

        for (int i = 0; i < piles.size(); ++i) {
            if (piles[i] > max_bananas)
                max_bananas = piles[i];
        }

        int l_rate = 1;
        int r_rate = max_bananas;

        while (l_rate < r_rate) {
            // cout << l_rate << " " << r_rate << endl;
            int m_rate = l_rate + (r_rate - l_rate) / 2;

            if (canEat(piles, h, m_rate)) {
                r_rate = m_rate;
            } 
            else {
                l_rate = m_rate + 1;
            }
        }
        return (l_rate);
    }

    bool    canEat(vector<int>& piles, int h, int rate) {
        long    hoursSpend = 0;

        for (int i = 0; i < piles.size(); i++) {
            hoursSpend += (piles[i] + rate - 1) / rate;
            if (hoursSpend > h)
                return (false);
        }
        return (true);
    }
};