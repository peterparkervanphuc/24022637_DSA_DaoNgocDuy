#include <iostream>
#include <list>
using namespace std;

class QueueLinkedList {
private:
    struct Node {
        int value;
        Node *next;
        Node(int value) : value(value), next(nullptr) {}
    };
    Node *frontNode = nullptr;
    Node *backNode = nullptr;

public:
    ~QueueLinkedList() {
        int ignored;
        while (dequeue(ignored)) {}
    }

    void enqueue(int value) {
        Node *node = new Node(value);
        if (backNode != nullptr) backNode->next = node;
        else frontNode = node;
        backNode = node;
    }

    bool dequeue(int &value) {
        if (frontNode == nullptr) return false;
        value = frontNode->value;
        Node *old = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) backNode = nullptr;
        delete old;
        return true;
    }
};

class QueueList {
private:
    list<int> data;

public:
    void enqueue(int value) {
        data.push_back(value);
    }

    bool dequeue(int &value) {
        if (data.empty()) return false;
        value = data.front();
        data.pop_front();
        return true;
    }
};

void printDequeued(QueueLinkedList &queue) {
    int value;
    while (queue.dequeue(value)) cout << value << ' ';
    cout << '\n';
}

void printDequeued(QueueList &queue) {
    int value;
    while (queue.dequeue(value)) cout << value << ' ';
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;

    QueueLinkedList linkedQueue;
    QueueList listQueue;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        linkedQueue.enqueue(value);
        listQueue.enqueue(value);
    }

    printDequeued(linkedQueue);
    printDequeued(listQueue);
    return 0;
}

// enqueue/dequeue for both implementations: O(1); memory: O(N).
