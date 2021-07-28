var table = map[byte]int {
	'I': 1,
	'V': 5,
	'X': 10,
	'L': 50,
	'C': 100,
	'D': 500,
	'M': 1000,
}

func romanToInt(s string) int {
	// Init lookahead value as first letter's value
	var curr, next, total int = 0, table[s[0]], 0
	
	for i := 1; i < len(s); i++ {
		// Lookahead of next letter
		curr, next = next, table[s[i]]
		
		if curr < next {
			// If current value is subtraction
			total -= curr
		} else {
			total += curr
		}
	}
	
	// Add the value of last letter, which can't be subtraction
	total += next
	
	return total
}
