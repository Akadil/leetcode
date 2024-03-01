#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    /*
        1. I should know the starting point
        2. I can create the directed graph out of that
        3. Why do i need dfs and bfs? How do I have to traverse through my graph

        Possible solutions:
            1. Create a full graph with full edges, then depending on prerequisites,
                remove the edges that can't be traversed. In this graph the directed
                edge will be "you can take course after course". and then take each
                course and try to run the bfs algorithm to see if there exists the 
                path 
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;

        // Create an adjacency list
        for (unsigned int i = 0; i < prerequisites.size(); ++i) {
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]); 
        }

        unordered_set<int>  visited;    // detect the infinite loops

        // Check if each of courses has a way to be taken
        for (unsigned int i = 0; i < numCourses; ++i) {
            if (canBeTaking(i, prereq, visited) == false)
                return (false);
        }
        return (true);
    }

    bool    canBeTaking(int course, unordered_map<int, vector<int>>& prereq, unordered_set<int>& visited) {
        if (visited.find(course) != visited.end()) {  // if visited, means loop
            return (false);
        }

        if (prereq[course].empty() == true) {
            return (true);
        }

        visited.insert(course);
        for (unsigned int j = 0; j < prereq[course].size(); ++j) {
            int nextCourse = prereq[course][j];

            if (canBeTaking(nextCourse, prereq, visited) == false)
                return (false);
        }
        prereq[course].clear();
        visited.erase(course);
        return (true);
    }
};