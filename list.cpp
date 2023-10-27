#include <stdio.h>


struct node_t {
  int data     = 0;
  node_t* next = {};
};

struct list_t {
  node_t* head;
  size_t cap;
  size_t size;
};

node_t*  nodeCtor   (int     val=0, node_t* next=NULL);
void     reverseList(node_t* head);
node_t*  deleteNodes(list_t* list, int val);


void reverseList(node_t* head) {
    node_t* cur  = head;
    node_t* prev = NULL;

    while (cur){
        node_t* next = cur->next;
        cur->next    = prev;
        prev         = cur;
        cur          = next;
  }
}

node_t* deleteNodes(list_t* list, int val) {
  node_t* dummy = nodeCtor(0, list->head);
  node_t* prev  = dummy;
  node_t* cur   = list->head;

  while (cur) {
      if (cur->data == val) {
        prev->next = cur->next;
    }
    
    prev = cur;
    cur  = cur->next;
  }
  
  list->head = dummy->next;

  return dummy->next;
}
