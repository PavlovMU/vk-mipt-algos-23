struct Node
{
    int     val ;
    Node*   next;
};

Node* RemovEl(Node* head, int val)
{
    Node dummy = {0, head};
    Node* current = head;
    Node* prev = head;

    while (current != nullptr)
    {
        if (current->val == val)
        {
            prev->next = current->next;
            delete current;
        }

        else
            prev = current;

        current = current->next;
    }

    return dummy.next;
}

int main()
{

    return 1;
}
