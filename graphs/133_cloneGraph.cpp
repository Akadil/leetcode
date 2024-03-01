#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    /**
    *    Take one node, store all its neighbors, make copies, then repeat for each neighbors 
    */
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return (NULL);
        }

        Node*   copy = new Node(node->val);
        link[node] = copy;

        queue<Node*>    queue;
        queue.push(node);

        while (queue.empty() == false) {
            Node*   curr = queue.front();
            queue.pop();

            for (unsigned int i = 0; i < curr->neighbors.size(); ++i) {
                Node* neighbor = curr->neighbors[i];

                // If it wasn't occured before save it
                if (link.find(neighbor) == link.end()) {
                    queue.push(neighbor);
                    link[neighbor] = new Node(neighbor->val);
                }

                // Add it as a neighbors
                link[curr]->neighbors.push_back(link[neighbor]);
            }
        }
        return (copy);
    }

private:
    unordered_map<Node*, Node*> link;
};