#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class List {
private:
    vector<int> data;

public:
    void add(int value) {
        data.push_back(value);
    }

    void insert(int position, int value) {
        if (position < 1 || position > static_cast<int>(data.size()) + 1)
            throw out_of_range("Vi tri chen khong hop le");
        data.insert(data.begin() + position - 1, value);
    }

    void remove(int position) {
        if (position < 1 || position > static_cast<int>(data.size()))
            throw out_of_range("Vi tri xoa khong hop le");
        data.erase(data.begin() + position - 1);
    }

    int find(int value) const {
        for (int i = 0; i < static_cast<int>(data.size()); ++i)
            if (data[i] == value) return i + 1;
        return -1;
    }

    void print() const {
        for (int i = 0; i < static_cast<int>(data.size()); ++i) {
            if (i > 0) cout << ' ';
            cout << data[i];
        }
        cout << '\n';
    }
};

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    List list;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.add(value);
    }
    list.print();

    int insertPosition, insertValue, removePosition, findValue;
    cin >> insertPosition >> insertValue >> removePosition >> findValue;
    try {
        list.insert(insertPosition, insertValue);
        list.print();
        list.remove(removePosition);
        list.print();
        cout << list.find(findValue) << '\n';
    } catch (const out_of_range &error) {
        cout << error.what() << '\n';
    }
    return 0;
}

// add/find: O(1) amortized/O(N); insert/remove: O(N); print: O(N).
// Memory: O(N).
