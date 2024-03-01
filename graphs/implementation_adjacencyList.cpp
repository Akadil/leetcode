#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
    Graph() {}

    void addEdge(int src, int dst) {
        adjList[src].push_back(dst);
    }

    bool removeEdge(int src, int dst) {
        if (adjList.find(src) == adjList.end()) {
            return false;
        }
        for (int i = 0; i < adjList[src].size(); i++) {
            if (adjList[src][i] == dst) {
                adjList[src].erase(adjList[src].begin() + i);
                return true;
            }
        }
        return false;
    }

    bool hasPath(int src, int dst) {
        unordered_set<int> visited;
        return hasPathDFS(src, dst, visited);
    }

private:
    unordered_map<int, vector<int>> adjList;

    bool hasPathDFS(int src, int dst, unordered_set<int> &visited) {
        if (src == dst) {
            return true;
        }
        if (visited.find(src) != visited.end()) {
            return false;
        }
        visited.insert(src);
        for (const int &neighbor : adjList[src]) {
            if (hasPathDFS(neighbor, dst, visited)) {
                return true;
            }
        }
        return false;
    }

};
