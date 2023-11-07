class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class reversell(object):
    def reverseList(self, head):
        new_list = None
        current = head
    
        while current:
            next_node = current.next
            current.next = new_list
            new_list = current
            current = next_node
        return new_list

