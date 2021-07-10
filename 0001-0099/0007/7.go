package main

import "math"

func reverse(x int) int {
	var y, rev int64 = int64(x), 0

	for y != 0 {
		rev = rev*10 + y%10

		// Check for overflow
		if rev > math.MaxInt32 || rev < math.MinInt32 {
			return 0
		}

		x /= 10
	}

	return int(rev)
}
