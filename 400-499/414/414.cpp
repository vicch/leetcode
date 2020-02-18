#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int a = INT_MIN, b = INT_MIN, c = INT_MIN;
		
		for (auto n : nums) {
			// This will break if n == INT_MAX
			if (n + 1 > a)
				c = b, b = a, a = n + 1;
			else if (n + 1 < a && n + 1 > b)
				c = b, b = n + 1;
			else if (n + 1 < b && n + 1 > c)
				c = n + 1;
		}
		
		return c == INT_MIN ? a - 1 : c - 1;
	}
};