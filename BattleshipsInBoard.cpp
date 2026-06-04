#include <iostream>
#include <vector>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // Skip empty cells
            if (board[i][j] == '.')
                continue;

            // If there is an 'X' above, this is not the start
            if (i > 0 && board[i - 1][j] == 'X')
                continue;

            // If there is an 'X' on the left, this is not the start
            if (j > 0 && board[i][j - 1] == 'X')
                continue;

            count++;
        }
    }

    return count;
}

int main() {
    int m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    cout << "Enter the board (X for battleship, . for empty):\n";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { 
            cin >> board[i][j];
        }
    }

    cout << "\nNumber of battleships: "
         << countBattleships(board) << endl;

    return 0;
}