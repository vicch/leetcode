// Problem:
// Given a string and a string dictionary, find the longest string in the
// dictionary that can be formed by deleting some characters of the given
// string. If there are more than one possible results, return the longest word
// with the smallest lexicographical order. If there is no possible result,
// return the empty string.
// - All the strings in the input will only contain lower-case letters.
// - The size of the dictionary won't exceed 1,000.
// - The length of all the strings in the input won't exceed 1,000.
// 
// Example:
// Input: s = "abpcplea", d = ["ale","apple","monkey","plea"]
// Output: "apple"
// 
// Solution:
// Keep a character pointer for each dictionary word. Iterating the string, if
// the current character matches one dictionary word's pointed character,
// forward the pointer. Pick the longest dictionary word whose pointer reaches
// the end.

#include <stdio.h>
#include <string.h>

char* findLongestWord(char* s, char** d, int dSize);

int main()
{
    return 0;
}

/********** Solution **********/

char* findLongestWord(char* s, char** d, int dSize)
{
    if (!(*s) || dSize == 0)
        return "";

    int len[dSize], lenmax, i;
    char* result;

    memset(len, 0, sizeof(len));
    lenmax = 0;
    result = "";

    for (; *s != '\0'; s++)
        for (i = 0; i < dSize; i++)
            if (*d[i] == *s) {
                d[i]++;
                len[i]++;
            }

    for (i = 0; i < dSize; i++)
        if (*d[i] == '\0' && (*result == '\0' || len[i] > lenmax || (len[i] == lenmax && strcmp(result, d[i] - len[i]) > 0))) {
            lenmax = len[i];
            result = d[i] - len[i];
        }

    return result;
}
