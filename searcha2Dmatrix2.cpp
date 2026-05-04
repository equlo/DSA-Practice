#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0;
    int j = col - 1; // start from top-right

    while(i < row && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        }
        else if(matrix[i][j] > target) {
            j--; // move left
        }
        else {
            i++; // move down
        }
    }
    return false;
}

int main() {
    // Your given matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 30}
    };

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