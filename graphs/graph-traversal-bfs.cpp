#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
BREADTH-FIRST SEARCH (BFS) GRAPH TRAVERSAL
==========================================

BFS explores a graph's vertices level by level, starting from a source node and
moving outward to visit all nodes at the same distance before moving to the next level.

Step-by-Step Algorithm:
1. Graph Initialization: Create graph with V vertices using adjacency list
2. Mark All Vertices as Unvisited: Initialize visited array
3. Initialize BFS Traversal: Mark start vertex as visited, add to queue
4. Perform BFS Traversal: Process queue until empty
5. End Condition: Queue becomes empty
*/

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

public:
    // Step 1: Graph Initialization
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    // Add undirected edge to adjacency list
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }
    
    // Add directed edge to adjacency list
    void addDirectedEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    // BFS Traversal following the step-by-step algorithm
    // Time: O(V + E), Space: O(V)
    void bfs(int startVertex) {
        // Input validation
        if (startVertex < 0 || startVertex >= V) {
            cout << "Invalid start vertex: " << startVertex << endl;
            return;
        }
        
        cout << "BFS starting from vertex " << startVertex << ":" << endl;
        
        // Step 2: Mark All Vertices as Unvisited
        vector<bool> visited(V, false);
        
        // Queue for BFS traversal
        queue<int> q;
        
        // Step 3: Initialize BFS Traversal
        visited[startVertex] = true;  // Mark start vertex as visited
        q.push(startVertex);          // Add start vertex to queue
        
        cout << "Level 0: " << startVertex << endl;
        int level = 0;
        
        // Step 4: Perform BFS Traversal
        while (!q.empty()) {
            int levelSize = q.size();
            cout << "Level " << level << " (size: " << levelSize << "): ";
            
            // Process all vertices at current level
            for (int i = 0; i < levelSize; i++) {
                // Dequeue a vertex from the front of the queue
                int currentVertex = q.front();
                q.pop();
                
                // Process the currentVertex (print its value)
                cout << currentVertex << " ";
                
                // For each neighbor of currentVertex (from its adjacency list)
                for (int neighbor : adj[currentVertex]) {
                    // If the neighbor is unvisited
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;  // Mark it as visited
                        q.push(neighbor);          // Enqueue the neighbor into the queue
                    }
                }
            }
            cout << endl;
            level++;
        }
        
        // Step 5: End Condition - Queue is empty, all reachable vertices visited
        cout << "BFS traversal completed. All reachable vertices from " << startVertex << " have been visited." << endl << endl;
    }
};

int main() {
    // Step 1: Graph Initialization
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    
    cout << "Graph structure:" << endl;
    cout << "    0 -- 1 -- 2" << endl;
    cout << "    |    |" << endl;
    cout << "    3 -- 4" << endl << endl;
    
    // BFS from vertex 0
    g.bfs(0);
    
    return 0;
}
