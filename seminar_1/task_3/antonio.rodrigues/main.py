

def has_cycle(head) -> bool:
    if head is None or head.next is None:
        return False

    slow = head
    fast = head.next

    while slow != fast:
        if fast is None or fast.next is None:
            return False

        fast = fast.next.next
        slow = slow.next

    return True
