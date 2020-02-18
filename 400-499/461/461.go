func hammingDistance(x int, y int) int {
	// Hamming distance equals to the number of digit 1 in (x XOR y)
	return countOnes(x ^ y)
}

// Count the number of digit 1 in the given number
func countOnes(n int) int {
	c := 0
	// Right shift n while checking if the right-most digit is 1
	for ; n != 0; c, n = c + n & 1, n >> 1 {}
	return c
}