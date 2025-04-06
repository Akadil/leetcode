/**
 * Problem: Minimum Depth of Binary Tree
 * 
 * Given the root of a binary tree, find its minimum depth. 
 * The minimum depth is the number of nodes along the shortest path 
 * from the root node down to the nearest leaf node.
 * A leaf node is a node with no children.
 * 
 * Example:
 * 
 * Input:
 *        3
 *       / \
 *      9  20
 *         /  \
 *        15   7
 * 
 * Output: 2
 * Explanation: The minimum depth is 2, which is the path 3 → 9.
 * 
 * Approach:
 * The solution uses Depth-First Search (DFS) to explore the binary tree.
 * - Traverse the tree and find the shortest path from the root to any leaf.
 * - For each node, calculate the minimum depth by comparing the left and right subtrees.
 * - Return the depth as the number of nodes in the path from the root to the nearest leaf.
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
         * Function to find the minimum depth of the binary tree.
         * This function starts the DFS traversal to calculate the minimum depth.
         * 
         * @param root The root of the binary tree.
         * @return The minimum depth of the binary tree.
         */
        int minDepth(TreeNode* root) {
            // Call the helper function to perform DFS traversal
            return dfs(root);
        }
        
        /**
         * Helper function to recursively calculate the minimum depth of the binary tree.
         * 
         * @param root The current node being processed.
         * @return The minimum depth of the tree rooted at the current node.
         */
        int dfs(TreeNode* root) {
            // Base case: If the current node is NULL, return 0 (no depth)
            if (!root)
                return 0;
            
            // If it's a leaf node (no left or right child), return depth as 1
            if (!root->left && !root->right)
                return 1;
        
            // Initialize left and right depths to maximum integer value
            int left = INT_MAX;
            int right = INT_MAX;
            
            // If left child exists, recursively find the minimum depth of the left subtree
            if (root->left)
                left = dfs(root->left);
            
            // If right child exists, recursively find the minimum depth of the right subtree
            if (root->right)    
                right = dfs(root->right);
            
            // Return the minimum of the left and right subtree depths, and add 1 for the current node
            return min(left, right) + 1;
        }
    };
    