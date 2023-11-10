struct Node {
      int val;
      Node *next;
      Node() : val(0), next(nullptr) {}
      Node(int x) : val(x), next(nullptr) {}
 };

bool hasCycle(Node* head) {
	Node* slow = head;
	Node* fast = head->next;
	while(slow && slow->next) {
		if (slow == fast) {
			return true;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}
