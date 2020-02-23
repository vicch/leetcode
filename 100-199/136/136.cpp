#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto n : nums) {
			ret ^= n;
		}
		return ret;
	}
};
