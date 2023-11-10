class ListNode:
	def __init__(self, x):
        	self.val = x
        	self.next = None

def reverse_list(head: ListNode) -> ListNode:
	current = head
	prev = None
	next = None
	while current:
		next = current.next
		current.next = prev
		prev = current
		current = next

	return prev

