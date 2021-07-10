#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int lmax = 0, lcur = 0;
		for (int n : nums) {
			if (n) {
				// Consecutive 1, increment counter
				lcur += 1;
			} else {
				// Consecutive 1 broken
				lmax = max(lcur, lmax);
				lcur = 0;
			}
		}
		return max(lcur, lmax);
	}
};
