/**
 * Problem: 1302. Deepest Leaves Sum
 * 
 * Description:
 * Given the root of a binary tree, return the sum of the values of its deepest leaves.
 * 
 * A leaf is a node with no children. The deepest leaves are those that are farthest from the root.
 * The task is to sum the values of all these deepest leaf nodes.
 *
 * Example:
 * Input: 
 *          1
 *         / \
 *        2   3
 *       / \   \
 *      4   5   6
 *     /         \
 *    7           8
 *
 * Output: 15
 * Explanation: The deepest leaves are 7 and 8, and their sum is 15.
 *
 * Approach:
 * - Use Level Order Traversal (Breadth-First Search) to traverse the tree level-by-level.
 * - For each level, compute the sum of its nodes.
 * - Once we reach the last level (deepest leaves), the last computed sum is the answer.
 */

 #include <queue>

 /**
  * Definition for a binary tree node.
  * Each node has a value and pointers to its left and right children.
  */
 struct TreeNode {
     int val;                // Value of the node
     TreeNode *left;         // Pointer to the left child
     TreeNode *right;        // Pointer to the right child
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 class Solution {
 public:
     /**
      * Function to compute the sum of the deepest leaves.
      *
      * @param root Pointer to the root of the binary tree
      * @return The sum of the deepest leaves
      */
     int deepestLeavesSum(TreeNode* root) {        
         std::queue<TreeNode*> my_queue;   // Queue for BFS traversal
         my_queue.push(root);
         int ans = 0;                      // Will store the final sum
         
         // Perform level order traversal
         while (!my_queue.empty()) {
             int row_length = my_queue.size(); // Number of nodes at current level
             int sum = 0;                      // Sum of values at current level
             
             // Traverse all nodes at this level
             for (int i = 0; i < row_length; ++i) {
                 TreeNode* node = my_queue.front();
                 my_queue.pop();
                 
                 sum += node->val;            // Add current node's value
                 
                 // Add children to queue for next level
                 if (node->left)
                     my_queue.push(node->left);
                 if (node->right)
                     my_queue.push(node->right);
             }
 
             // After traversing the level, store the sum
             // This will eventually be the sum of the deepest level
             ans = sum;
         }
 
         return ans;
     }
 };
 