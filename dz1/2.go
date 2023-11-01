package main

import "fmt"

func moveZerosToEnd(arr []int) {
	zeroIndex := 0 

	for i := 0; i < len(arr); i++ {
		if arr[i] != 0 {
			arr[i], arr[zeroIndex] = arr[zeroIndex], arr[i]
			zeroIndex++
		}
	}
}

func main() {
    var n int
    fmt.Scan(&n)
    
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&arr[i])
    }
    
    moveZerosToEnd(arr)
    for i, num := range arr {
		if i > 0 {
			fmt.Print(" ") 
		}
		fmt.Print(num)
	}
	fmt.Println()
}

