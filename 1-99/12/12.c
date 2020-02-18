#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num);

int main()
{
    printf("%s\n", intToRoman(1));

    return 0;
}

char* intToRoman(int num)
{
    char* r = malloc(sizeof(char) * 50);

    switch (num / 1000) {
        case 1: strcat(r, "M"); break;
        case 2: strcat(r, "MM"); break;
        case 3: strcat(r, "MMM"); break;
        default: break;
    }

    switch ((num % 1000) / 100) {
        case 1: strcat(r, "C"); break;
        case 2: strcat(r, "CC"); break;
        case 3: strcat(r, "CCC"); break;
        case 4: strcat(r, "CD"); break;
        case 5: strcat(r, "D"); break;
        case 6: strcat(r, "DC"); break;
        case 7: strcat(r, "DCC"); break;
        case 8: strcat(r, "DCCC"); break;
        case 9: strcat(r, "CM"); break;
        default: break;
    }

    switch ((num % 100) / 10) {
        case 1: strcat(r, "X"); break;
        case 2: strcat(r, "XX"); break;
        case 3: strcat(r, "XXX"); break;
        case 4: strcat(r, "XL"); break;
        case 5: strcat(r, "L"); break;
        case 6: strcat(r, "LX"); break;
        case 7: strcat(r, "LXX"); break;
        case 8: strcat(r, "LXXX"); break;
        case 9: strcat(r, "XC"); break;
        default: break;
    }

    switch (num % 10) {
        case 1: strcat(r, "I"); break;
        case 2: strcat(r, "II"); break;
        case 3: strcat(r, "III"); break;
        case 4: strcat(r, "IV"); break;
        case 5: strcat(r, "V"); break;
        case 6: strcat(r, "VI"); break;
        case 7: strcat(r, "VII"); break;
        case 8: strcat(r, "VIII"); break;
        case 9: strcat(r, "IX"); break;
        default: break;
    }

    return r;
}