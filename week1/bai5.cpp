#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 0) return 0;

    vector<double> a(n);
    double sum = 0.0;
    for (double &x : a) {
        cin >> x;
        sum += x;
    }

    double average = sum / n;
    cout << fixed << setprecision(6) << average << '\n';
    for (int i = 0; i < n; ++i) {
        if (a[i] >= average) {
            cout << a[i] << '\n';
        }
    }
    return 0;
}

// Time: O(N), memory: O(N).