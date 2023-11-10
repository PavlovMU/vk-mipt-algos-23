class ListNode:
	def __init__(self, x):
	       	self.val = x
          	self.next = None

def has_cycle(head: ListNode) -> bool:
        fast = slow = head
        while fast:
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
            else:
                return False

            if fast == slow:
                return True
        return False

