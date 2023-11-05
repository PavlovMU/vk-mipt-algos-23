#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void remove_node_from_list(List* lst, int id) {
    lst->cur_ptr = lst->head;
    if (lst->head->id == id) {
        Node* tmp = lst->head->next;
        free(lst->head);
        lst->head = tmp;
        return;
    }

    while (lst->cur_ptr->next->id != id) {
        lst->cur_ptr = lst->cur_ptr->next;
        continue;
    }
    Node* tmp = lst->cur_ptr->next->next;
    free(lst->cur_ptr->next);
    lst->cur_ptr->next = tmp;
    return;
}

List* dummy_list(unsigned N) {
    assert(N > 0);
    Node* head = (Node*) calloc(1, sizeof(Node));
    head->id = 0;

    List* lst;
    lst->head = head;
    lst->cur_ptr = head;

    for (size_t i = 0; i < N-1; i++) {
        Node* node = (Node*) calloc(1,  sizeof(Node));
        node->id = i+1;
        lst->cur_ptr->next = node;
        lst->cur_ptr = node;
    }
    lst->cur_ptr->next = NULL;
    return lst;
}

void free_node(Node* node) {
    if (node->next != NULL) {
        free_node(node->next);
    }
    free(node);
}

void free_list(List* lst) {
    lst->cur_ptr = lst->head;
    free_node(lst->cur_ptr);
}

int main() {
    List* lst = dummy_list(12);
    print_list(lst);
    remove_node_from_list(lst, 0);
    print_list(lst);
    free_list(lst);
    return 0;
}