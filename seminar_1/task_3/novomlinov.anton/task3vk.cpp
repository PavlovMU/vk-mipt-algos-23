#include <iostream>

struct Node {
  Node* next;
  int value;
  Node(int value) : value(value), next(nullptr) {
  }
};

bool HasCycle(Node* head) {
  if (head == nullptr)
    return false;

  Node* slow = head;
  Node* fast = head->next;

  while (fast != nullptr && fast->next != nullptr) {
    if (slow == fast) {
      return true;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}