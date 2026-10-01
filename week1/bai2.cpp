#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sortAscending(vector<long long> &a) {
    sort(a.begin(), a.end());
}

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    sortAscending(a);
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}

// Time: O(N log N), memory: O(log N) auxiliary.
