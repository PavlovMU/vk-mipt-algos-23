package main

import "fmt"

func returnIdx(nums []int, elem int) []int {
	if len(nums) <= 1 {
		return []int{}
	}
	var (
		first_ptr  = 0
		second_ptr = len(nums) - 1
	)
	for first_ptr < second_ptr {
		curr := nums[first_ptr] + nums[second_ptr]
		if curr == elem {
			return []int{first_ptr, second_ptr}
		} else if curr > elem {
			second_ptr--
		} else {
			first_ptr++
		}
	}

	return []int{}
}

func main() {
	fmt.Println("task_4")
}
