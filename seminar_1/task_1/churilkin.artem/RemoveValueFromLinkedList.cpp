// удаление элемента из односвязного списка по значению
#include <iostream>


// не работает !!!! не понял учет dummy
struct Node {
    int data;
    Node* next;
};

Node* removeValue(Node * head, int value){
    Node* dummy;
    dummy->next = head;

    Node * prev = dummy;
    Node * curr = head;
    Node * next = nullptr;
    while (curr != nullptr)
    {
        if (head->data == value) {
            Node* newHead = head->next;
            delete head;
            dummy->next = newHead;
            return newHead->next;
        }

        if(curr->data == value)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }    
        else
        {
            prev = curr;
            curr = curr->next;
        }

        return dummy->next;    
    }
    


}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 2;
    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->next = new Node();
    head->next->next->next->data = 2;
    head->next->next->next->next = nullptr;

    std::cout << "Original List: ";
    printList(head);

    head = removeValue(head, 2);

    std::cout << "\nList after removing 2: ";
    printList(head);


    return 0;
}