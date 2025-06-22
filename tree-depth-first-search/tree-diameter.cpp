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