# вторая задачка

class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None
        
class Stack(object):
    def __init__(self):
        self.top = None
    
    def push(self, data):
        new_Node = Node(data)
        
        if self.top is None:
            self.top = new_Node
            return
        
        new_Node.next = self.top
        self.top = new_Node

        
    def pop(self):
        if not self.top:
            return None
        
        top = self.top
        if self.top.next is not None:
            self.top = self.top.next
        else:
            self.top = None
            
        return top.data    
    #def show_stack(self):
        

def isPalindrome(s):
    st = Stack()
    
    for char in s:
        st.push(char)
    
    for char in s:
        
        if char != st.pop():
            return False
    
    return True

a = 'SHALAHS'

print(isPalindrome(a))


