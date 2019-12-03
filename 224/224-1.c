// Problem:
// Implement a basic calculator to evaluate a simple expression string. The
// expression string may contain open ( and closing parentheses ), the plus +
// or minus sign -, non-negative integers and empty spaces. Assume that the
// given expression is always valid.
// 
// Example:
// "(1+(4+5+2)-3)+(6+8)" = 23
// 
// Solution:
// Expand the expression by evaluating all numbers and add up later. Numbers are
// evaluated as positive or negative depending on a "sign" which negates when
// minus operator is encountered. For example, 1 - (2 - (3 - 4)), numbers added
// to the list are: 1, -2, 3, -4.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate(char* s);
char* clean(char* s);
char* calculateSub(char* s, int sign);
char* addNumber(char* s, int sign);
char* getNumber(char* s, int* num);

int main()
{
    // printf("%d\n", calculate(" 2-1 + 2 "));
    // printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)"));
    // printf("%d\n", calculate("10"));
    // printf("%d\n", calculate("11 + (12 - 13) + 14"));
    // printf("%d\n", calculate("1-(5)"));
    // printf("%d\n", calculate("3-(5+1)"));
    // printf("%d\n", calculate("2-(5-6)"));
    printf("%d\n", calculate("1 - (2 - (3 - 4)) - (5 - 6)"));
    // printf("%d\n", calculate("1 + (3 - (4 + 10 - (2 + 0) - (3 + 4) - (4 - 5))) - (2 - 3)"));

    return 0;
}

int nums[100000];
int count = 0;

int calculate(char* s)
{
    int res = 0;

    // Eliminate spaces
    s = clean(s);

    s = calculateSub(s, 1);

    // Add numbers up
    while (count > 0)
        res += nums[--count];

    return res;
}

char* calculateSub(char* s, int sign)
{
    if (*s == '(')
        s = calculateSub(++s, sign);

    while (*s != '\0' && *s != ')') {
        if (*s == '+') {
            s++;
            if (*s == '(')
                s = calculateSub(++s, sign);
            else
                s = addNumber(s, sign);
        } else if (*s == '-') {
            s++;
            if (*s == '(')
                s = calculateSub(++s, -sign);
            else
                s = addNumber(s, -sign);
        } else
            s = addNumber(s, sign);
    }

    if (*s == ')')
        s++;

    return s;
}

char* clean(char* s)
{
    char* new = malloc(sizeof(char) * (strlen(s) + 1));
    char* cur = new;

    for (; *s != '\0'; s++)
        if (*s != ' ')
            *(cur++) = *s;
    *cur = '\0';

    return new;
}

char* addNumber(char* s, int sign)
{
    int num;

    s = getNumber(s, &num);
    nums[count++] = num * sign;

    return s;
}

char* getNumber(char* s, int* num)
{
    if (*s == '\0')
        return s;

    *num = 0;

    while (*s >= '0' && *s <= '9') {
        *num = *num * 10 + (*s - '0');
        s++;
    }

    return s;
}