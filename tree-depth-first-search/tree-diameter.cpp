// Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

// Note: You can always assume that there are at least two leaf nodes in the given tree.

// Image
// Image
// Constraints:

// n == edges.length + 1
// 1 <= n <= 104
// 0 <= ai, bi < n
// ai != bi


class Solution {
public:
  int maxDiameter = 0;

  // Helper function to calculate height and update diameter
  int dfs(TreeNode *node) {
    if (!node) return 0;

    int leftHeight = dfs(node->left);
    int rightHeight = dfs(node->right);

    // Update the max diameter at this node (as a number of nodes)
    int diameterAtNode = leftHeight + rightHeight + 1;
    maxDiameter = max(maxDiameter, diameterAtNode);

    // Return height to parent
    return max(leftHeight, rightHeight) + 1;
  }

  int findDiameter(TreeNode *root) {
    dfs(root);
    return maxDiameter;
  }
};

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

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
public:
    int mx = 0;
    int dfs(TreeNode* node){
        if(!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);

        mx = max(mx, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return mx;
    }
};