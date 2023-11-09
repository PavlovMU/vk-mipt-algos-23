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

  ll_node* reverse_list(ll_node* node) {
    ll_node* prev = nullptr;
    ll_node* next = nullptr;
    ll_node* curr = node;

    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};
}  // namespace ll_namespace

