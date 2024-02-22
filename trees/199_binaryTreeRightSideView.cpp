#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>  myQueue;
        vector<int> myVector;

        if (root) {
            myQueue.push(root);
        }

        while (myQueue.empty() == false) {
            int levelSize = myQueue.size();
            int lastValue;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode*   node = myQueue.front();
                
                myQueue.pop();
                lastValue = node->val;
                if (node->left)
                    myQueue.push(node->left);
                if (node->right)
                    myQueue.push(node->right);
            }
            myVector.push_back(lastValue);
        }
        return (myVector);
    }
};