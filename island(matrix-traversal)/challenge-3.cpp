// You are given a 2D matrix containing different characters, you need to find if there exists any cycle consisting of the same character in the matrix.
// A cycle is a path in the matrix that starts and ends at the same cell and has four or more cells. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same character value of the current cell.
// Write a function to find if the matrix has a cycle.

class Solution {
public:
    int rows, cols;

    // Main function to check for any cycle in the grid
    bool hasCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Visited matrix to track visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Traverse every cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If this cell hasn't been visited yet, start DFS from here
                if (!visited[i][j]) {
                    // Start DFS with previous coordinates (-1, -1) since there's no parent
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;  // cycle found
                    }
                }
            }
        }

        return false;  // no cycles found
    }

    // DFS helper to detect cycle
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
             int i, int j, int pi, int pj, char target) {
        // Out of bounds or different character — stop DFS
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != target)
            return false;

        // If this cell was already visited and it's not the parent, we found a cycle
        if (visited[i][j])
            return true;

        // Mark this cell as visited
        visited[i][j] = true;

        // 4-directional movement: down, up, right, left
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto [di, dj] : directions) `{
            int ni = i + di;
            int nj = j + dj;

            // Skip the cell we just came from (the parent)
            if (ni == pi && nj == pj) continue;

            // Recursively DFS into neighbors
            if (dfs(grid, visited, ni, nj, i, j, target))
                return true;  // if any neighbor leads to a cycle, return true
        }

        return false;  // no cycle found from this path
    }
};
