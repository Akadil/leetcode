/**
 * Problem: 270. Closest Binary Search Tree Value
 *
 * Given a binary search tree and a target value, return the value in the BST that is closest to the target.
 *
 * Assumptions:
 * - There will only be one closest value.
 * - The BST is not necessarily balanced.
 *
 * Approach:
 * - Use a depth-first search (DFS) to traverse the tree.
 * - At each node, update the closest value if the current node's value is closer to the target.
 * - Only explore the left or right subtree based on how the current value compares to the target,
 *   which helps skip unnecessary branches thanks to BST properties.
 */

 #include <cmath>
 #include <climits>
 
 /**
  * Definition for a binary tree node.
  */
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
     /**
      * Finds the value in the BST closest to the given target.
      *
      * @param root - pointer to the root node of the BST
      * @param target - target value to compare against
      * @return int - the value in the BST closest to the target
      */
     int closestValue(TreeNode* root, double target) {
         dfs(root, target);
         return closest;
     }
 
 private:
     int closest = INT_MAX;
 
     /**
      * Performs a smart DFS traversal using BST properties.
      * - Moves left if target is smaller.
      * - Moves right if target is larger.
      * - Updates the closest value found so far.
      *
      * @param node - current node in traversal
      * @param target - the value we want to get close to
      */
     void dfs(TreeNode* node, double target) {
         if (!node) return;
 
         // Update closest value if current node is closer
         if (std::abs(node->val - target) < std::abs(closest - target))
             closest = node->val;
 
         // Traverse towards the potentially closer side
         if (target < node->val && node->left)
             dfs(node->left, target);
         else if (target > node->val && node->right)
             dfs(node->right, target);
     }
 };
 