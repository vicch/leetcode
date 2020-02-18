func reverseInt(x int) int64 {
	var rev int64 = 0
	for cpy := int64(x); cpy > 0; cpy /= 10 {
		rev = rev * 10 + cpy % 10;
	}
	return rev
}

func isPalindrome(x int) bool {
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false
	} else if (x < 10) {
		return true
	}

	return x == int(reverseInt(x))
}
