#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        // Set up the proper format
        for (int i = 1; i < n + 1; ++i) {
            adj[i] = vector<pair<int, int>>();
        }
        for (vector<int> edge : times) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back(make_pair(d, w));
        }

        // Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> shortest;
        int returner = -1;

        minHeap.push(make_pair(0, k));
        // std::cout << "Initial: " << k << std::endl; 
        while (!minHeap.empty()) {
            pair<int, int> node = minHeap.top();
            int n1 = node.second, w1 = node.first;

            minHeap.pop();
            if (shortest.count(n1) > 0)
                continue;
            shortest[n1] = w1;
            // std::cout << "n: " << n1 << ", w: " << w1 << std::endl;
            if (w1 > returner)
                returner = w1;
            for (pair<int, int> neighbour : adj[n1]) {
                int n2 = neighbour.first, w2 = neighbour.second;

                if (shortest.count(n2) == 0) {
                    minHeap.push(make_pair(w2 + w1, n2));
                    // std::cout << "Added: n: " << n2 << ", w: " << w2 + w1 << std::endl;
                }
            }
        }
        return shortest.size() == n ? returner : -1;
    }
};