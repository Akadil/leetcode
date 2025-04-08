/**
 * Problem: Given an undirected graph with `n` nodes and a list of restricted nodes,
 * return the number of nodes reachable from node 0, **excluding** restricted ones.
 *
 * Approach:
 * - Use DFS starting from node 0.
 * - Track visited nodes to avoid cycles.
 * - Skip nodes marked as restricted.
 */

 #include <vector>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 class Solution {
 public:
     int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
         // Build adjacency list for the graph
         for (const auto& edge : edges) {
             graph[edge[0]].push_back(edge[1]);
             graph[edge[1]].push_back(edge[0]);
         }
 
         // Mark restricted nodes
         vector<bool> is_restricted(n, false);
         for (int node : restricted) {
             is_restricted[node] = true;
         }
 
         // Track visited nodes
         visited = vector<bool>(n, false);
 
         // DFS traversal from node 0
         return dfs(0, is_restricted);
     }
 
 private:
     unordered_map<int, vector<int>> graph;
     vector<bool> visited;
 
     /**
      * DFS traversal to count reachable nodes.
      * Skips restricted and already visited nodes.
      */
     int dfs(int node, const vector<bool>& is_restricted) {
         if (visited[node] || is_restricted[node])
             return 0;
 
         visited[node] = true;
         int count = 1; // Count the current node
 
         for (int neighbor : graph[node]) {
             count += dfs(neighbor, is_restricted);
         }
 
         return count;
     }
 };
 