package main

import "fmt"

type LinkedList struct {
	Head *ListNode
}
type ListNode struct {
	Value int
	Next  *ListNode
}

func reverseList(lst *ListNode) *ListNode {
	if lst == nil {
		return nil
	}

	var reverseLst *ListNode

	for lst != nil {
		tmp := lst.Next
		lst.Next = reverseLst
		reverseLst = lst
		lst = tmp
	}
	return reverseLst
}

func main() {
	Lst := make([]ListNode, 3)
	Lst[2] = ListNode{
		Value: 2,
		Next:  nil,
	}
	Lst[1] = ListNode{
		Value: 1,
		Next:  &Lst[2],
	}
	Lst[0] = ListNode{
		Value: 0,
		Next:  &Lst[1],
	}
	fmt.Println(Lst)
	reverseList(&Lst[0])
	fmt.Println(Lst)

}
