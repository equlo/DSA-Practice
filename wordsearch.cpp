#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int index) {

        // If all characters are matched
        if (index == word.length()) {
            return true;
        }

        // Boundary check + character mismatch
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
            || board[i][j] != word[index]) {
            return false;
        }

        // Store current character
        char temp = board[i][j];

        // Mark as visited
        board[i][j] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    Solution obj;

    if (obj.exist(board, word)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}