#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;

        // Overflow check
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;
        }

        rev = rev * 10 + digit;
        x /= 10;
    }

    return rev;
}

int main() {
    int x;

    // Input
    cin >> x;

    // Function call and output
    cout << reverseInteger(x);

    return 0;
}