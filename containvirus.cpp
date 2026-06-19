#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size();
        int n = isInfected[0].size();

        int totalWalls = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (true) {
            vector<vector<pair<int, int>>> regions;
            vector<unordered_set<int> > frontiers;
            vector<int> wallsNeeded;

            vector<vector<int> > visited(m, vector<int>(n, 0));

            // Find all infected regions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (isInfected[i][j] == 1 && !visited[i][j]) {

                        vector<pair<int, int> > region;
                        unordered_set<int> frontier;
                        int walls = 0;

                        queue<pair<int, int> > q;
                        q.push(make_pair(i, j));
                        visited[i][j] = 1;

                        while (!q.empty()) {
                            pair<int, int> cur = q.front();
                            q.pop();

                            int x = cur.first;
                            int y = cur.second;

                            region.push_back(make_pair(x, y));

                            for (int d = 0; d < 4; d++) {
                                int nx = x + dx[d];
                                int ny = y + dy[d];

                                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                                    continue;

                                if (isInfected[nx][ny] == 1 &&
                                    !visited[nx][ny]) {

                                    visited[nx][ny] = 1;
                                    q.push(make_pair(nx, ny));
                                }
                                else if (isInfected[nx][ny] == 0) {

                                    walls++;
                                    frontier.insert(nx * n + ny);
                                }
                            }
                        }

                        regions.push_back(region);
                        frontiers.push_back(frontier);
                        wallsNeeded.push_back(walls);
                    }
                }
            }

            int target = -1;
            int maxThreat = 0;

            // Find region threatening maximum cells
            for (int i = 0; i < (int)frontiers.size(); i++) {
                if ((int)frontiers[i].size() > maxThreat) {
                    maxThreat = frontiers[i].size();
                    target = i;
                }
            }

            if (target == -1)
                break;

            totalWalls += wallsNeeded[target];

            // Quarantine selected region
            for (int i = 0; i < (int)regions[target].size(); i++) {
                int x = regions[target][i].first;
                int y = regions[target][i].second;
                isInfected[x][y] = -1;
            }

            // Spread virus from remaining regions
            for (int i = 0; i < (int)regions.size(); i++) {

                if (i == target)
                    continue;

                for (unordered_set<int>::iterator it = frontiers[i].begin();
                     it != frontiers[i].end(); ++it) {

                    int pos = *it;
                    int x = pos / n;
                    int y = pos % n;

                    isInfected[x][y] = 1;
                }
            }
        }

        return totalWalls;
    }
};

int main() {
    vector<vector<int> > grid = {
        {0,1,0,0,0,0,0,1},
        {0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0}
    };

    Solution obj;
    cout << obj.containVirus(grid) << endl;

    return 0;
}