#include <iostream>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};

        // Count frequency of s1
        for (int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int windowSize = s1.length();

        // Check every window in s2
        for (int i = 0; i < s2.length(); i++) {
            int freq2[26] = {0};

            int windIdx = 0, idx = i;

            while (windIdx < windowSize && idx < s2.length()) {
                freq2[s2[idx] - 'a']++;
                idx++;
                windIdx++;
            }

            if (isFreqSame(freq1, freq2)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if (obj.checkInclusion(s1, s2)) {
        cout << "True (Permutation exists)" << endl;
    } else {
        cout << "False (Permutation does not exist)" << endl;
    }

    return 0;
}