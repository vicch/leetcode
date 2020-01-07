func twoSum(nums []int, target int) []int {
	cache := make(map[int]int)

	for i, val := range nums {
		// Look for corresponding number
		if j, ok := cache[target - val]; ok {
			return []int {j, i}
		}

		// Not found, push this number into the map
		cache[val] = i
	}

	return []int {-1, -1}
}