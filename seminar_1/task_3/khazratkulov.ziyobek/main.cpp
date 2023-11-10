#include <iostream>

struct Node {
  int data;
  Node* next;

  Node(int data) : data(data), next(nullptr) {}
}

bool has_cycle(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return false;
  }
  Node* slow = head;
  Node* fast = head->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) {
      return false;
    }
    slow = slow->next;
    fast = fast->next->next;
 }
 return true;
}
