#include <iostream>

// реализован простой лист с функционалом для наших задач
// reverse(listok) развернуть лист
// если лист пуст или состоит из 1 элемента - ничего не делает

struct Node {
  int value;
  Node* next;

  Node(int _value, Node* _next = nullptr) : value(_value), next(_next) {}
};

struct List {
  Node* Head;
  Node* Tail;
  size_t size = 0;
};

bool is_empty(List listok) { return listok.Head == nullptr; }

void push_back(int value, List* listok) {
  if (listok->size == 0) {
    listok->Head = new Node(value);
    listok->Tail = listok->Head;
  } else {
    listok->Tail->next = new Node(value);
    listok->Tail = listok->Tail->next;
  }
  ++listok->size;
}

void pop_front(List listok) {
  if (listok.size > 0) {
    Node* t = listok.Head;
    listok.Head = listok.Head->next;
    delete t;
    --listok.size;
  }
}

void pop_back(List listok) {
  if (listok.size == 1) {
    delete listok.Head;
    listok.Head == nullptr;
    --listok.size;
  } else if (listok.size > 1) {
    Node* i = listok.Head;
    Node* t = listok.Head;
    while (i->next != listok.Tail) {
      ++i;
    }
    i->next = nullptr;
    delete t;
    --listok.size;
  }
}

void reverse(List* listok) {
  if (listok->Head == nullptr) {
    return;
  } else if (listok->Head->next == nullptr) {
    return;
  }
  Node* prev_current = listok->Head;
  Node* current = listok->Head->next;
  Node* next_current = current->next;
  prev_current->next = nullptr;
  while (next_current != nullptr) {
    current->next = prev_current;
    prev_current = current;
    current = next_current;
    next_current = next_current->next;
  }
  current->next = prev_current;
  listok->Tail = listok->Head;
  listok->Head = current;
}

int main() {
  // для введения тестов
  /*
  List listok;

  push_back(0, &listok);
  push_back(1, &listok);
  push_back(2, &listok);
  push_back(3, &listok);

  reverse(&listok);
  if (listok.Head != nullptr) {
    std::cout << "Head: " << listok.Head->value << "\n";
    std::cout << "Tail: " << listok.Tail->value << "\n";
  }
  */
  return 0;
}
