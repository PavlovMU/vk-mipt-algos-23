#!/usr/bin/env python
# coding: utf-8


class Node:
    def __init__(self, data=None, nextt=None):
        self.data = data
        self.next = nextt
        
class LinkedList:
    def __init__(self, head=None): # переменная аргумент head - экземпляр класса Node
        self.head = head 
        
       

def IsCycle(l): # будет возвращено Bool значение 
    
    if (l.head is None) or (l.head.next is None): # можем так сделать из-за ленивого вычисления составных логических операций в питоне 
        return False
    
    slow = l.head
    fast = l.head.next
    
    while slow != fast:
        
        if (fast is None ) or (fast.next is None):
            return False
        
        slow = slow.next
        fast = fast.next.next
        
    return True



# n1 = Node(1)
# n2 = Node(2)
# n3 = Node(3)
# n4 = Node(4)
# n5 = Node(5)

# n1.next = n2
# n2.next = n3
# n3.next = n4
# n4.next = n5
# n5.next = n3 # делаем зацикливание вручную

# l = LinkedList(n1)

# print(IsCycle(l))

# l.display()




# In[ ]:




