package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var cache map[int]int
var count int

func visit(root *TreeNode, total int, sum int) {
	if root == nil {
		return
	}

	total += root.Val

	// If path ending on this node exists, add the number of paths to counter
	if v, ok := cache[total-sum]; ok {
		count += v
	}

	cache[total] += 1

	visit(root.Left, total, sum)
	visit(root.Right, total, sum)

	// Decrement the cache, because following DFS will be on a different route
	cache[total] -= 1
}

func pathSum(root *TreeNode, sum int) int {
	// Reset global vars
	cache = make(map[int]int)
	count = 0

	// Init cache
	cache[0] = 1

	visit(root, 0, sum)

	return count
}
