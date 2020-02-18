// Problem:
// Given a group of two strings, you need to find the longest uncommon
// subsequence of this group of two strings. The longest uncommon subsequence
// is defined as the longest subsequence of one of these strings and this
// subsequence should not be any subsequence of the other strings. A
// subsequence is a sequence that can be derived from one sequence by deleting
// some characters without changing the order of the remaining elements.
// 
// Example:
// Input: "aba", "cdc"
// Output: 3
// 
// Solution:
// If length of a and b are not equal, then the longer one is not subsequence
// of the shorter one. If a and b are of equal length, unless a completely
// equals b, then either a or b is not subsequence of the other.

#include <stdio.h>
#include <string.h>

int findLUSlength(char* a, char* b);

int main()
{
    return 0;
}

/********** Solution **********/

int findLUSlength(char* a, char* b)
{
    int la = strlen(a);
    int lb = strlen(b);

    printf("la = %d, lb = %d\n", la, lb);

    if (la != lb)
        return (la > lb ? la : lb);

    if (strcmp(a, b) == 0)
        return 0;

    return la;
}