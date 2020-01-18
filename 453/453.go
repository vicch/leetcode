package main

import "math"

func minMoves(nums []int) int {
	var min int = math.MaxInt64
	var sum int = 0

	for _, n := range nums {
		sum += n
		if min > n {
			min = n
		}
	}

	return sum - min*len(nums)
}
