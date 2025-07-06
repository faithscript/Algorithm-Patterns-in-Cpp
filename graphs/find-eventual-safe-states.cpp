// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

// Example 1:

// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
// Example 2:

// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
// Explanation:
// Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].length <= n
// 0 <= graph[i][j] <= n - 1
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
SOLUTION EXPLANATION
===================

This problem asks us to find nodes that are "eventually safe" - meaning all paths
from these nodes lead to terminal nodes (nodes with no outgoing edges).

Key Insights:
1. A node is safe if ALL paths from it lead to terminal nodes
2. A node is unsafe if ANY path from it leads to a cycle
3. Terminal nodes are always safe (base case)
4. We need to detect cycles during traversal

Approach: DFS with Cycle Detection and Memoization
1. Use DFS to explore all paths from each node
2. Track nodes in current recursion stack to detect cycles
3. Memoize results to avoid redundant computation
4. A node is safe only if ALL its neighbors are safe

Algorithm:
1. For each node, run DFS to determine if it's safe
2. During DFS, track current path to detect cycles
3. If we reach a terminal node → safe
4. If we detect a cycle → unsafe
5. If any neighbor is unsafe → current node is unsafe
6. Memoize results for efficiency

Time: O(V + E) - each edge is visited at most once
Space: O(V) - for recursion stack and memoization
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> memo(n, -1);  // -1: unvisited, 0: unsafe, 1: safe
        vector<int> result;
        
        // Check each node
        for (int i = 0; i < n; i++) {
            if (isSafe(i, graph, memo)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
private:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& memo) {
        // If already computed, return memoized result
        if (memo[node] != -1) {
            return memo[node] == 1;
        }
        
        // Mark as currently visiting (for cycle detection)
        memo[node] = 0;
        
        // Check all neighbors
        for (int neighbor : graph[node]) {
            // If any neighbor is unsafe, this node is unsafe
            if (!isSafe(neighbor, graph, memo)) {
                memo[node] = 0;  // Mark as unsafeBro sometimadsS
                return false;
            }
        }
        
        // All neighbors are safe, so this node is safe
        memo[node] = 1;
        return true;
    }
};

// Alternative solution using DFS with cycle detection
class SolutionDFS {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);  // 0: unvisited, 1: visiting, 2: safe, 3: unsafe
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, visited) == 2) {  // 2 means safe
                result.push_back(i);
            }
        }
        
        return result;
    }
    
private:
    // Returns: 2 = safe, 3 = unsafe
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        // If already determined, return result
        if (visited[node] == 2) return 2;  // Safe
        if (visited[node] == 3) return 3;  // Unsafe
        
        // If currently visiting, we found a cycle
        if (visited[node] == 1) {
            visited[node] = 3;  // Mark as unsafe
            return 3;
        }
        
        // Mark as currently visiting
        visited[node] = 1;
        
        // Check all neighbors
        for (int neighbor : graph[node]) {
            if (dfs(neighbor, graph, visited) == 3) {
                visited[node] = 3;  // Mark as unsafe
                return 3;
            }
        }
        
        // All neighbors are safe, so this node is safe
        visited[node] = 2;
        return 2;
    }
};

// Example usage and demonstration
void demonstrateSolution() {
    Solution solution;
    
    // Example 1: [[1,2],[2,3],[5],[0],[5],[],[]]
    vector<vector<int>> graph1 = {
        {1, 2},    // Node 0 -> 1, 2
        {2, 3},    // Node 1 -> 2, 3
        {5},        // Node 2 -> 5
        {0},        // Node 3 -> 0
        {5},        // Node 4 -> 5
        {},         // Node 5 -> (terminal)
        {}          // Node 6 -> (terminal)
    };
    
    cout << "Example 1:" << endl;
    cout << "Graph: [[1,2],[2,3],[5],[0],[5],[],[]]" << endl;
    vector<int> result1 = solution.eventualSafeNodes(graph1);
    cout << "Safe nodes: ";
    for (int node : result1) cout << node << " ";
    cout << endl << endl;
    
    // Example 2: [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    vector<vector<int>> graph2 = {
        {1, 2, 3, 4},  // Node 0 -> 1, 2, 3, 4
        {1, 2},         // Node 1 -> 1, 2
        {3, 4},         // Node 2 -> 3, 4
        {0, 4},         // Node 3 -> 0, 4
        {}               // Node 4 -> (terminal)
    };
    
    cout << "Example 2:" << endl;
    cout << "Graph: [[1,2,3,4],[1,2],[3,4],[0,4],[]]" << endl;
    vector<int> result2 = solution.eventualSafeNodes(graph2);
    cout << "Safe nodes: ";
    for (int node : result2) cout << node << " ";
    cout << endl;
}

int main() {
    demonstrateSolution();
    return 0;
}

