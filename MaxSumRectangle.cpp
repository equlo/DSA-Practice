// 363. Max Sum of Rectangle No Larger Than K
// Optimized Solution using Prefix Sum + Set
// Time Complexity: O(min(m,n)^2 * max(m,n) * log(max(m,n)))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = INT_MIN;

        // Fix left column
        for (int left = 0; left < cols; left++) {

            vector<int> rowSum(rows, 0);

            // Expand right column
            for (int right = left; right < cols; right++) {

                // Build row sums
                for (int r = 0; r < rows; r++) {
                    rowSum[r] += matrix[r][right];
                }

                // Find max subarray sum <= k
                set<int> prefixSet;
                prefixSet.insert(0);

                int prefixSum = 0;

                for (int sum : rowSum) {
                    prefixSum += sum;

                    // Need smallest prefix >= prefixSum - k
                    auto it = prefixSet.lower_bound(prefixSum - k);

                    if (it != prefixSet.end()) {
                        ans = max(ans, prefixSum - *it);
                    }

                    prefixSet.insert(prefixSum);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };

    int k = 2;

    cout << obj.maxSumSubmatrix(matrix, k);

    return 0;
}