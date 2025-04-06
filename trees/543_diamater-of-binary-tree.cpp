/**
 * Problem: 543. Diameter of Binary Tree
 *
 * Description:
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
 * This path may or may not pass through the root.
 * 
 * The length of a path between two nodes is represented by the number of edges between them.
 *
 * Example:
 * Input: [1,2,3,4,5]
 *        1
 *       / \
 *      2   3
 *     / \     
 *    4   5    
 * 
 * Output: 3
 * Explanation: The longest path is [4,2,1,3] or [5,2,1,3], and its length is 3.
 *
 * Approach:
 * - Use a post-order traversal (DFS) to compute the depth of left and right subtrees for every node.
 * - At each node, the sum of left and right subtree depths is a candidate for the longest path (diameter).
 * - Keep track of the maximum such value seen during the traversal.
 * - Return the global maximum as the answer.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;            // Value of the current node
 *     TreeNode *left;     // Pointer to the left child
 *     TreeNode *right;    // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 class Solution {
    public:
        /**
         * Public function to initiate the diameter calculation.
         *
         * @param root Pointer to the root of the binary tree
         * @return The diameter (maximum number of edges between any two nodes)
         */
        int diameterOfBinaryTree(TreeNode* root) {
            max_depth(root);  // Start DFS traversal from the root
            return this->ans; // Return the maximum diameter found
        }
        
    private:
        int ans = 0;  // Stores the maximum diameter found so far
    
        /**
         * Helper function to compute the depth of a subtree rooted at 'root'.
         * While computing depth, it updates the global diameter.
         *
         * @param root The current node being visited
         * @return The maximum depth from the current node to a leaf
         */
        int max_depth(TreeNode* root) {
            if (!root)
                return 0; // Base case: null node has depth 0
    
            // Recursively find the depth of left and right subtrees
            int left = max_depth(root->left);
            int right = max_depth(root->right);
    
            // The path through this node = left depth + right depth
            // Update the diameter if this path is the longest so far
            this->ans = max(this->ans, left + right);
    
            // Return the depth of the current node's subtree
            return max(left, right) + 1;
        }
    };
    