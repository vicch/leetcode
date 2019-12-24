func twoSum(nums []int, target int) []int {
	numsMap := make(map[int]int)
	for idx, val := range nums {
		// Look for corresponding number
		if (numsMap[target - val] > 0) {
			return []int {numsMap[target - val] - 1, idx}
		}
		// Not found, push this number into the map
		numsMap[val] = idx + 1
	}
	return []int {-1, -1}
}