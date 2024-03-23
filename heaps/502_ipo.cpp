#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Compare based on the first element of the pair
        return a.first > b.first;
    }
}; 

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Initiate the minHeap 
        for (unsigned int i = 0; i < capital.size(); ++i) {
            if (capital[i] > w)
                minCapital.push({capital[i], i});
            else
                maxProfit.push({profits[i], i});
        }

        int returner = w;

        // Formulate k profits
        for (int i = 0; i < k; ++i) {
            
            // Add projects whose capital is lower than our budget
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push({profits[minCapital.top().second], minCapital.top().second});
                minCapital.pop();
            }

            if (maxProfit.empty()) // shouldn't happen though
                return (returner);

            // Invest in the highest profit project
            returner += profits[maxProfit.top().second];
            // w = w - capital[maxProfit.top().second] + profits[maxProfit.top().second];
            w = w + profits[maxProfit.top().second];
            maxProfit.pop();

            // Add the investments back to 
            while (!maxProfit.empty() && capital[maxProfit.top().second] > w) {
                minCapital.push({capital[maxProfit.top().second], maxProfit.top().second});
                maxProfit.pop();
            }
        }
        return (returner);
    }

private:
    typedef pair<int, int>  myPair;

    std::priority_queue<myPair>                                 maxProfit; // MaxHeap    
    std::priority_queue<myPair, vector<myPair>, ComparePairs>   minCapital; // minHeap
};

int main(void) {
    Solution s;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {1, 1, 2};
    int k = 1;
    int w = 2;
    cout << "The result is: " << s.findMaximizedCapital(k, w, profits, capital) << endl;
    return (0);
}