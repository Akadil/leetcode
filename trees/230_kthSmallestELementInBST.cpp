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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void    inOrder(TreeNode* root, int& k, int& result) {
        if (k == 0 || root == nullptr)
            return ;
        
        inOrder(root->left, k, result);
        if (k == 1)
            result = root->val;
        k--;
        inOrder(root->right, k, result);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        // 1. Just traverse with inOrder algorithm
        // 2. Maybe I can modify the structure by adding a parent node? 
        //      and then just traverse faster?  But no, I think it is the same
        //      as previous method
        
        int result = -1;

        inOrder(root, k, result);
        return (result);
    }
};