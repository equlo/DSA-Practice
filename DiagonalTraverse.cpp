#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> result;

    for (int d = 0; d < m + n - 1; d++) {
        vector<int> diagonal;

        int row = (d < n) ? 0 : d - n + 1;
        int col = (d < n) ? d : n - 1;

        while (row < m && col >= 0) {
            diagonal.push_back(mat[row][col]);
            row++;
            col--;
        }

        if (d % 2 == 0) {
            reverse(diagonal.begin(), diagonal.end());
        }

        result.insert(result.end(), diagonal.begin(), diagonal.end());
    }

    return result;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = findDiagonalOrder(mat);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}