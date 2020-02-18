#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2);

int main()
{
    printf("%s\n", multiply("11", "11"));
    printf("%s\n", multiply("9369162965141127216164882458728854782080715827760307787224298083754", "7204554941577564438"));
    printf("%s\n", multiply("1292903509936727404199686220192411623085", "9996190433341303536650999221082973702747291324607482481306424831201698419742124862320482024"));

    return 0;
}

char* multiply(char* num1, char* num2)
{
    if (*num1 == '0' || *num2 == '0') return "0";

    int l1 = strlen(num1), l2 = strlen(num2), rl = l1 + l2;
    int *rd = (int*)malloc(sizeof(int) * rl);
    memset(rd, 0, sizeof(int) * rl);

    int i, j;
    for (i = l1 - 1; i >= 0; i--)
        for (j = l2 - 1; j >= 0; j--)
            rd[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');

    for (i = rl - 1; i > 0; i--) {
        rd[i - 1] += rd[i] / 10;
        rd[i] %= 10;
    }

    char* rs = (char*)malloc(sizeof(char) * (rl + 1));
    for (i = 0; rd[i] == 0; i++);
    for (j = 0; i < rl; i++, j++)
        rs[j] = rd[i] + '0';
    rs[j] = '\0';

    return rs;
}