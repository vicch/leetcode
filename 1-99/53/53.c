#include <stdio.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int maxSubArray(int* nums, int numsSize) {
	int i, max, cur;
	
	// Init the global and local max sums
	max = cur = nums[0];

	for (i = 1; i < numsSize; i++) {
		// Calculate the max sum of all subarrays ending on this element
		cur = MAX(cur + nums[i], nums[i]);

		// Update the global sum if necessary
		max = MAX(cur, max);
	}

	return max;
}
