// You are given a 2D matrix containing only 1s (land) and 0s (water).

// An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water). Each cell is considered connected to other cells horizontally or vertically (not diagonally).

// Two islands are considered the same if and only if they can be translated (not rotated or reflected) to equal each other.

// Write a function to find the number of distinct islands in the given matrix.

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        set<string> shapes;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    string path;
                    dfs(grid, i, j, path, 'o');  // 'o' for origin
                    shapes.insert(path);
                }
            }
        }

        return shapes.size();
    }

    void dfs(vector<vector<int>>& grid, int i, int j, string& path, char dir) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        path += dir;

        dfs(grid, i+1, j, path, 'd');
        dfs(grid, i-1, j, path, 'u');
        dfs(grid, i, j+1, path, 'r');
        dfs(grid, i, j-1, path, 'l');

        path += 'b';  // backtrack marker
    }
};
