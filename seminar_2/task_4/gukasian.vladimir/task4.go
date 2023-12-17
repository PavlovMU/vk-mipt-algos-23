package main 

import "fmt"

func copyTime(n , x, y int) int {
    mid := 0
    left   := 0
    right  := (n-1) * max(x, y)
    
    for ; left + 1 < right ; {
        mid = (left + right) / 2

        if (mid / x + mid / y) < n - 1 {
            left = mid
        } else {
            right = mid
        }
    }
    
    return right + min(x, y)
}

func main() {
    fmt.Println(copyTime(5, 1, 2))
}
