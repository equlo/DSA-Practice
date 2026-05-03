#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        if (!ans.empty() && ans.back() == s[i]) {
            ans.pop_back();  // remove duplicate
        } else {
            ans.push_back(s[i]);  // add character
        }
    }

    cout << ans << endl;

    return 0;
}