package main

import "math"

func arrangeCoins(n int) int {
	// See readme for explanation
	x := int(math.Floor(math.Sqrt(float64(n) * 2)))
	if x*(x+1)/2 > n {
		x = x - 1
	}
	return x
}
