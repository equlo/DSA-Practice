#include <iostream>
#include <string>
#include <climits>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();

    // Skip leading spaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Check sign
    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    // Convert digits
    long long num = 0;

    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');

        // Check overflow
        if (sign * num > INT_MAX)
            return INT_MAX;
        if (sign * num < INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign * num;
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Converted Integer: " << myAtoi(s) << endl;

    return 0;
}