#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes) {
	int i, j;
	int queensMap[8][8];

	// Init return value as 8 pairs of int
	int** returnArray = malloc(sizeof(int*) * 8);
	for (i = 0; i < 8; i++) {
		returnArray[i] = malloc(sizeof(int) * 2);
	}

	*returnSize = 0;
	*returnColumnSizes = malloc(sizeof(int) * 8);

	// Init the matrix as 0s
	memset(queensMap, 0, sizeof(queensMap));

	// Mark the Queens in matrix
	for (i = 0; i < queensSize; i++) {
		queensMap[queens[i][0]][queens[i][1]] = 1;
	}

	// Up left
	for (i = king[0] - 1, j = king[1] - 1; i >= 0 && j >= 0; i--, j--) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Up
	for (i = king[0] - 1, j = king[1]; i >= 0; i--) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Up right
	for (i = king[0] - 1, j = king[1] + 1; i >= 0 && j < 8; i--, j++) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Right
	for (i = king[0], j = king[1] + 1; j < 8; j++) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Down right
	for (i = king[0] + 1, j = king[1] + 1; i < 8 && j < 8; i++, j++) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Down
	for (i = king[0] + 1, j = king[1]; i < 8; i++) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Down left
	for (i = king[0] + 1, j = king[1] - 1; i < 8 && j >= 0; i++, j--) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	// Left
	for (i = king[0], j = king[1] - 1; j >= 0; j--) {
		if (queensMap[i][j]) {
			returnArray[*returnSize][0] = i;
			returnArray[*returnSize][1] = j;
			(*returnColumnSizes)[*returnSize] = 2;
			(*returnSize)++;
			break;
		}
	}

	return returnArray;
}