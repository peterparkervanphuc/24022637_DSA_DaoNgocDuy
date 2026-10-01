#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    if (n < 0 || n > 20) {
        cout << "Khong tinh duoc trong pham vi unsigned long long\n";
        return 0;
    }

    unsigned long long factorial = 1;
    for (long long i = 2; i <= n; ++i) factorial *= static_cast<unsigned long long>(i);

    cout << factorial << '\n';
    return 0;
}

// Time: O(N), memory: O(1).