namespace ll_namespace {

class linked_list {
  class ll_node {
   public:
    ll_node* next;
    int data;
  };

 private:
  ll_node* head;
  ll_node* tail;  // probably don't really need it now?

 public:
  linked_list() { head = tail = nullptr; }

  ll_node* delete_node(ll_node* node, int data) {
    ll_node dummy{node, 0};
    ll_node* curr = node;
    ll_node* prev = &dummy;

    while (curr != nullptr) {
      if (curr->data == data) {
        prev->next = curr->next;
        delete curr;
      } else
        prev = curr;

      curr = curr->next;
    }

    return dummy.next;
  }
};
}  // namespace ll_namespace

