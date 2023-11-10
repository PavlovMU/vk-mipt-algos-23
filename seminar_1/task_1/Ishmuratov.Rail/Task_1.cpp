#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr) {
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while(curr!=nullptr){
        if(curr->val==val){
            prev->next = curr->next;
            curr = curr->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
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
    ListNode* result = removeElements(&a, 2);
    while (result != nullptr) {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<"\n";
}
