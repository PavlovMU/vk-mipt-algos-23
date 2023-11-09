#include <iostream>

struct Node {
  Node* next;
  int value;

  Node(int value) : value(value), next(nullptr) {
  }
};

Node* DeleteNode(Node* head, int val) {
  if (head == nullptr) {
    return nullptr;
  }
  while (head != nullptr && head->value == val) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  Node* cur = head->next;
  Node* prev = head;
  while (cur != nullptr) {
    if (cur->value == val) {
      prev->next = cur->next;
      delete cur;
      cur = prev->next; //Если узлов со значением val несколько
    } else {
      prev = cur;
      cur = cur->next;
    }
  }
  return head;
}

void PrintList(Node* node) {
  while (node != nullptr) {
    std::cout << node->value << " ";
    node = node->next;
  }
  std::cout << std::endl;
}






