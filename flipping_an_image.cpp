#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;

            while (left <= right) {
                // Swap and invert simultaneously
                int temp = image[i][left] ^ 1;   // invert left element
                image[i][left] = image[i][right] ^ 1; // invert right element
                image[i][right] = temp;

                left++;
                right--;
            }
        }

        return image;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> result = obj.flipAndInvertImage(image);

    // Output matrix
    for (auto &row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}