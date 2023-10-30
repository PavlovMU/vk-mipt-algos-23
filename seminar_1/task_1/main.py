class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

def remove_element(head: ListNode, value: int) -> ListNode:
	dummy = ListNode(0, head)
	current = head
	while current:
		if current.val == value:
			dummy.next = current.next
		current = current.next
		dummy = dummy.next 

	return head

