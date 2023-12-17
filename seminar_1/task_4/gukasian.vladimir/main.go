package main 

import "fmt"

func findTwoSum(nums []int, target int)  {
    i := 0
    j := len(nums) - 1
    
    cur_sum := 0
    for i != j {
      cur_sum = nums[i] + nums[j]

        if cur_sum == target {
            break
        } else if cur_sum < target {
            i++
        } else {
            j--
        }
    }
    
    if (i != j) {
        fmt.Println(target, "is a sum of the", i, "and", j, "elements")
    } else {
        fmt.Println("Can not find elements which sum is", target)
    }
}

func main() {
    nums   := []int{2, 7, 11, 15}
    target   := 9
  
    fmt.Println("Array:", nums)
    fmt.Println("Target:", target)
    
    findTwoSum(nums, target)
    findTwoSum(nums, 8)
  
}
