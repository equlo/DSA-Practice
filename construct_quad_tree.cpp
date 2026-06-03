#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:

    bool isUniform(vector<vector<int>>& grid, int row, int col, int size) {
        int value = grid[row][col];

        for (int i = row; i < row + size; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] != value)
                    return false;
            }
        }
        return true;
    }

    Node* build(vector<vector<int>>& grid, int row, int col, int size) {

        if (isUniform(grid, row, col, size)) {
            return new Node(grid[row][col], true);
        }

        int half = size / 2;

        Node* topLeft = build(grid, row, col, half);
        Node* topRight = build(grid, row, col + half, half);
        Node* bottomLeft = build(grid, row + half, col, half);
        Node* bottomRight = build(grid, row + half, col + half, half);

        return new Node(
            true,
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};

void printQuadTree(Node* root) {
    if (!root) return;

    cout << "[isLeaf=" << root->isLeaf
         << ", val=" << root->val << "] ";

    if (!root->isLeaf) {
        printQuadTree(root->topLeft);
        printQuadTree(root->topRight);
        printQuadTree(root->bottomLeft);
        printQuadTree(root->bottomRight);
    }
}

int main() {
    int n;

    cout << "Enter grid size (power of 2): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Enter grid values:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    Node* root = obj.construct(grid);

    cout << "\nQuad Tree (Preorder Traversal):\n";
    printQuadTree(root);

    return 0;
}