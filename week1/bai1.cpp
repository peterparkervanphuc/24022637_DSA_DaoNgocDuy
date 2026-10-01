#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    vector<long long> a(n);
    long long sum = 0;
    for (long long &x : a) {
        cin >> x;
        sum += x;
    }

    cout << sum << '\n';
    return 0;
}

// Time: O(N), memory: O(N).
