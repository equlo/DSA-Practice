#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, string current, vector<string>& ans) {
        // Base Case
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            backtrack(open + 1, close, n, current + "(", ans);
        }

        // Add ')'
        if (close < open) {
            backtrack(open, close + 1, n, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, n, "", ans);
        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<string> result = obj.generateParenthesis(n);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}