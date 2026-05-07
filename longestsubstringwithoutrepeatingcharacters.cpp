#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            // If duplicate character exists
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            // Store latest index
            mp[s[right]] = right;

            // Update maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution obj;

    string s;

    cout << "Enter the string: ";
    cin >> s;

    int ans = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: " 
         << ans << endl;

    return 0;
}