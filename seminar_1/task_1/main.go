package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func DeleteElem(head *ListNode, elem int) *ListNode {
	dummy := &ListNode{
		Val:  -123123123,
		Next: head,
	}
	var curr = dummy
	for curr != nil && curr.Next != nil {
		if curr.Next.Val == elem {
			curr.Next = curr.Next.Next
		} else {
			curr = curr.Next
		}
	}
	return dummy.Next
}

func main() {
}
