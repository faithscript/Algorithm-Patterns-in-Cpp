// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

// Example 1:


// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3
 

// Constraints:

// The number of nodes in the tree is in the range [0, 1000].
// -109 <= Node.val <= 109
// -1000 <= targetSum <= 1000

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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int count = countFrom(root, targetSum);

        count += pathSum(root->left, targetSum);    
        count += pathSum(root->right, targetSum);

        return count;
    }
    int countFrom(TreeNode* node, long long target){
        if(!node) return 0;

        int count = 0;
        if(node->val == target) count++;

        count += countFrom(node->left, target - node->val);
        count += countFrom(node->right, target - node->val);

        return count;
    }
};

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
    int count = 0;

    void dfs(TreeNode* node, long long rS, int targetSum, unordered_map<long long, int>& runningSumCount){
        if(!node) return;

        rS += node->val;

        count += runningSumCount[rS - targetSum];
        runningSumCount[rS]++;

        dfs(node->left, rS, targetSum, runningSumCount);
        dfs(node->right, rS, targetSum, runningSumCount);
        runningSumCount[rS]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> runningSumCount;
        runningSumCount[0] = 1;
        dfs(root, 0, targetSum, runningSumCount);
        return count;
    }
};