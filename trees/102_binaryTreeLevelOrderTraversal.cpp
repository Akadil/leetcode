#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >    returner;
        queue<TreeNode*>        myQueue;

        // First level vector
        if (root) {
            myQueue.push(root);
        }

        // Traverse through each level. Each iteration is one level
        while (myQueue.empty() == false) {
            vector<int> levelVector;
            
            int size = myQueue.size();
            for (unsigned int i = 0; i < size; ++i) {

                TreeNode*   node = myQueue.front();
                myQueue.pop();
                levelVector.push_back(node->val);
                
                // Add the next level elements to the queue
                if (node->left)
                    myQueue.push(node->left);
                if (node->right)
                    myQueue.push(node->right);
            }

            // Add the current vector to the main vector
            returner.push_back(levelVector);
        }
        return (returner);
    }
};