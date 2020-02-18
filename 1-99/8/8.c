#include <stdio.h>

int myAtoi(char* str);

int main()
{
    printf("%s:%d\n", " 123", myAtoi(" 123"));
    printf("%s:%d\n", "abc-123", myAtoi("abc-123"));
    printf("%s:%d\n", "-123,456", myAtoi("-123,456"));
    printf("%s:%d\n", "+000001", myAtoi("+000001"));
    printf("%s:%d\n", "-abc123", myAtoi("-abc123"));
    printf("%s:%d\n", "+-2", myAtoi("+-2"));
    printf("%s:%d\n", "9223372036854775809", myAtoi("9223372036854775809"));

    return 0;
}

int myAtoi(char* str)
{
    char c;
    int  i, state, sign;
    long double res;
    enum states {IDLE, EXPECT_NUM, READING_NUM, IGNORE_NUM};

    state = IDLE;
    res = 0;
    sign = 1;

    for (i = 0; (c = str[i]) != '\0'; i++) {
        if (state == IDLE) {
            if (c == ' ') {
                continue;
            } else if (c >= '0' && c <= '9') {
                state = READING_NUM;
                res = res * 10 + (c - '0');
            } else if (c == '-') {
                state = EXPECT_NUM;
                sign = -1;
            } else if (c == '+') {
                state = EXPECT_NUM;
                sign = 1;
            } else {
                break;
            }

        } else if (state == EXPECT_NUM) {
            if (c >= '0' && c <= '9') {
                state = READING_NUM;
                res = res * 10 + (c - '0');
            } else {
                break;
            }

        } else if (state == READING_NUM) {
            if (c >= '0' && c <= '9') {
                res = res * 10 + (c - '0');
            } else if (c == ',') {
                continue;
            } else {
                break;
            }

        } else if (state == IGNORE_NUM) {
            if ((c >= '0' && c <= '9' || c == '-' || c == '+')) {
                continue;
            } else {
                state = IDLE;
                res = 0;
                sign = 1;
            }
        }
    }

    res *= sign;

    if (res > 2147483647) {
        res = 2147483647;
    } else if (res < -2147483648) {
        res = -2147483648;
    }

    return res;
}
