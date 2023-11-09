#include <iostream>

class LinkedList {
    public:

    class ListNode {
        public:
        ListNode *next;
        int data;
    };
    ListNode* head;
    ListNode* tail;

    bool hasCycle(ListNode *head) {

        if (head == nullptr || head->next == nullptr) return false;

        ListNode *slow = head; 
        ListNode *fast = head->next;


        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
        
    }
};

int main() {

}