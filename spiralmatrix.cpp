#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cout << "Enter rows and columns: "; // enter the number of rows and columns for the matrix
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));

    cout << "Enter matrix elements:\n"; // enter the elements of the matrix
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans;

    int startingRow = 0;
    int endingRow = row - 1;
    int startingCol = 0;
    int endingCol = col - 1;

    int total = row * col;
    int count = 0;

    while(count < total) {

        // Left → Right
        for(int i = startingCol; i <= endingCol && count < total; i++) {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        // Top → Bottom
        for(int i = startingRow; i <= endingRow && count < total; i++) {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        // Right → Left
        for(int i = endingCol; i >= startingCol && count < total; i--) {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        // Bottom → Top
        for(int i = endingRow; i >= startingRow && count < total; i--) {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    cout << "Spiral Order: "; // print the elements in spiral order
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}