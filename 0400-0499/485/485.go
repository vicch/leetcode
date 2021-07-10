package main

// I can't believe there is neither max() nor ternary operator in Go
func maxInt(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

func findMaxConsecutiveOnes(nums []int) int {
	max, cur := 0, 0
	for _, n := range nums {
		if n == 1 {
			// Consecutive 1, increment counter
			cur += 1
		} else {
			// Consecutive 1 broken
			max = maxInt(cur, max)
			cur = 0
		}
	}
	return maxInt(cur, max)
}
