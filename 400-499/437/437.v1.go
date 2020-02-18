package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSumContinuous(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	path := 0

	// Path ending on current node
	if root.Val == sum {
		path += 1
	}

	// Paths starting from a previous node and ending on any node in left child tree
	path += pathSumContinuous(root.Left, sum-root.Val)

	// Paths starting from a previous node and ending on any node in right child tree
	path += pathSumContinuous(root.Right, sum-root.Val)

	return path
}

func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	path := 0

	// Paths starting from current node
	path += pathSumContinuous(root, sum)

	// Paths starting from any node in left child tree
	path += pathSum(root.Left, sum)

	// Paths starting from any node in right child tree
	path += pathSum(root.Right, sum)

	return path
}
