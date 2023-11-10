#include <iostream>

struct Node {
	int val;
	struct Node *next;
	
	Node(int val) : val(val), next(nullptr) {}	
}

void delete_node(struct Node* head, int val) {
	Node* dummy = new Node(0);
	Node* curr = head;
	Node* prev = dummy;
	while(curr->next) {
		if (curr->val == val) {
			curr->next = curr->next->next;
		} else {
			prev = curr;
		}
		curr = curr->next;
	}
	head = dummy->next;
}

