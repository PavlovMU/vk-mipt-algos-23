package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func cicleLinkedList(head *ListNode) bool {
	var (
		slow = head
		fast = head
	)
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println("task_3")
}
