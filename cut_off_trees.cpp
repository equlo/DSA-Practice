#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
    if (sr == tr && sc == tc) return 0;

    int m = forest.size();
    int n = forest[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;

    q.push({sr, sc});
    visited[sr][sc] = true;

    int steps = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            auto current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            if (r == tr && c == tc)
                return steps;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc] &&
                    forest[nr][nc] != 0) {

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        steps++;
    }

    return -1;
}

int cutOffTree(vector<vector<int>>& forest) {
    vector<tuple<int, int, int>> trees;

    int m = forest.size();
    int n = forest[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (forest[i][j] > 1) {
                trees.push_back({forest[i][j], i, j});
            }
        }
    }

    sort(trees.begin(), trees.end());

    int totalSteps = 0;
    int currR = 0, currC = 0;

    for (auto tree : trees) {
        int height, r, c;
        tie(height, r, c) = tree;

        int dist = bfs(forest, currR, currC, r, c);

        if (dist == -1)
            return -1;

        totalSteps += dist;

        currR = r;
        currC = c;

        forest[r][c] = 1;
    }

    return totalSteps;
}

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> forest(m, vector<int>(n));

    cout << "Enter forest matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }

    cout << "Minimum Steps = " << cutOffTree(forest) << endl;

    return 0;
}