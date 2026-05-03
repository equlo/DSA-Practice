#include <iostream>
#include <string>
using namespace std;

char getMaxOccuringChar(string s) {
    int freq[26] = {0};   // for 'a' to 'z'

    // Step 1: Count frequency
    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find max frequency character
    int maxFreq = -1;
    char ans = 'a';

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            ans = i + 'a';
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << getMaxOccuringChar(s);

    return 0;
}