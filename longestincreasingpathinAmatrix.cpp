#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    // Directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& matrix, int i, int j) {

        // If already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            // Valid move and increasing value
            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans, 1 + dfs(matrix, ni, nj));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, i, j));
            }
        }

        return result;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution obj;

    cout << "Longest Increasing Path Length = "
         << obj.longestIncreasingPath(matrix);

    return 0;
}