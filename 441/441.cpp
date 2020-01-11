#include <cmath>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		// See readme for explanation
		// 2n may overflow as int, convert it to long
		long x = sqrt(long(n) * 2);
		return (x * (x + 1) / 2 <= n) ? x : x - 1;
	}
};
