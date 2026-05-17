#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        // Boundary check
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;

        // Mark safe cells
        board[i][j] = '#';

        // Visit 4 directions
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // Traverse left and right boundaries
        for(int i = 0; i < m; i++) {

            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // Traverse top and bottom boundaries
        for(int j = 0; j < n; j++) {

            if(board[0][j] == 'O')
                dfs(board, 0, j);

            if(board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Convert surrounded O -> X
        // Restore # -> O
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {

    int m, n;

    cout << "Enter number of rows: ";
    cin >> m;

    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<char>> board(m, vector<char>(n));

    cout << "Enter the board elements (X or O):\n";

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solve(board);

    cout << "\nBoard after solving:\n";

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}