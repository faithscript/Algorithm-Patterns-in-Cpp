// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
SOLUTION EXPLANATION
===================

This problem asks us to find the number of connected components (provinces) in a graph.

Key Insights:
1. The adjacency matrix isConnected[i][j] = 1 means cities i and j are directly connected
2. A province is a connected component - all cities reachable from each other
3. We need to count how many separate groups of connected cities exist

Approach:
1. Use DFS or BFS to traverse the graph
2. Each time we start a new traversal from an unvisited city, we've found a new province
3. Count the number of times we start a new traversal

Algorithm:
1. Initialize visited array to track visited cities
2. For each unvisited city:
   - Start DFS/BFS from that city
   - Mark all reachable cities as visited
   - Increment province count
3. Return the total count

Time: O(n²) - we visit each cell in the adjacency matrix once
Space: O(n) - for the visited array and recursion stack
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> seen(n, false);
        int res = 0;

        for(int i = 0; i < n; i++){
            if(!seen[i]){
                dfs(i, seen, isConnected);
                res++;
            }
        }
        return res;

    }
    void dfs(int node, vector<bool>& seen, vector<vector<int>>& graph){
        seen[node] = true;

        for(int i = 0; i < graph.size(); i++){
            if(graph[node][i] == 1 && !seen[i]){
                dfs(i, seen, graph);
            }
        }
    }
};

// Alternative solution using BFS
class SolutionBFS {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                provinces++;
            }
        }
        
        return provinces;
    }
    
private:
    void bfs(int startCity, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        visited[startCity] = true;
        q.push(startCity);
        
        while (!q.empty()) {
            int currentCity = q.front();
            q.pop();
            
            // Check all other cities
            for (int nextCity = 0; nextCity < isConnected.size(); nextCity++) {
                if (isConnected[currentCity][nextCity] == 1 && !visited[nextCity]) {
                    visited[nextCity] = true;
                    q.push(nextCity);
                }
            }
        }
    }
};

// Example usage and demonstration
void demonstrateSolution() {
    Solution solution;
    
    // Example 1: [[1,1,0],[1,1,0],[0,0,1]]
    // Cities 0 and 1 are connected, city 2 is separate
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    cout << "Example 1:" << endl;
    cout << "Matrix:" << endl;
    for (const auto& row : isConnected1) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Provinces: " << solution.findCircleNum(isConnected1) << endl << endl;
    
    // Example 2: [[1,0,0],[0,1,0],[0,0,1]]
    // All cities are separate
    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    
    cout << "Example 2:" << endl;
    cout << "Matrix:" << endl;
    for (const auto& row : isConnected2) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Provinces: " << solution.findCircleNum(isConnected2) << endl << endl;
    
    // Additional example: All cities connected
    vector<vector<int>> isConnected3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    
    cout << "Example 3 (all connected):" << endl;
    cout << "Matrix:" << endl;
    for (const auto& row : isConnected3) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "Provinces: " << solution.findCircleNum(isConnected3) << endl;
}

int main() {
    demonstrateSolution();
    return 0;
}

