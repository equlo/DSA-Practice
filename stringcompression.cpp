#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    int i = 0, index = 0;

    while (i < chars.size()) {
        char current = chars[i];
        int count = 0;

        while (i < chars.size() && chars[i] == current) {
            i++;
            count++;
        }

        chars[index++] = current;

        if (count > 1) {
            string cnt = to_string(count);
            for (char c : cnt) {
                chars[index++] = c;
            }
        }
    }

    return index;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    vector<char> chars(input.begin(), input.end());

    int newLength = compress(chars);

    cout << "Compressed output: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }

    cout << "\nLength: " << newLength << endl;

    return 0;
}