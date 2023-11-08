#!/usr/bin/env python
# coding: utf-8

# In[88]:


class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next
        
class LinkedList:
    def __init__(self, head=None):
        self.head = head        

    def remove_element(self, data):
        #dummy = Node(None, head )
        current = self.head
        prev = None
        
        while current is not None:
            if current.data == data:
                if prev is None:
                    self.head = current.next
                else:
                    prev.next = current.next
                return
            prev = current
            current = current.next


# In[ ]:





# In[ ]:




