#include <stdio.h>
#include <string.h>

int isPalindrome(char* s);
int transform(char* new, char* old, int len);

int main()
{
    char str1[] = "A man, a plan, a canal: Panama";
    printf("%d\n", isPalindrome(str1));

    char str2[] = "race a car";
    printf("%d\n", isPalindrome(str2));

    char str3[] = "0P";
    printf("%d\n", isPalindrome(str3));

    return 0;
}

int isPalindrome(char* s)
{
    int lo = strlen(s);
    char new[lo];
    int ln = transform(new, s, lo);

    int i;
    for (i = 0; i < ln / 2; i++) {
        if (new[i] != new[ln - i - 1])
            return 0;
    }

    return 1;
}

/* Strip non-alphabetic chars, lowercase all alphabetic chars */
int transform(char* new, char* old, int len)
{
    int i = 0;
    while (len-- > 0) {
        if (*old >= 'A' && *old <= 'Z')
            new[i++] = *old - 'A' + 'a';
        else if ((*old >= 'a' && *old <= 'z') || (*old >= '0' && *old <= '9'))
            new[i++] = *old;
        else
            ;
        old++;
    }
    new[i] = '\0';

    return i;
}