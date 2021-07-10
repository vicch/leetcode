// Problem:
// A character in UTF8 can be from 1 to 4 bytes long, subjected to the
// following rules:
// 1. For 1-byte character, the first bit is a 0, followed by its unicode code.
// 2. For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
//    followed by n-1 bytes with most significant 2 bits being 10.
//    
// Char. number range  |        UTF-8 octet sequence
//    (hexadecimal)    |              (binary)
// --------------------+------------------------------------
// 0000 0000-0000 007F | 0xxxxxxx
// 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
// 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
// 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// 
// Given an array of integers representing the data, return whether it is a
// valid utf-8 encoding. Only the least significant 8 bits of each integer is
// used to store the data.
// 
// Example:
// Input: [197, 130, 1] (11000101 10000010 00000001)
// Output: true
// 
// Solution:
// Simply iterate the array and check each integer.

#include <stdio.h>

typedef int bool;

bool validUtf8(int* data, int dataSize);

int main()
{
    int d1[] = {197, 130, 1};
    printf("%d\n", validUtf8(d1, 3));

    int d2[] = {235, 140, 4};
    printf("%d\n", validUtf8(d2, 3));

    int d3[] = {237};
    printf("%d\n", validUtf8(d3, 1));

    return 0;
}

bool validUtf8(int* data, int dataSize)
{
    int i, l;

    for (i = l = 0; i < dataSize; i++, l--) {
        if (l == 0)
            if (data[i] < 128)
                l = 1;
            else if (data[i] < 192)
                return 0;
            else if (data[i] < 224)
                l = 2;
            else if (data[i] < 240)
                l = 3;
            else if (data[i] < 248)
                l = 4;
            else
                return 0;
        else if (data[i] < 128 || data[i] > 191)
            return 0;
    }

    return l == 0;
}