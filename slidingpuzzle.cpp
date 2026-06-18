#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    string start = "";

    for (auto &row : board) {
        for (int num : row) {
            start += char(num + '0');
        }
    }

    string target = "123450";

    vector<vector<int>> adj = {
        {1, 3},      // index 0
        {0, 2, 4},   // index 1
        {1, 5},      // index 2
        {0, 4},      // index 3
        {1, 3, 5},   // index 4
        {2, 4}       // index 5
    };

    queue<pair<string, int>> q;
    unordered_set<string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        string state = current.first;
        int moves = current.second;

        if (state == target)
            return moves;

        int zeroPos = state.find('0');

        for (int nextPos : adj[zeroPos]) {
            string nextState = state;
            swap(nextState[zeroPos], nextState[nextPos]);

            if (visited.find(nextState) == visited.end()) {
                visited.insert(nextState);
                q.push({nextState, moves + 1});
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> board = {
        {4, 1, 2},
        {5, 0, 3}
    };

    cout << "Minimum moves: " << slidingPuzzle(board) << endl;

    return 0;
}