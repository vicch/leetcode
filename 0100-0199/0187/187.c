// Problem:
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, T,
// for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
// identify repeated sequences within the DNA. Write a function to find all
// 10-letter-long sequences (substrings) that occur more than once in a DNA
// molecule.
// 
// Example:
// Input: "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC", "CCCCCAAAAA"]
// 
// Solution:
// Use 2 bits to represent each letter, and a 10-letter-long sequence becomes
// a 20-bit integer, use this integer as index to count the occurrences.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** findRepeatedDnaSequences(char* s, int* returnSize);

int main()
{
    return 0;
}

char** findRepeatedDnaSequences(char* s, int* returnSize)
{
    *returnSize = 0;

    if (!s)
        return NULL;
    
    int letterToInt[256], intToLetter[4];
    int i, seq;

    letterToInt['A'] = 0;
    letterToInt['C'] = 1;
    letterToInt['G'] = 2;
    letterToInt['T'] = 3;

    intToLetter[0] = 'A';
    intToLetter[1] = 'C';
    intToLetter[2] = 'G';
    intToLetter[3] = 'T';

    // Get first 10 letters
    for (i = seq = 0; i < 10 && s[i] != '\0'; i++)
        seq = (seq + letterToInt[s[i]]) << 2;

    // Counter the excessive shift at the end
    seq >>= 2;

    // Less than 10 letters
    if (i < 10)
        return NULL;

    int count[1048576]; // 2^20
    char** repeated = malloc(sizeof(char*) * 1000); // Assume max 1000

    // Init as 0
    memset(count, 0, sizeof(count));

    count[seq] = 1;

    for (; s[i] != '\0'; i++) {
        // Keep last 16 bits, left shift and add current letter
        seq = ((seq & 262143) << 2) + letterToInt[s[i]];

        // Repeated sequence
        if (count[seq] == 1) {
            repeated[*returnSize] = malloc(sizeof(char) * 11);
            strncpy(repeated[*returnSize], s + i - 9, 10);
            repeated[(*returnSize)++][10] = '\0';
        }

        count[seq] += 1;
    }

    return repeated;
}