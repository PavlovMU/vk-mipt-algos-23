

def reverse(head):
    prev = None
    next = None
    current = head

    while current is not None:
        next = current.next
        current.next = prev
        prev = current
        current = next

    return prev
