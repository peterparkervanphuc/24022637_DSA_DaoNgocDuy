#include <cstdlib>
#include <iostream>
#include <numeric>
using namespace std;

void reduceFraction(long long a, long long b, long long &numerator, long long &denominator) {
    numerator = a;
    denominator = b;
    if (denominator == 0) return;

    long long divisor = gcd(llabs(numerator), llabs(denominator));
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int main() {
    long long a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << "Mau so khong hop le\n";
        return 0;
    }

    long long numerator, denominator;
    reduceFraction(a, b, numerator, denominator);
    cout << numerator << '/' << denominator << '\n';
    return 0;
}

// Time: O(log min(|a|, |b|)) for gcd, memory: O(1).
