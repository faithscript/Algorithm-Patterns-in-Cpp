// If the depth of a tree is smaller than 5, then this tree can be represented by an array of three-digit integers. For each integer in this array:

// The hundreds digit represents the depth d of this node where 1 <= d <= 4.
// The tens digit represents the position p of this node in the level it belongs to where 1 <= p <= 8. The position is the same as that in a full binary tree.
// The units digit represents the value v of this node where 0 <= v <= 9.
// Given an array of ascending three-digit integers nums representing a binary tree with a depth smaller than 5, return the sum of all paths from the root towards the leaves.

// It is guaranteed that the given array represents a valid connected binary tree.

 

// Example 1:



// Input: nums = [113,215,221]
// Output: 12
// Explanation: The tree that the list represents is shown.
// The path sum is (3 + 5) + (3 + 1) = 12.

class Solution {
public:
    unordered_map<int, int> tree;  // key: depth * 10 + pos, value: node value
    int totalSum = 0;
    int pathSum = 0;  // Shared variable

    void dfs(int depth, int pos) {
        int key = depth * 10 + pos;
        if (!tree.count(key)) return;

        pathSum += tree[key];

        int leftKey = (depth + 1) * 10 + (pos * 2 - 1);
        int rightKey = (depth + 1) * 10 + (pos * 2);

        if (!tree.count(leftKey) && !tree.count(rightKey)) {
            totalSum += pathSum;
            return;
        }

        dfs(depth + 1, pos * 2 - 1);
        dfs(depth + 1, pos * 2);  

        pathSum -= tree[key];  // Backtrack
    }

    int pathSum(vector<int>& nums) {
        for (int num : nums) {
            int d = num / 100;
            int p = (num / 10) % 10;
            int v = num % 10;
            tree[d * 10 + p] = v;
        }

        dfs(1, 1);
        return totalSum;
    }
};
