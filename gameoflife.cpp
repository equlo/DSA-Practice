#include <iostream>
#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<pair<int, int>> dir = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},           {0,1},
        {1,-1},  {1,0},  {1,1}
    };

    // Step 1: Mark transitions
    // -1 = live -> dead
    //  2 = dead -> live

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            int live = 0;

            for(auto d : dir) {
                int ni = i + d.first;
                int nj = j + d.second;

                if(ni >= 0 && ni < m && nj >= 0 && nj < n) {

                    // Count original live cells
                    if(board[ni][nj] == 1 || board[ni][nj] == -1)
                        live++;
                }
            }

            // Current cell is alive
            if(board[i][j] == 1) {

                if(live < 2 || live > 3)
                    board[i][j] = -1;
            }
            // Current cell is dead
            else {

                if(live == 3)
                    board[i][j] = 2;
            }
        }
    }

    // Step 2: Final update
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {

            if(board[i][j] > 0)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

int main() {

    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    gameOfLife(board);

    cout << "Updated Board:\n";

    for(auto row : board) {
        for(auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}