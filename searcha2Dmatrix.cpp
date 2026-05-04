#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        int element = matrix[mid / col][mid % col];

        if(element == target) {
            return true;
        }
        else if(element < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    int row, col;
    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    bool found = searchMatrix(matrix, target);

    if(found) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}