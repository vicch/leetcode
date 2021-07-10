class Solution {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		
		// Values of the last 2 items, they will calculate the next item and be updated
		// accordingly for the next iteration
		int a = 1, b = 1;
		
		for (; n > 1; n--) {
			b = a + b; // next b = current a + current b
			a = b - a; // next a = current a + current b - current a = current b
		}
		
		return b;
	}
};
