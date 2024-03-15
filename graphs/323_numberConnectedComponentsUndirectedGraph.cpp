#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int result = n;

        init_unionFind(n);


        for (unsigned int i = 0; i < edges.size(); ++i) {
            result -= myUnion(edges[i][0], edges[i][1]);
        }
        return (result);
    }

private:
    vector<int> _parent;
    vector<int> _rank;

    void    init_unionFind(int n) {
        for (int i = 0; i < n; ++i) {
            _parent.push_back(i);
            _rank.push_back(0);
        }
    }

    int find(int index) {
        while (index != _parent[index]) {
            _parent[index] = _parent[_parent[index]];
            index = _parent[index];
        }
        return (index);
    }

    int    myUnion(int node0, int node1) {
        int parent0 = find(node0);
        int parent1 = find(node1);

        if (parent0 == parent1)
            return 0;

        if (_rank[parent0] > _rank[parent1]) {
            _rank[parent0] += _rank[parent1];
            _parent[parent1] = parent0;
        } 
        else {
            _rank[parent1] += _rank[parent0];
            _parent[parent0] = parent1;
        }
        return 1;
    }
};
