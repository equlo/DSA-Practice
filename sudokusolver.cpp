#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            // Row check
            if (board[row][i] == num)
                return false;

            // Column check
            if (board[i][col] == num)
                return false;

            // 3x3 Box check
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if (board[r][c] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char num = '1'; num <= '9'; num++) {

                        if (isValid(board, row, col, num)) {

                            board[row][col] = num;

                            if (solve(board))
                                return true;

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {

    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku Board (use . for empty cells):\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solveSudoku(board);

    cout << "\nSolved Sudoku:\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}