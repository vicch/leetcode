func numberOfBoomerangs(points [][]int) int {
	var total int = 0
	
	for _, i := range points {
		// Cache of counts of distances
		var cache map[int]int = map[int]int {}
		
		// For each point i, iterate all other points
		for _, j := range points {

			// Calculate distance
			x := i[0] - j[0]
			y := i[1] - j[1]
			dist := x * x + y * y
			
			if _, ok := cache[dist]; ok {
				// Assuming the current count of this distance is n, then:
				// - number of boomerangs before current increment = n * (n - 1)
				// - number of boomerangs after current increment  = (n + 1) * n
				// The diff is n * 2, so we just need to add n * 2 to get the new number of
				// boomerangs from the old number
				total += cache[dist] * 2

				// Increment count of this distance
				cache[dist] += 1
			} else {

				// Init count of this distance to 1
				cache[dist] = 1
			}
		}
	}
	
	return total
}
