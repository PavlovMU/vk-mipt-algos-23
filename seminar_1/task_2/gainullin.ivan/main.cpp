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
    LinkedList() : head(nullptr), size(0) {}
    LinkedList(Node* head_, size_t size_) : head(head_), size(size_) {}

    Node* head;
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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur(new Node(head));
    Node* next = nullptr;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main() {
    std::vector<Node> a(5);
    for (size_t i = 0; i < a.size()-1; i++) {
        a[i].data = i;
        a[i].next = &a[i+1];
    }
    a[a.size()-1].data = a.size()-1;

    LinkedList list(&a[0], a.size());
    std::cout << "List before reversing: " << list;

    list.head = reverseList(list.head);
    std::cout << "List after reversing: " << list;
}