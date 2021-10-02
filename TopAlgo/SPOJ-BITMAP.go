package main

import (
    "fmt"
)

type Queue []int

func (q *Queue) push(val int) {
    *q = append(*q, val)
}

func (q *Queue) pop() {
    *q = (*q)[1:]
}

func (q *Queue) peek() int {
    return (*q)[0]
}

func (q *Queue) size() int {
    return len(*q)
}

func main() {
    var n int
    var key int
    var value int
    
    ans := 0

    fmt.Scanf("%d", &key)
    fmt.Scanf("%d", &value)
    fmt.Scanf("%d", &n)

    list := make([]int, n)

    for i:=0; i<n; i++ {
        fmt.Scan(&list[i])
    }

    for i:=0; i<n; i++ {
        fmt.Printf("%d ", list[i])
    }

    fmt.Println(ans)
}
