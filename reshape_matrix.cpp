#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();

    if (m * n != r * c)
        return mat;

    vector<vector<int>> result(r, vector<int>(c));

    int idx = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[idx / c][idx % c] = mat[i][j];
            idx++;
        }
    }

    return result;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    vector<vector<int>> result = matrixReshape(mat, r, c);

    cout << "Reshaped Matrix:\n";
    for (auto &row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}