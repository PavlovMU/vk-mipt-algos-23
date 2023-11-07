class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class iscyrcle(object):
    def two_pointers(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fast = head
        while fast and fast.next:
            head = head.next
            fast = fast.next.next
            if head == fast:
                return True
             
        return False
