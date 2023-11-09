#include <iostream>
//ask in interview

class LinkedList {
    public:

    class ListNode {
        public:
        ListNode *next;
        int data;
    };
    ListNode* head;
    ListNode* tail;

    ListNode *ReverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        ListNode *current = head;

        while (current != nullptr) {
            next = current->next;
            current->next = prev; 
            prev = current;
            current = next;
        }

        return prev;
    };

};

int main() {

}

