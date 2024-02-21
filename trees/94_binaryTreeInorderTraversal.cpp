#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> container;

        if (root == nullptr)
            return (container);

        concatVectors(container, inorderTraversal(root->left));
        container.insert(container.end(), root->val);
        concatVectors(container, inorderTraversal(root->right));

        return (container);
    }

    void    concatVectors(vector<int>& left, const vector<int>& right) {
        if (right.empty())
            return;
 
        left.insert(left.end(), right.begin(), right.end());
    }
};