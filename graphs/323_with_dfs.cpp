/**
 * Problem: 323. Number of Connected Components in an Undirected Graph
 *
 * You are given an undirected graph with `n` nodes labeled from 0 to n - 1
 * and a list of undirected edges. Return the number of connected components.
 *
 * Approach:
 * - Build an adjacency list to represent the graph.
 * - Use DFS to explore all nodes in a connected component.
 * - Count how many times DFS is initiated from an unvisited node.
 */

 #include <vector>
 #include <unordered_map>
 
 using namespace std;
 
 class Solution {
 public:
     /**
      * Counts the number of connected components in an undirected graph.
      *
      * @param n - number of nodes (0 to n-1)
      * @param edges - list of undirected edges
      * @return number of connected components
      */
     int countComponents(int n, vector<vector<int>>& edges) {
         // Step 1: Build the adjacency list
         for (const auto& edge : edges) {
             graph[edge[0]].push_back(edge[1]);
             graph[edge[1]].push_back(edge[0]);
         }
 
         // Step 2: Initialize the "seen" tracker
         visited = vector<bool>(n, false);
 
         int count = 0;  // Connected component counter
 
         // Step 3: Explore each node using DFS if not yet visited
         for (int i = 0; i < n; ++i) {
             if (!visited[i]) {
                 dfs(i);
                 ++count;  // Every DFS call from unvisited node = new component
             }
         }
 
         return count;
     }
 
 private:
     unordered_map<int, vector<int>> graph;  // Adjacency list representation
     vector<bool> visited;                  // Tracks visited nodes
 
     /**
      * DFS helper function to mark all nodes in the same component.
      *
      * @param node - the current node being visited
      */
     void dfs(int node) {
         visited[node] = true;
         for (int neighbor : graph[node]) {
             if (!visited[neighbor])
                 dfs(neighbor);
         }
     }
 };
 