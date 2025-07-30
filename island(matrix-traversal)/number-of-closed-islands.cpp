// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

 

// Example 1:



// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// Example 2:



// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// Example 3:

// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
 

// Constraints:

// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // flood fill all boarders then look for islands
        int r = grid.size(), c = grid[0].size(), cnt = 0;

        for(int i = 0; i < r; ++i){
            dfs(i, 0, grid);
            dfs(i, c - 1, grid);
        }
        for(int j = 0; j < c; ++j){
            dfs(0, j, grid);
            dfs(r - 1, j, grid);
        }

        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1) return;

        grid[i][j] = 1;

        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
    }
};