/**
 * Problem: 103. Binary Tree Zigzag Level Order Traversal
 * 
 * Description:
 * Given the root of a binary tree, return its zigzag level order traversal.
 * 
 * Zigzag traversal means level order traversal where the nodes at each level
 * alternate between left-to-right and right-to-left ordering.
 * 
 * Example:
 * Input:
 *     1
 *    / \
 *   2   3
 *  / \   \
 * 4   5   6
 * 
 * Output:
 * [
 *   [1],
 *   [3, 2],
 *   [4, 5, 6]
 * ]
 * 
 * Approach:
 * - Use a deque to process nodes in both left-to-right and right-to-left directions.
 * - Use a boolean flag `left_to_right` to track current direction.
 * - Traverse each level accordingly and build the result.
 */

 #include <vector>
 #include <deque>
 using namespace std;
 
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
      * Returns zigzag level order traversal of the binary tree.
      * @param root - pointer to the root of the tree
      * @return vector of vectors representing zigzag level order
      */
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if (!root) return {};
 
         vector<vector<int>> result;
         deque<TreeNode*> dq;            // Double-ended queue for flexible traversal
         dq.push_back(root);
 
         bool left_to_right = true;      // Direction toggle flag
 
         while (!dq.empty()) {
             int level_size = dq.size();
             vector<int> level_nodes;
 
             for (int i = 0; i < level_size; ++i) {
                 if (left_to_right) {
                     // Pop from front and add children left-to-right
                     TreeNode* node = dq.front(); dq.pop_front();
                     level_nodes.push_back(node->val);
                     if (node->left)  dq.push_back(node->left);
                     if (node->right) dq.push_back(node->right);
                 } else {
                     // Pop from back and add children right-to-left
                     TreeNode* node = dq.back(); dq.pop_back();
                     level_nodes.push_back(node->val);
                     if (node->right) dq.push_front(node->right);
                     if (node->left)  dq.push_front(node->left);
                 }
             }
 
             result.push_back(level_nodes);
             left_to_right = !left_to_right;  // Flip direction for next level
         }
 
         return result;
     }
 };
 