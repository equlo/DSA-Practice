#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstColZero = false;

    // Step 1: Mark rows and columns
    for (int i = 0; i < rows; i++) {

        if (matrix[i][0] == 0)
            firstColZero = true;

        for (int j = 1; j < cols; j++) {

            if (matrix[i][j] == 0) {

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Update matrix using markers
    for (int i = rows - 1; i >= 0; i--) {

        for (int j = cols - 1; j >= 1; j--) {

            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }

        if (firstColZero)
            matrix[i][0] = 0;
    }
}

void printMatrix(vector<vector<int>>& matrix) {

    for (auto row : matrix) {

        for (auto val : row) {
            cout << val << " ";
        }

        cout << endl;
    }
}

int main() {

    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";

    printMatrix(matrix);

    return 0;
}