package main

import "fmt"

func moveEvenNumbersToFront(arr []int) {
	evenIndex := 0

	for i := 0; i < len(arr); i++ {
		if arr[i]%2 == 0 {
			arr[i], arr[evenIndex] = arr[evenIndex], arr[i]
			evenIndex++
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
    
    moveEvenNumbersToFront(arr)
    for i, num := range arr {
		if i > 0 {
			fmt.Print(" ") 
		}
		fmt.Print(num)
	}
	fmt.Println()
}

