#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buy_price = INT_MAX;
            int ans = 0;
    
            for (int& sell_price : prices) {
                if (buy_price > sell_price)
                    buy_price = sell_price;
                else
                    ans = max(ans, sell_price - buy_price);
            }
            return ans;
        }
    };