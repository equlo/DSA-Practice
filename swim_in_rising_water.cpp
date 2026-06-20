#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});

        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (visited[r][c])
                continue;

            visited[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return time;

            for (auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    pq.push({
                        max(time, grid[nr][nc]),
                        nr,
                        nc
                    });
                }
            }
        }

        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.swimInWater(grid);

    return 0;
}