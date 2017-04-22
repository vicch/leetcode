// Problem:
// Given a string S, which represents a software license key which we would
// like to format. The string S is composed of alphanumerical characters and
// dashes. The dashes split the alphanumerical characters within the string
// into groups. (i.e. if there are M dashes, the string is split into M+1
// groups). The dashes in the given string are possibly misplaced. We want each
// group of characters to be of length K (except for possibly the first group,
// which could be shorter, but still must contain at least one character). To
// satisfy this requirement, we will reinsert dashes. Additionally, all the
// lower case letters in the string must be converted to upper case. Given a
// non-empty string S, representing a license key to format, and an integer K.
// And return the license key formatted according to the description above.
// 
// Example:
// Input: S = "2-4A0r7-4k", K = 3
// Output: "24-A0R-74K"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* licenseKeyFormatting(char* S, int K);

int main()
{
    printf("%s\n", licenseKeyFormatting("2-4A0r7-4k", 4));
    printf("%s\n", licenseKeyFormatting("---", 3));

    return 0;
}

/********** Solution **********/

#define UPPER(a) ((97 <= (a) && (a) <= 122) ? (a) - 32 : (a))

int keyLength(char* s);

char* licenseKeyFormatting(char* S, int K)
{
    int len, rem, c, i, j;
    char* key;

    // Length without dashes
    len = keyLength(S);
    
    // Length of first group
    rem = len % K;
    if (rem == 0) rem = K;
    
    // Length with dashes
    len += (len + K - 1) / K - 1;
    if (len < 0) len = 0;

    key = malloc(sizeof(char) * (len + 1));

    for (i = j = 0, c = K + 1 - rem; i < len;)
        // Add dashes
        if (c == K + 1)
            key[i++] = '-', c = 1;
        else {
            // Ignore dashes in original string
            if (S[j] != '-')
                key[i++] = UPPER(S[j]), c++;
            j++;
        }

    key[len] = '\0';

    return key;
}

int keyLength(char* s)
{
    int l;

    for (l = 0; *s != '\0'; s++)
        if (*s != '-')
            l++;

    return l;
}