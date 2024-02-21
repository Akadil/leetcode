#include <iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return (build(preorder, inorder, inorder.begin(), inorder.end(), 
                    preorder.begin(), preorder.end()));
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
            vector<int>::iterator in_beg, vector<int>::iterator in_end, 
            vector<int>::iterator pre_beg, vector<int>::iterator pre_end) 
    {
        /*
            Some stopping condition
        */
        if (pre_beg == pre_end)
            return (nullptr);
        else if (pre_beg + 1 == pre_end)
            return (new TreeNode(*pre_beg));

        int root_value = *pre_beg;

        /*  Update the pointers */
        vector<int>::iterator   in_middle = in_beg;
        vector<int>::iterator   pre_middle = pre_beg + 1;

        // Traverse till the inorder iterator not equal to root value
        while (*in_middle != root_value)
            in_middle++;

        // Given the size of left child elements, identify the middle iterator of pre
        pre_middle = pre_middle + (in_middle - in_beg);
 
        // Create the Tree
        TreeNode*   node = new TreeNode(root_value);

        node->left = build(preorder, inorder, in_beg, in_middle, pre_beg + 1, pre_middle);
        node->right = build(preorder, inorder, in_middle + 1, in_end, pre_middle, pre_end);

        return (node);
    }
};