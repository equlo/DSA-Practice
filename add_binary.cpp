#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;

    cout << "Enter first binary number: ";
    cin >> a;

    cout << "Enter second binary number: ";
    cin >> b;

    cout << "Sum = " << addBinary(a, b) << endl;

    return 0;
}