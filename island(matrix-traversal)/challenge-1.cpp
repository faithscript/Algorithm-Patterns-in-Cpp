// You are given a 2D matrix containing only 1s (land) and 0s (water).

// An island is a connected set of 1s (land) and is surrounded by either an edge or 0s (water). Each cell is considered connected to other cells horizontally or vertically (not diagonally).

// There are no lakes on the island, so the water inside the island is not connected to the water around it. A cell is a square with a side length of 1.

// The given matrix has only one island, write a function to find the perimeter of that island.

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    // Check cell above
                    if (i > 0 && grid[i - 1][j] == 1)
                        perimeter -= 2;

                    // Check cell to the left
                    if (j > 0 && grid[i][j - 1] == 1)
                        perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};
