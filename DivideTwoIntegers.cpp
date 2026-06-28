#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int divide(int dividend, int divisor) {

    // Handle overflow case
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine the sign of the result
    bool negative = (dividend < 0) ^ (divisor < 0);

    // Convert to positive long long values
    long long dvd = llabs((long long)dividend);
    long long dvs = llabs((long long)divisor);

    long long quotient = 0;

    while (dvd >= dvs) {
        long long temp = dvs;
        long long multiple = 1;

        // Find the largest multiple of divisor
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }

        dvd -= temp;
        quotient += multiple;
    }

    // Apply sign
    if (negative)
        quotient = -quotient;

    return (int)quotient;
}

int main() {
    int dividend, divisor;

    cout << "Enter dividend: ";
    cin >> dividend;

    cout << "Enter divisor: ";
    cin >> divisor;

    int result = divide(dividend, divisor);

    cout << "Quotient = " << result << endl;

    return 0;
}