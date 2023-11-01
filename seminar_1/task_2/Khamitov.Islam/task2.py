#!/usr/bin/env python
# coding: utf-8


class Node:
    def __init__(self, data=None, nextt=None):
        self.data = data
        self.next = nextt
        
class LinkedList:
    def __init__(self, head=None): # переменная аргумент head - экземпляр класса Node
        self.head = head 
        
#     def insert(self, data):
#         new_node = Node(data)
        
#         if self.head is None:
#             self.head = new_node
#         else:
#             current = self.head
#             while current.next is not None:
#                 current = current.next
#             current.next = new_node   
    
#     def display(self):
#         current = self.head
#         while current is not None:
#             print(current.data, end=" ")
#             current = current.next
#         print()        

def ReverseList(l):
    prev = Node() # тот, что в финальном списке получится cледующим 
    sled = Node() # тот ,что в перевернутом списке является предыдущим , т.е. следующий в данном списке   
    current = l.head 
    
    while current != None:
        sled = current.next 
        current.next = prev
        prev = current 
        current = sled
        
    l.head = prev
    return l.head

# linked_list = LinkedList()
# linked_list.insert(1)
# linked_list.insert(2)
# linked_list.insert(3)
# linked_list.insert(4)
# linked_list.insert(5)

# print(linked_list.head.data)

# ReverseList(linked_list)

# print(linked_list.head.data)







