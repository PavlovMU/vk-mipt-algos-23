struct Node
{
    int     val ;
    Node*   next;
};

Node* ReverseList(Node* head)
{
    Node* cur  = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (cur != nullptr)
    {
        next        = cur->next;
        cur->next   = prev;
        prev        = cur;
        cur         = next;
    }

    return prev;
}

int main()
{

    return 1;
}
