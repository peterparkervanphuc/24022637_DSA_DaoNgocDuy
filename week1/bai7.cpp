#include <iostream>
#include <vector>
using namespace std;

long long matrixSum(const vector<vector<long long>> &matrix) {
    long long sum = 0;
    for (const vector<long long> &row : matrix)
        for (long long value : row) sum += value;
    return sum;
}

bool eraseRow(vector<vector<long long>> &matrix, int i) {
    if (i < 1 || i > static_cast<int>(matrix.size())) return false;
    matrix.erase(matrix.begin() + (i - 1));
    return true;
}

void printMatrix(const vector<vector<long long>> &matrix) {
    for (const vector<long long> &row : matrix) {
        for (int j = 0; j < static_cast<int>(row.size()); ++j) {
            if (j > 0) cout << ' ';
            cout << row[j];
        }
        cout << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n < 0 || m < 0) return 0;

    vector<vector<long long>> matrix(n, vector<long long>(m));
    for (vector<long long> &row : matrix)
        for (long long &value : row) cin >> value;

    cout << matrixSum(matrix) << '\n';

    int i;
    cin >> i;
    if (!eraseRow(matrix, i)) {
        cout << "Dong xoa khong hop le\n";
        return 0;
    }
    printMatrix(matrix);
    return 0;
}

// Sum: O(N*M), memory: O(N*M).
// Erasing row i shifts at most O(N) row objects; matrix element moves are O(1) because each row is stored separately.
