#include <iostream>

struct Node {
  Node* next;
  int value;
  Node(int value) : value(value), next(nullptr) {
  }
};

Node* Reverse(Node* head) {
  Node* prev = nullptr;
  Node* next = nullptr;
  Node* cur = head;
  while (cur != nullptr)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;  
}