#include <iostream>

struct Node {
    Node* next;
    int value;

    Node() {
        next = nullptr;
        value = 0;
    }
    Node(int value) {
        next = nullptr;
        this->value = value;
    }
};

void del_elem(Node*& head, int val) {
    //создаем доп ноду, чтобы не потерять head,
    //можно без него, но иногда дает преимущества
    //Node dummy = Node(0, head);
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    Node* pred = head;
    while (current->next != nullptr) {
      if (current->value == val) {
          pred->next = current->next;
          delete current;
          delete pred;
          return;
      }
      pred = current;
      current = current->next;
    }
}