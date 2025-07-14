// Given the root of a binary tree, explore all possible root-to-leaf paths, compute the sum of values along each path, and return the minimum sum.

// A leaf node is a node with no children.

// Examples
// Example 1:
// Input: root = [10, 5, 15, null, null, 7, 20]
// Image
// Expected Output: 15
// Justification: The path with the minimum sum is 10 -> 5. The sum is 10 + 5 = 15.

class Solution {
public:
    int minSum = INT_MAX;

    int minRootToLeafSum(TreeNode* root) {
        int currentSum = 0;  // Shared variable
        dfs(root, currentSum);
        return minSum;
    }

    void dfs(TreeNode* node, int& currentSum) {  // Pass by reference
        if (!node) return;

        currentSum += node->val;  // Add current node's value

        // If it's a leaf node, update the minimum
        if (!node->left && !node->right) {
            minSum = min(minSum, currentSum);
            currentSum -= node->val;  // Backtrack
            return;
        }

        dfs(node->left, currentSum);   // Explore left subtree
        dfs(node->right, currentSum);  // Explore right subtree
        
        currentSum -= node->val;  // Backtrack: restore the value
    }
};
