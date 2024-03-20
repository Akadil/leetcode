#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;

        // Create a new vector adding its length
        for (unsigned int i = 0; i < points.size(); ++i) {
            triples.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], points[i][0], points[i][1]});
        }

        // Create a min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> p_queue(triples.begin(), triples.end());

        vector<vector<int>> result;

        while (k > 0) {
            vector<int> elem = p_queue.top();

            p_queue.pop();
            result.push_back({elem[1], elem[2]});
            --k;
        }
        return (result);
    }
};