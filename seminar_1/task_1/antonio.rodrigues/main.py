from typing import Union


class Node:
    def __init__(self, data, next) -> None:
        self.data = data,
        self.next = next


def Remove(head: Node, val: int):
    dummy = head
    prev = head
    head = head.next

    while head is not None:
        if head.data == val:
            prev.next = head.next
            head = head.next
            continue
        else:
            prev = head
            head = head.next

    if dummy.data == val:
        dummy = dummy.next

    return dummy
