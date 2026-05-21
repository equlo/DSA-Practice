#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int maxi = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // First row or first column
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }
                else if(matrix[i][j] == '1') {

                    dp[i][j] = 1 + min({
                        dp[i-1][j],      // top
                        dp[i][j-1],      // left
                        dp[i-1][j-1]     // diagonal
                    });
                }
                else {
                    dp[i][j] = 0;
                }

                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi * maxi;
    }
};

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution obj;

    cout << "Maximum Square Area: "
         << obj.maximalSquare(matrix);

    return 0;
}