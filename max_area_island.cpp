#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& grid, int r, int c) {
    int m = grid.size();
    int n = grid[0].size();

    if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0)
        return 0;

    grid[r][c] = 0; // visited

    return 1 +
           dfs(grid, r + 1, c) +
           dfs(grid, r - 1, c) +
           dfs(grid, r, c + 1) +
           dfs(grid, r, c - 1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
    }

    return maxArea;
}

int main() {
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << "Maximum Area of Island: "
         << maxAreaOfIsland(grid);

    return 0;
}