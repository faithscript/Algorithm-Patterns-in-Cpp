// Given a root of the binary tree and an integer key, find the level order successor of the node containing the given key as a value in the tree.

// The level order successor is the node that appears right after the given node in the level order traversal.

// Examples
// Example 1
// Input: root = [1, 2, 3, 4, 5], key = 3
// Image
// Output: 4
// Explanation: The level-order traversal of the tree is [1, 2, 3, 4, 5]. The successor of 3 in this order is 4.

class Solution {
public:
    TreeNode* findLevelOrderSuccessor(TreeNode* root, int key) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            // Enqueue children
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

            // After pushing children, check if this is the node with the key
            if (curr->val == key) {
                return q.empty() ? nullptr : q.front();  // next in queue = successor
            }
        }

        return nullptr; // Key not found
    }
};
