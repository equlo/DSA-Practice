#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();

        // Check whether transformation is possible
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((board[0][0] ^ board[i][0] ^
                     board[0][j] ^ board[i][j]) == 1) {
                    return -1;
                }
            }
        }

        int rowSum = 0, colSum = 0;
        int rowSwap = 0, colSwap = 0;

        for (int i = 0; i < n; i++) {
            rowSum += board[i][0];
            colSum += board[0][i];

            // Count rows/columns already matching pattern 0,1,0,1...
            if (board[i][0] == i % 2)
                rowSwap++;

            if (board[0][i] == i % 2)
                colSwap++;
        }

        // Check validity of number of 0s and 1s
        if (abs(n - 2 * rowSum) > 1 ||
            abs(n - 2 * colSum) > 1) {
            return -1;
        }

        // For odd n
        if (n % 2) {
            if (rowSwap % 2)
                rowSwap = n - rowSwap;

            if (colSwap % 2)
                colSwap = n - colSwap;
        }
        // For even n
        else {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        }

        return (rowSwap + colSwap) / 2;
    }
};

int main() {
    int n;
    cout << "Enter size of board (n): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    cout << "Enter the board elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    cout << "Minimum moves required: "
         << obj.movesToChessboard(board) << endl;

    return 0;
}