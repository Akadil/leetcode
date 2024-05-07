## Graphs 

### Topics to cover:
- Introduction to graphs
- DFS algorithm
- BFS algorithm
- Adjacency list
- [Advanced topic] Dijkstra's algorithm
- [Advanced topic] Prim's algorithm
- [Advanced topic] Kruskal's algorithm
- [Advanced topic] Topological sort

<br>

| # | Title | Solution | Problem level | Time | Space |
|---| ----- | -------- | ------------- | ---- | ----- |
|  |  |  |  |  |  |
| 6 | [207 - Course Schedule](https://leetcode.com/problems/course-schedule/description/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/207_courseSchedule.cpp) | Medium | 39% | 25% |
| 5 | [133 - Clone Graph](https://leetcode.com/problems/clone-graph/description/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/133_cloneGraph.cpp) | Medium | 100% | 53% |
| 4 | [994 - Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/994_rottingOranges.cpp) | Medium - BFS | 60% | 43% |
| 3 | [1091 - Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/1091_shortestPathInMatrix.cpp) | Medium - BFS | 79% | 55% |
| 2 | [695 - Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/695_maxAreaOfIsland.cpp) | Medium - DFS | 87% | 65% |
| 1 | [200 - Number of Islands](https://leetcode.com/problems/number-of-islands/description/) | [C++](https://github.com/Akadil/leetcode/blob/main/graphs/200_numberOfIslands.cpp) | Medium - DFS | 76% | 75% |

<!-------------- Introduction to Graphs ------------->
<details>
<summary>Introduction to Graphs</summary>
<br>
It seems like the graphs should be represented as tree nodes, but in the problems, it is represented as an integer to represent several nodes and a matrix to represent edges. 

</details>
<br>

<!-------------- DFS algorithm ---------------------->
<details>
<summary>DFS algorithm</summary>
<br>

The main idea is to make a recursion. I use it when I need to check every solution. Recursion, where each function runs the recursion for each possible way

</details>
<br>

<!-------------- BFS algorithm ---------------------->
<details>
<summary>BFS algorithm</summary>
<br>

Mainly used for shortest path. The idea is that we make one step, and then store all the next steps inside of something (usually a deque). Then we take a step from a deque
and repeat

```c++
    int bfs(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> visit(4, vector<int>(4));
        queue<pair<int, int>> queue;
        queue.push(pair<int, int>(0, 0));
        visit[0][0] = 1;

        int length = 0;
        while (queue.size()) {
            int queueLength = queue.size();
            for (int i = 0; i < queueLength; i++) {
                pair<int, int> curPair = queue.front();
                queue.pop();
                int r = curPair.first, c = curPair.second;
                if (r == ROWS - 1 && c == COLS - 1) {
                    return length;
                }

                // We can directly build the four neighbors
                int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
                for (int j = 0; j < 4; j++) {
                    int newR = neighbors[j][0], newC = neighbors[j][1];
                    if (min(newR, newC) < 0 || newR == ROWS || newC == COLS
                        || visit[newR][newC] || grid[newR][newC]) {
                        continue;
                    }
                    queue.push(pair<int, int>(newR, newC));
                    visit[newR][newC] = 1;
                }
            }
            length++;
        }
    }
```

</details>
