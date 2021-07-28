#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// Init the global and local max sums
		int maxAll = nums[0], maxCur = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			// Calculate the max sum of all subarrays ending on this element
			maxCur = max(maxCur + nums[i], nums[i]);

			// Update the global sum if necessary
			maxAll = max(maxCur, maxAll);
		}

		return maxAll;
	}
};
