#include <iostream>
#include <vector>
using namespace std;

bool eraseAt(vector<long long> &a, int k) {
    if (k < 1 || k > static_cast<int>(a.size())) return false;
    a.erase(a.begin() + (k - 1));
    return true;
}

bool insertAt(vector<long long> &a, long long y, int m) {
    if (m < 1 || m > static_cast<int>(a.size()) + 1) return false;
    a.insert(a.begin() + (m - 1), y);
    return true;
}

void printArray(const vector<long long> &a) {
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    int k;
    cin >> k;
    if (!eraseAt(a, k)) {
        cout << "Vi tri xoa khong hop le\n";
        return 0;
    }
    printArray(a);

    long long y;
    int m;
    cin >> y >> m;
    if (!insertAt(a, y, m)) {
        cout << "Vi tri chen khong hop le\n";
        return 0;
    }
    printArray(a);
    return 0;
}

// Each erase/insert is O(N) in the worst case because elements may be shifted.
// Memory: O(N).
