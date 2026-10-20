#include <iostream>
#include <list>
using namespace std;

class StackLinkedList {
private:
    struct Node {
        int value;
        Node *next;
        Node(int value, Node *next) : value(value), next(next) {}
    };
    Node *topNode = nullptr;

public:
    ~StackLinkedList() {
        while (topNode != nullptr) {
            Node *old = topNode;
            topNode = topNode->next;
            delete old;
        }
    }

    void push(int value) {
        topNode = new Node(value, topNode);
    }

    bool pop(int &value) {
        if (topNode == nullptr) return false;
        value = topNode->value;
        Node *old = topNode;
        topNode = topNode->next;
        delete old;
        return true;
    }
};

class StackList {
private:
    list<int> data;

public:
    void push(int value) {
        data.push_back(value);
    }

    bool pop(int &value) {
        if (data.empty()) return false;
        value = data.back();
        data.pop_back();
        return true;
    }
};

void printPopped(StackLinkedList &stack) {
    int value;
    while (stack.pop(value)) cout << value << ' ';
    cout << '\n';
}

void printPopped(StackList &stack) {
    int value;
    while (stack.pop(value)) cout << value << ' ';
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    StackLinkedList linkedStack;
    StackList listStack;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        linkedStack.push(value);
        listStack.push(value);
    }

    printPopped(linkedStack);
    printPopped(listStack);
    return 0;
}

// push/pop for both implementations: O(1); memory: O(N).
