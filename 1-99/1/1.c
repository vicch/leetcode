int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	int* ret;
	
	ret = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	
	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				ret[0] = i;
				ret[1] = j;
				return ret;
			}
		}
	}
	
	return (0);
}