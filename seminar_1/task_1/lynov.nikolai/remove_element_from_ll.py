class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        dummy_head = ListNode("cat")
        print (dummy_head)
        dummy_head.next = head
        
        current = dummy_head
        while current.next != None:
            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next
                
        return dummy_head.next
