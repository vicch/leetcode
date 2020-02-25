#include <vector>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		// Init local min/max and global max
		int maxAll = nums[0], maxCur = nums[0], minCur = nums[0];

		// Start from second number
		for (int i = 1; i < nums.size(); i++) {
			// Keep copies of local min/max
			int maxTmp = maxCur, minTmp = minCur;

			// Update local min/max
			maxCur = max(max(maxTmp * nums[i], minTmp * nums[i]), nums[i]);
			minCur = min(min(maxTmp * nums[i], minTmp * nums[i]), nums[i]);

			// Update global max if necessary
			maxAll = max(maxCur, maxAll);
		}

		return maxAll;
	}
};