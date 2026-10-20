#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *previous;
    Node *next;
    Node(int value) : value(value), previous(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    ~DoublyLinkedList() {
        clear();
    }

    void addBack(int value) {
        Node *node = new Node(value);
        node->previous = tail;
        if (tail != nullptr) tail->next = node;
        else head = node;
        tail = node;
    }

    void insert(int position, int value) {
        if (position < 1) return;
        if (position == 1) {
            Node *node = new Node(value);
            node->next = head;
            if (head != nullptr) head->previous = node;
            else tail = node;
            head = node;
            return;
        }

        Node *current = head;
        for (int i = 1; current != nullptr && i < position; ++i)
            current = current->next;
        if (current == nullptr) {
            if (position == size() + 1) addBack(value);
            return;
        }

        Node *node = new Node(value);
        node->previous = current->previous;
        node->next = current;
        current->previous->next = node;
        current->previous = node;
    }

    bool remove(int position) {
        Node *current = nodeAt(position);
        if (current == nullptr) return false;
        if (current->previous != nullptr) current->previous->next = current->next;
        else head = current->next;
        if (current->next != nullptr) current->next->previous = current->previous;
        else tail = current->previous;
        delete current;
        return true;
    }

    int size() const {
        int count = 0;
        for (Node *current = head; current != nullptr; current = current->next) ++count;
        return count;
    }

    void printForward() const {
        for (Node *current = head; current != nullptr; current = current->next) {
            if (current != head) cout << ' ';
            cout << current->value;
        }
        cout << '\n';
    }

    void printBackward() const {
        for (Node *current = tail; current != nullptr; current = current->previous) {
            if (current != tail) cout << ' ';
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
        tail = nullptr;
    }

private:
    Node *nodeAt(int position) const {
        if (position < 1 || position > size()) return nullptr;
        if (position <= size() / 2) {
            Node *current = head;
            for (int i = 1; i < position; ++i) current = current->next;
            return current;
        }
        Node *current = tail;
        for (int i = size(); i > position; --i) current = current->previous;
        return current;
    }
};

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    DoublyLinkedList list;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        list.addBack(value);
    }
    list.printForward();
    list.printBackward();

    int insertPosition, insertValue, removePosition;
    cin >> insertPosition >> insertValue >> removePosition;
    list.insert(insertPosition, insertValue);
    list.printForward();
    cout << (list.remove(removePosition) ? "Da xoa\n" : "Vi tri xoa khong hop le\n");
    list.printForward();
    return 0;
}

// Access by position: O(N), but can start from the nearer end; addBack: O(1).
// Insert/remove after locating a node: O(1); memory: O(N).
