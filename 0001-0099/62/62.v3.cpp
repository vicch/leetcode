#include <algorithm>

using namespace std;

class Solution {
private:
	// Calculate the number of combinations to arrange b items among a items
	int combination(int a, int b) {

		// C(a, b) == C(a, a - b), with a smaller number b, it saves processing time
		b = min(b, a - b);
		
		// Use a larger type for the temp result, because it may overflow the range of int
		long c = 1;

		// C(a, b) = (a-0) x (a-1) x (a-2) x ... x (a-(b-1)) / 1 / 2 / ... / b
		//         = (a-0) / 1 x (a-1) / 2 x ... x (a-(b-1)) / b
		// To keep the temp result as small as possible, intersect the calculations into pairs
		// of multiplication and division.
		for (int i = 0; i < b; i++) {
			c *= a - i;

			// We can be sure that the division result will always be clean, because there must
			// be a number between a and a-i that could be divided by i+1.
			c /= i + 1;
		}
		
		return c;
	}
public:
	int uniquePaths(int m, int n) {
		return combination(m + n - 2, m - 1);
	}
};
