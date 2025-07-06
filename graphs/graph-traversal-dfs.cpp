// Depth-First Search (DFS) Graph Traversal
// DFS explores as far as possible along each branch before backtracking
// Works on both directed and undirected graphs
// Can be implemented using recursion or explicit stack

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Recursive DFS Implementation
    void dfsRecursive(int node, vector<bool>& visited, vector<vector<int>>& graph) {
        // Mark current node as visited
        visited[node] = true;
        cout << "Visiting: " << node << endl;
        
        // Explore all neighbors of current node
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited, graph);
            }
        }
    }
    
    // Iterative DFS Implementation (using stack)
    void dfsIterative(int start, vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        stack<int> st;
        st.push(start);
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            // Only process if not already visited
            if (!visited[node]) {
                visited[node] = true;
                cout << "Visiting: " << node << endl;
                
                // Push all unvisited neighbors onto stack
                // Note: We push in reverse order to maintain DFS order
                for (int i = graph[node].size() - 1; i >= 0; i--) {
                    int neighbor = graph[node][i];
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
    }
    
    // Complete graph traversal (handles disconnected components)
    void traverseGraph(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        
        // Start DFS from each unvisited node
        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i]) {
                cout << "Starting DFS from node: " << i << endl;
                dfsRecursive(i, visited, graph);
            }
        }
    }
    
    // Example usage
    void example() {
        // Example graph: 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3
        // Adjacency list representation
        vector<vector<int>> graph = {
            {1, 2},    // Node 0 connects to nodes 1 and 2
            {3},       // Node 1 connects to node 3
            {3},       // Node 2 connects to node 3
            {}         // Node 3 has no outgoing edges
        };
        
        cout << "Recursive DFS:" << endl;
        traverseGraph(graph);
        
        cout << "\nIterative DFS from node 0:" << endl;
        dfsIterative(0, graph);
    }
};

/*
Algorithm Steps:

1. Initialize:
   - Create visited array to track visited nodes
   - Choose starting node

2. Recursive Approach:
   - Mark current node as visited
   - Process current node (print, count, etc.)
   - Recursively visit all unvisited neighbors

3. Iterative Approach:
   - Use stack to simulate recursion
   - Push starting node onto stack
   - While stack not empty:
     * Pop node from stack
     * If not visited, mark as visited and process
     * Push all unvisited neighbors onto stack

4. Handle Disconnected Components:
   - Start DFS from each unvisited node
   - Ensures all nodes are visited

Time Complexity: O(V + E) where V = vertices, E = edges
Space Complexity: O(V) for visited array + recursion stack
*/
