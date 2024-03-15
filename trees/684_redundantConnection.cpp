#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Initialize them by parent pointing to itself
        for (unsigned int i = 0; i < edges.size() + 1; ++i) {
            _parent.push_back(i);
            _rank.push_back(0);
        }

        // Add edges
        for (unsigned int i = 0; i < edges.size(); ++i) {
            int parent_0 = find(edges[i][0]);
            int parent_1 = find(edges[i][1]);
            
            // cout << "Debugger: [" <<  edges[i][0] << ", " << edges[i][1];
            // cout << "] -> [" << parent_0 << ", " << parent_1 << "]" << endl;

            if (parent_0 == parent_1)
                return {edges[i][0], edges[i][1]};
            else
                myUnion(parent_0, parent_1);
        }
        return {-1, -1};
    }

private:
    vector<int> _parent;
    vector<int> _rank;

    int find(int i_node) {
        while (i_node != _parent[i_node]) {
            i_node = _parent[i_node];
        }
        return (i_node);
    }

    void    myUnion(int node_0, int node_1) {
        if (_rank[node_0] > _rank[node_1]) {    // if the rank of node_0 is more
            _parent[node_1] = node_0;
            _rank[node_0] += _rank[node_1];
        } 
        else if (_rank[node_1] > _rank[node_0]) {   // if the rank of node_1 is more
            _parent[node_0] = node_1;
            _rank[node_1] += _rank[node_0];
        } 
        else {
            _rank[node_1] += _rank[node_0];
            _parent[node_1] = node_0;
        }
    }
};