#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> dirs = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},          {0,1},
        {1,-1},  {1,0},  {1,1}
    };

    void dfs(vector<vector<char>>& board, int r, int c) {
        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E')
            return;

        int mines = 0;

        for (auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                board[nr][nc] == 'M') {
                mines++;
            }
        }

        if (mines > 0) {
            board[r][c] = mines + '0';
            return;
        }

        board[r][c] = 'B';

        for (auto &d : dirs) {
            dfs(board, r + d[0], c + d[1]);
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);
        return board;
    }
};

int main() {
    int m, n;

    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<char>> board(m, vector<char>(n));

    cout << "Enter board elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> click(2);
    cout << "Enter click position (row col): ";
    cin >> click[0] >> click[1];

    Solution obj;
    vector<vector<char>> result = obj.updateBoard(board, click);

    cout << "\nUpdated Board:\n";
    for (auto &row : result) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}