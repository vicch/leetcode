#include <stdio.h>
#include <limits.h>

int reverse(int x);

int main()
{
	printf("%d,%d\n", 123, reverse(123));
	printf("%d,%d\n", 1, reverse(1));
	printf("%d,%d\n", 100, reverse(100));
	printf("%d,%d\n", -123, reverse(-123));
	printf("%d,%d\n", 1534236469, reverse(1534236469));

	return 0;
}

int reverse(int x)
{
	long rev = 0;

	while (x != 0) {
		rev = rev * 10 + x % 10;

		// Check for overflow
		if (rev > INT_MAX || rev < INT_MIN)
			return 0;

		x /= 10;
	}

	return (int)rev;
}
