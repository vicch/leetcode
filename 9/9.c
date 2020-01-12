#include <stdio.h>

int isPalindrome(int x);

int main()
{
	printf("%d:%d\n", 1, isPalindrome(1));
	printf("%d:%d\n", 12321, isPalindrome(12321));
	printf("%d:%d\n", 123321, isPalindrome(12321));
	printf("%ld:%d\n", 2222222222, isPalindrome(2222222222));
	printf("%d:%d\n", -2147447412, isPalindrome(-2147447412));

	return 0;
}

int isPalindrome(int x)
{
	if (x < 0 || (x % 10 == 0 && x != 0))
		// All negative ints are not palindrome
		return 0;
	else if (x < 10)
		// All single digit positive ints are palindrome
		return 1;
	
	// Reverse digits of an int, it may overflow as int, so use a long
	long rev = 0;
	for (int cpy = x; cpy > 0; cpy /= 10)
		rev = rev * 10 + cpy % 10;
	
	return x == rev;
}
