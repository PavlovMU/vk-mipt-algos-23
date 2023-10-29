package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func Reverse(head *ListNode) *ListNode {
	var prev *ListNode
	currNode := head

	for currNode != nil {
		nextNode := currNode.Next
		currNode.Next = prev
		prev = currNode
		currNode = nextNode
	}
	return prev
}

func main() {
	fmt.Println("work")
}
