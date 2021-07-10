using namespace std;

class Solution {
private:
	// Reverse digits of an int, it may overflow as int, so return as long
	long reverseInt(int x) {
		long rev = 0;
		for (int cpy = x; cpy > 0; cpy /= 10)
			rev = rev * 10 + cpy % 10;
		return rev;
	}
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0))
			// All negative ints are not palindrome
			return false;
		else if (x < 10)
			// All single digit positive ints are palindrome
			return true;

		return x == reverseInt(x);
	}
};
