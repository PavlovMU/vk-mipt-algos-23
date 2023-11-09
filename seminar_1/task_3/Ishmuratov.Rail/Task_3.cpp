#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast ->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main()
{
    ListNode d{4};
    ListNode c{3, &d};
    ListNode b{2, &c};
    ListNode a{1, &b}; // Это head
    if(hasCycle(&a)){
        cout<<"Has Cycle"<<"\n";
    }
    else{
        cout<<"Does not have Cycle"<<"\n";
    }
}
