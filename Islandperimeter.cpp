#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                perimeter += 4;

                if(i + 1 < rows && grid[i + 1][j] == 1)
                    perimeter -= 2;

                if(j + 1 < cols && grid[i][j + 1] == 1)
                    perimeter -= 2;
            }
        }
    }
    return perimeter;
}

int main() {
    int row, col;

    cout << "Enter rows and columns: ";
    cin >> row >> col;

    vector<vector<int>> grid(row, vector<int>(col));

    cout << "Enter the grid (0 for water, 1 for land):\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    int result = islandPerimeter(grid);

    cout << "Island Perimeter = " << result << endl;

    return 0;
}