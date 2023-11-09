#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

int main()
{
    ListNode d{4};
    ListNode c{3, &d};
    ListNode b{2, &c};
    ListNode a{1, &b}; // Это head
    ListNode* head = &a;
    while (head != nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
    ListNode* result = reverseList(&a);
    while (result != nullptr) {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<"\n";
}
