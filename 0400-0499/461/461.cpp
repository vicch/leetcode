class Solution {
private:
	// Count the number of digit 1 in the given number
	int countOnes(int n) {
		int c;
		// Right shift n while checking if the right-most digit is 1
		for (c = 0; n != 0; c += n & 1, n >>= 1);
		return c;
	}
public:
	int hammingDistance(int x, int y) {
		// Hamming distance equals to the number of digit 1 in (x XOR y)
		return countOnes(x ^ y);
	}
};