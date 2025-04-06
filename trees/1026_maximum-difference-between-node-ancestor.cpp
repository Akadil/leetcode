/**
 * Problem: Maximum Difference Between Node and Ancestor
 * 
 * Given the root of a binary tree, find the maximum value V for which 
 * there exists different nodes A and B where B is a descendant of A, and 
 * V = |A.val - B.val| (the absolute difference of their values).
 * 
 * A node is a descendant of another node if it is reachable by repeatedly 
 * following the left or right child pointers from the other node.
 * 
 * Example:
 * 
 * Input:
 *        8
 *       / \
 *      3   10
 *     / \    \
 *    1   6    14
 *        / \   / 
 *       4   7 13
 * 
 * Output: 13
 * Explanation: The maximum difference is between node 1 and node 14.
 * 
 * Approach:
 * The problem is solved using a Depth-First Search (DFS) approach:
 * 1. Traverse the tree starting from the root.
 * 2. Maintain the minimum and maximum values encountered along the path from the root to the current node.
 * 3. For each node, calculate the maximum difference between the node's value and the minimum or maximum value encountered so far.
 * 4. Recursively calculate the maximum difference for both the left and right subtrees.
 * 5. Return the largest difference encountered during the traversal.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;        // Value of the node
 *     TreeNode *left; // Pointer to the left child
 *     TreeNode *right;// Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}  // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  // Constructor with value and children
 * };
 */

 class Solution {
    public:
        /**
         * Function to find the maximum difference between a node and its ancestor.
         * This function starts the DFS traversal to calculate the maximum difference.
         * 
         * @param root The root of the binary tree.
         * @return The maximum difference between a node and its ancestor.
         */
        int maxAncestorDiff(TreeNode* root) {
            // Call the helper function to perform DFS traversal with initial min and max values
            return dfs(root, INT_MAX, INT_MIN);
        }
        
        /**
         * Helper function to recursively calculate the maximum difference between node and ancestor.
         * 
         * @param root The current node being processed.
         * @param min_val The minimum value encountered along the path from root to this node.
         * @param max_val The maximum value encountered along the path from root to this node.
         * @return The maximum difference between the current node and its ancestor in the subtree.
         */
        int dfs(TreeNode* root, int min_val, int max_val) {
            // Base case: if the current node is NULL, return 0 as no difference can be calculated
            if (!root)
                return 0;
            
            // Update the minimum and maximum values encountered along the path
            min_val = min(min_val, root->val);
            max_val = max(max_val, root->val);
            
            // Calculate the current difference as the maximum of the absolute differences
            // between the node's value and the min/max values encountered so far
            int curr = max(abs(min_val - root->val), abs(max_val - root->val));
            
            // Recursively calculate the maximum difference for the left and right subtrees
            int left = dfs(root->left, min_val, max_val);
            int right = dfs(root->right, min_val, max_val);
            
            // Return the maximum of the current difference, left subtree, and right subtree
            return max(max(curr, left), right);
        }
    };
    