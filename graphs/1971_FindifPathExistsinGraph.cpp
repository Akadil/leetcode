/**
 * Problem: 1971. Find if Path Exists in Graph
 *
 * You are given an undirected graph with `n` nodes, labeled from 0 to n - 1,
 * and a list of edges where each edge connects two nodes.
 * You are also given two nodes `source` and `destination`.
 * Return true if there is a valid path from `source` to `destination`.
 *
 * Approach:
 * - Build an adjacency list to represent the graph.
 * - Use Depth-First Search (DFS) starting from the source node.
 * - Track visited nodes with a set to avoid infinite recursion or revisits.
 */

 #include <vector>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 class Solution {
 public:
     /**
      * Determines if a valid path exists between source and destination nodes.
      *
      * @param n - number of nodes in the graph
      * @param edges - list of edges, where each edge connects two nodes
      * @param source - starting node
      * @param destination - target node
      * @return true if path exists, false otherwise
      */
     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         // Edge case: source and destination are the same node
         if (source == destination)
             return true;
 
         // Step 1: Build the adjacency list (undirected graph)
         for (const auto& edge : edges) {
             graph[edge[0]].push_back(edge[1]);
             graph[edge[1]].push_back(edge[0]);
         }
 
         // Step 2: Start DFS from the source node
         visited.insert(source);
         return dfs(source, destination);
     }
 
 private:
     unordered_map<int, vector<int>> graph;   // Adjacency list
     unordered_set<int> visited;              // Set to track visited nodes
 
     /**
      * DFS helper to traverse graph and look for destination node.
      *
      * @param current - current node during traversal
      * @param destination - target node to reach
      * @return true if a path to destination is found, false otherwise
      */
     bool dfs(int current, int destination) {
         for (int neighbor : graph[current]) {
             if (neighbor == destination)
                 return true;
 
             if (visited.find(neighbor) == visited.end()) {
                 visited.insert(neighbor);
                 if (dfs(neighbor, destination))
                     return true;
             }
         }
         return false;
     }
 };
 