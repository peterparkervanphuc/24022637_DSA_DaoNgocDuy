#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value, Node *next = nullptr) : value(value), next(next) {}
};

class SinglyLinkedList {
private:
    Node *head = nullptr;

public:
    ~SinglyLinkedList() {
        clear();
    }

    void addBack(int value) {
        Node *node = new Node(value);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node *current = head;
        while (current->next != nullptr) current = current->next;
        current->next = node;
    }

    void insert(int position, int value) {
        if (position < 1) return;
        if (position == 1) {
            head = new Node(value, head);
            return;
        }
        Node *current = head;
        for (int i = 1; current != nullptr && i < position - 1; ++i)
            current = current->next;
        if (current != nullptr)
            current->next = new Node(value, current->next);
    }

    bool remove(int position) {
        if (position < 1 || head == nullptr) return false;
        if (position == 1) {
            Node *old = head;
            head = head->next;
            delete old;
            return true;
        }
        Node *current = head;
        for (int i = 1; current->next != nullptr && i < position - 1; ++i)
            current = current->next;
        if (current->next == nullptr) return false;
        Node *old = current->next;
        current->next = old->next;
        delete old;
        return true;
    }

    void print() const {
        for (Node *current = head; current != nullptr; current = current->next) {
            if (current != head) cout << ' ';
            cout << current->value;
        }
        cout << '\n';
    }

    void clear() {
        while (head != nullptr) {
            Node *old = head;
            head = head->next;
            delete old;
        }
    }
};

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    SinglyLinkedList list;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.addBack(value);
    }
    list.print();

    int insertPosition, insertValue, removePosition;
    cin >> insertPosition >> insertValue >> removePosition;
    list.insert(insertPosition, insertValue);
    list.print();
    cout << (list.remove(removePosition) ? "Da xoa\n" : "Vi tri xoa khong hop le\n");
    list.print();
    return 0;
}

// addBack/insert/remove/print: O(N) in the worst case; insert/remove at head: O(1).
// Memory: O(N).
