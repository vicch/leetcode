package main

// Return list of prime factors of the given number
func getPrimeFactors(n int) []int {

	// The string's length is < 10000, if it's a composite number, one of its factors must be
	// smaller than sqrt(10000) which is 100
	primes := [25]int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}
	var factors []int

	// Stop the loop if it reaches the last prime numbers in the list, or the number itself is
	// smaller than a prime number
	for i := 0; i < 25 && primes[i] <= n; i++ {
		if n%primes[i] == 0 {
			factors = append(factors, primes[i])
		}
	}

	return factors
}

// Check if the string can be divided as n identical substrings
func hasNRepeatedSubstring(s string, n int) bool {
	l := len(s)
	m := l / n

	// For each char in the first substring of length m
	for i := 0; i < m; i++ {
		// Check if it's equal to its corresponding char in the rest of the substrings of length
		// m
		for j := i + m; j < l; j += m {
			if s[i] != s[j] {
				// If any substring is not identical, return false
				return false
			}
		}
	}

	// All substrings are identical
	return true
}

func repeatedSubstringPattern(s string) bool {
	factors := getPrimeFactors(len(s))

	// For each prime factor n of the length, check if the string can be divided as n identical
	// substrings
	for _, f := range factors {
		if hasNRepeatedSubstring(s, f) {
			return true
		}
	}

	return false
}
