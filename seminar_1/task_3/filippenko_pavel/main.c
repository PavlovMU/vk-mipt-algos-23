#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct _Node
{
    int id;
    struct _Node* next;
} Node;


typedef struct _List 
{
    Node* head;
    Node* cur_ptr;
} List;

void print_list(List* lst) {
    lst->cur_ptr = lst->head;
    while(lst->cur_ptr->next != NULL) {
        printf("%d -> ", lst->cur_ptr->id);
        lst->cur_ptr = lst->cur_ptr->next;
    }
    printf("%d\n", lst->cur_ptr->id);
}

bool is_list_cycled(List* lst) {
    lst->cur_ptr = lst->head;

    Node* fast = lst->head;
    Node* slow = lst->head->next;

    while (fast != slow && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next == NULL)
        return false;
    else
        return true;
}

int main() {
    Node lst1_node1;
    Node lst1_node2;
    Node lst1_node3;

    lst1_node1.id = 1;
    lst1_node1.next = &lst1_node2;
    lst1_node2.id = 2;
    lst1_node2.next = &lst1_node3;
    lst1_node3.id = 3;
    lst1_node3.next = &lst1_node1;

    Node lst2_node3 = {3, NULL};
    Node lst2_node2 = {2, &lst2_node3};
    Node lst2_node1 = {1, &lst2_node2};

    List lts_cycled = {&lst1_node1, NULL};
    List lts_non_cycled = {&lst2_node1, NULL};

    printf("List 1 is cycled? %s\n", is_list_cycled(&lts_cycled) ? "true" : "false");
    printf("List 2 is cycled? %s\n", is_list_cycled(&lts_non_cycled) ? "true" : "false");
    return 0;
}