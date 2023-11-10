#include <iostream>

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data), next(nullptr) {}
}

void delete_node(Node* head, int data) {
  Node* tmp = new Node(0);
  Node* current = head;
  Node* previous = tmp;
  while (current->next) {
    if(current->data == data) {
      current->next = current->next->next;
    } else {
      previous = current;
    }
    current = current->next;
  }
  head = tmp->next;
}

