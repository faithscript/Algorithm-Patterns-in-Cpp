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
    // Main function to return the minimum root to leaf sum
    int minRootToLeafSum(TreeNode* root) {
        // Base case: if the tree is empty, return a large value since we are finding the minimum sum
        if (root == nullptr) {
            return INT_MAX;
        }

        // Base case: if we reached a leaf node, return its value
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        // Recursive case: compute the minimum sum for left and right subtrees
        int leftSum = minRootToLeafSum(root->left);
        int rightSum = minRootToLeafSum(root->right);

        // Return the minimum of the two sums, adding the current node's value
        return root->val + min(leftSum, rightSum);
    }
};
