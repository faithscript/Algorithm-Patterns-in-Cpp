// Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.

// Image
// Image
// Constraints:

// 1 <= arr.length <= 5000
// 0 <= arr[i] <= 9
// Each node's value is between [0 - 9].

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }

    bool dfs(TreeNode* node, vector<int>& arr, int index) {
        if (!node || index >= arr.size() || node->val != arr[index])
            return false;

        // If it's a leaf and last index matches
        if (!node->left && !node->right && index == arr.size() - 1)
            return true;

        // Recurse into children
        return dfs(node->left, arr, index + 1) || dfs(node->right, arr, index + 1);
    }
};
