func queensAttacktheKing(queens [][]int, king []int) [][]int {
	var returnArray [][]int
	var queensMap [8][8]int

	// Mark the Queens in matrix
	for _, queen := range queens {
		queensMap[queen[0]][queen[1]] = 1
	}

	// Up left
	for i, j := king[0] - 1, king[1] - 1; i >= 0 && j >= 0; i, j = i - 1, j - 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Up
	for i, j := king[0] - 1, king[1]; i >= 0; i = i - 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Up right
	for i, j := king[0] - 1, king[1] + 1; i >= 0 && j < 8; i, j = i - 1, j + 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Right
	for i, j := king[0], king[1] + 1; j < 8; j = j + 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Down right
	for i, j := king[0] + 1, king[1] + 1; i < 8 && j < 8; i, j = i + 1, j + 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Down
	for i, j := king[0] + 1, king[1]; i < 8; i = i + 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Down left
	for i, j := king[0] + 1, king[1] - 1; i < 8 && j >= 0; i, j = i + 1, j - 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	// Left
	for i, j := king[0], king[1] - 1; j >= 0; j = j - 1 {
		if queensMap[i][j] > 0 {
			returnArray = append(returnArray, []int{i, j})
			break;
		}
	}

	return returnArray
}