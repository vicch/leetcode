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
    long rev = 0;
    int sign = 1;
    int copy = x;

    if (x < 0) {
        rev = 0;

    } else if (x < 10) {
        rev = x;

    } else {
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
    }

    rev *= sign;
    
    return (rev == copy);
}