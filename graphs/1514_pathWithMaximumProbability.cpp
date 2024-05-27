#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // set up the proper format
        unordered_map<int, vector<pair<double, int>>> adj;

        // cout << "Initial pushed values: " << endl;
        for (unsigned int i = 0; i < edges.size(); ++i) {
            if (adj.count(edges[i][0]) == 0)
                adj[edges[i][0]] = vector<pair<double, int>>();
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            // cout << "s: " << edges[i][0] << ", d: " << edges[i][1] << ", w: " << succProb[i] << endl;
            
            if (adj.count(edges[i][1]) == 0)
                adj[edges[i][1]] = vector<pair<double, int>>();
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
            // cout << "s: " << edges[i][1] << ", d: " << edges[i][0] << ", w: " << succProb[i] << endl;
        }

        // Dijkstra's algo
        priority_queue<pair<double, int>>   maxHeap;
        unordered_set<int>                  visited;

        maxHeap.push({1, start_node});
        // cout << "Initial: " << start_node << endl;
        while (!maxHeap.empty()) {
            pair<double, int>   node = maxHeap.top();
            maxHeap.pop();

            // cout << "n: " << node.second << ", prob: " << node.first << endl;
            if (node.second == end_node) {
                return (node.first);
            }
            visited.insert(node.second);
            for (pair<double, int> edge : adj[node.second]) {
                // cout << "Pushed: n: " << edge.second << ", prob: " << edge.first * node.first << endl;
                if (visited.count(edge.second) == 0) {
                    maxHeap.push({edge.first * node.first, edge.second});
                }
            }
        }
        return (0);
    }
};