#include <stdio.h>

int romanToInt(char* s);
int romanValue(char c);

int main()
{
	printf("%s:%d\n", "III", romanToInt("III"));
	printf("%s:%d\n", "V", romanToInt("V"));
	printf("%s:%d\n", "VII", romanToInt("VII"));
	printf("%s:%d\n", "IX", romanToInt("IX"));
	printf("%s:%d\n", "XVI", romanToInt("XVI"));
	printf("%s:%d\n", "XXIV", romanToInt("XXIV"));
	printf("%s:%d\n", "MDCCC", romanToInt("MDCCC"));

	return 0;
}

int romanValue(char c)
{
	// Assume there are only uppercase letters
	switch (c) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return 0;
	}
}

int romanToInt(char* s)
{
	int curr, next, total;

	curr = total = 0;
	// Init lookahead value
	next = romanValue(s[0]);
	
	for (int i = 1; s[i] != '\0'; i++) {
		curr = next;
		// Lookahead of next letter
		next = romanValue(s[i]);

		if (curr < next)
			// If current value is subtraction
			total -= curr;
		else
			total += curr;
	}
	
	// Add the value of last letter, which can't be subtraction
	total += next;

	return total;
}
