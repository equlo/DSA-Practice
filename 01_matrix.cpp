#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
            } else {
                mat[i][j] = -1;
            }
        }
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                mat[nx][ny] == -1) {

                mat[nx][ny] = mat[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return mat;
}

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Enter matrix elements (0 or 1):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> result = updateMatrix(mat);

    cout << "\nDistance Matrix:\n";
    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}