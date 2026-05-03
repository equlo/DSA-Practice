#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to reverse words in a string
string reverseWords(string s) {
    int n = s.length();     // length of string
    string ans = "";        // final answer

    // Step 1: Reverse entire string
    reverse(s.begin(), s.end());
    // Example: "the sky" -> "yks eht"

    // Step 2: Traverse string to extract words
    for (int i = 0; i < n; i++) {

        string word = "";   // to store each word

        // Step 2.1: Skip spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2.2: Form word (until next space)
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        // Step 2.3: Reverse the extracted word
        reverse(word.begin(), word.end());

        // Step 2.4: Add word to answer
        if (word.length() > 0) {
            // Add space only if ans is not empty
            if (ans.length() > 0) {
                ans += " ";
            }
            ans += word;
        }
    }

    return ans;  // final reversed string
}

int main() {
    string s;

    cout << "Enter string: ";
    getline(cin, s);   // take full input including spaces

    cout << "Output: " << reverseWords(s);

    return 0;
}