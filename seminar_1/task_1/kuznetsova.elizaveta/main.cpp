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


    // ListNode *Node(int val, ListNode *next) {
    //     ListNode* NewNode = (ListNode *)calloc(1, sizeof(ListNode));
    //     NewNode->data = val;
    //     NewNode->next = next;
    //     return NewNode;
    // };
    
    // ListNode *Search(ListNode *head, int val) {
    //     ListNode *node = head;

    //     while (node != nullptr && node->data != val) {
    //         node = node->next;
    //     }

    //     return node;
    // }

    ListNode *Erase(ListNode *head, int val) {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *SearchNode = head;

        while (SearchNode != nullptr) {
            if (SearchNode->data == val) break;
            prev = SearchNode;
            SearchNode = SearchNode->next;
        }

        if (prev == nullptr) {
            return head->next;
        } else {
            prev->next = SearchNode->next;
            SearchNode->next = nullptr;
            return temp;
        }
    };

};






int main() {
    
}