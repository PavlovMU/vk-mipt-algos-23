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

  bool has_cycle(ll_node* node) {
    if (node == nullptr || node->next == nullptr) return false;

    ll_node* slow = node;
    ll_node* fast = node->next;

    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr) return false;

      slow = slow->next;
      fast = fast->next->next;
    }

    return true;
  }
};
}  // namespace ll_namespace

