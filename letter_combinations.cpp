#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> ans;

    void backtrack(string digits, int index, string current,
                   unordered_map<char, string>& mp) {

        // Base case
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Get letters for current digit
        string letters = mp[digits[index]];

        // Try each letter
        for (char ch : letters) {
            backtrack(digits, index + 1, current + ch, mp);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backtrack(digits, 0, "", mp);
        return ans;
    }
};

int main() {
    Solution obj;

    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = obj.letterCombinations(digits);

    cout << "Possible combinations are:\n";
    for (string s : result) {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}