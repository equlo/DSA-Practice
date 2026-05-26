#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Function to count elements <= mid
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        int count = 0;

        while (row >= 0 && col < n) {

            if (matrix[row][col] <= mid) {
                
                // All elements above current row are <= mid
                count += (row + 1);
                col++;
            }
            else {
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {

            int mid = low + (high - low) / 2;

            int cnt = countLessEqual(matrix, mid);

            if (cnt < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    cout << "Kth Smallest Element = "
         << obj.kthSmallest(matrix, k);

    return 0;
}