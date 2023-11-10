#include <iostream>

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data), next(nullptr) {}
}

void reverse_list(Node* head) {
  Node* tmp = nullptr;
  Node* current = head;
  while (current) {
    Node* next = current->next;
    current->next = tmp;
    tmp = current
    current = next
  }
  head = tmp;
  return head;
}

