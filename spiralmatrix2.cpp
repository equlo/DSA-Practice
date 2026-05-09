#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int num = 1;

    while (top <= bottom && left <= right) {

        // Left to Right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        // Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> result = generateMatrix(n);

    cout << "Spiral Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}