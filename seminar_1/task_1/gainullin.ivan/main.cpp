#include <iostream>
#include <vector>

struct Node {
    Node() : data(0), next(nullptr) {}
    Node(int data_) : data(data_), next(nullptr) {}
    Node(int data_, Node* next_) : data(data_), next(next_) {}
    Node(const Node* node) : data(node->data), next(node->next) {}

    int data;
    Node* next;
};

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.data;
    return os;
}

struct LinkedList {
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    LinkedList(Node* head_, Node* tail_, size_t size_) : head(head_), tail(tail_), size(size_) {}

    Node* head;
    Node* tail;
    size_t size;
};

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* tmp(new Node(list.head->data, list.head->next));
    while (tmp->next != nullptr) {
        os << tmp->data << ' ';
        tmp = tmp->next;
    }
    os << tmp->data;
    os << std::endl;
    return os;
}

void removeElements(Node* head, int val) {
    Node* dummy(new Node(0, head));
    Node* prev(dummy);
    Node* cur(head);
    while (cur != nullptr) {
        if (cur->data == val) {
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
}

int main() {
    std::vector<Node> a(5);
    for (size_t i = 0; i < a.size()-1; i++) {
        a[i].data = i;
        a[i].next = &a[i+1];
    }
    a[a.size()-1].data = a.size()-1;

    LinkedList list(&a[0], &a[a.size()-1], a.size());
    std::cout << "List before removing element: " << list;

    removeElements(list.head, 4);
    std::cout << "List after removing element: " << list;
}