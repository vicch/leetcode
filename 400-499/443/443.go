package main

import "strconv"

func compress(chars []byte) int {
	var i, j, k int

	// Moves the fast pointer, note it goes beyond the end of the array so the last part can be
	// processed correctly
	for i, j, k = 0, 0, 0; i <= len(chars); i++ {

		// Skip logic below and keep moving the fast pointer if the char is repeating
		if i < len(chars) && chars[i] == chars[j] {
			continue
		}

		// Write the char part of the compressed array, the char is always written, even if it's
		// not being compressed (which should be a single char without following number in the
		// compressed array)
		chars[k] = chars[j]
		k += 1

		// Write the number part of the compressed array, skip it if the char only shows up
		// once
		if i-j > 1 {
			for _, c := range strconv.Itoa(i - j) {
				chars[k] = byte(c)
				k += 1
			}
		}

		// Make the slow pointer catch up with the fast pointer
		j = i
	}

	// Current writing position marks the length of the compressed array
	return k
}
