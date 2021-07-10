// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
private:
	int guessNumberSub(int min, int max) {
		// The value of "min + max" maybe out of range, use this to find the middle value
		int middle = min + (max - min) / 2;

		int answer = guess(middle);

		if (answer == 0)
			return middle;
		else if (answer == -1)
			return guessNumberSub(min, middle - 1);
		else
			return guessNumberSub(middle + 1, max);
	}
public:
	int guessNumber(int n) {
		return guessNumberSub(1, n);
	}
};