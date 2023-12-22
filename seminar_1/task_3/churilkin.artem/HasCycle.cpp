// есть ли закольцованнось в односвязном списке

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node * head)
{
    if(head == nullptr or head->next == nullptr) return false;
    Node* slow_ptr = head;
    Node* fast_ptr = head->next;

    while (slow_ptr != fast_ptr)
    {
        if (slow_ptr == nullptr or fast_ptr == nullptr) return false;
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return true;
}