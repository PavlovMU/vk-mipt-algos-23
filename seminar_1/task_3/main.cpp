struct Node
{
    int     val ;
    Node*   next;
};

bool IsListLooped(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    Node* slow = head;
    Node* fast = head->next;

    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main()
{

    return 1;
}
