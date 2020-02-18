#include <stdio.h>

int isPrime(int n);
int countPrimesRange(int f, int t);
int countPrimes(int n);

int main()
{
    int i;

    for (i = 100000; i < 2000000; i += 100000) {
        printf("%d:%d\n", i, countPrimes(i));
    }

    return 0;
}

int isPrime(int n)
{
    int i;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0 && n > i)
            return 0;
    }

    return 1;
}

int countPrimesRange(int f, int t)
{
    int cnt = 0;

    for (; f < t; f++)
        cnt += isPrime(f);

    return cnt;
}

int countPrimes(int n)
{
    if (n <= 1)
        return 0;

    int cnt;

    if      (n < 100000)  cnt = countPrimesRange(2, n);
    else if (n < 200000)  cnt = countPrimesRange(100000,  n) + 9592;
    else if (n < 300000)  cnt = countPrimesRange(200000,  n) + 17984;
    else if (n < 400000)  cnt = countPrimesRange(300000,  n) + 25997;
    else if (n < 500000)  cnt = countPrimesRange(400000,  n) + 33860;
    else if (n < 600000)  cnt = countPrimesRange(500000,  n) + 41538;
    else if (n < 700000)  cnt = countPrimesRange(600000,  n) + 49098;
    else if (n < 800000)  cnt = countPrimesRange(700000,  n) + 56543;
    else if (n < 900000)  cnt = countPrimesRange(800000,  n) + 63951;
    else if (n < 1000000) cnt = countPrimesRange(900000,  n) + 71274;
    else if (n < 1100000) cnt = countPrimesRange(1000000, n) + 78498;
    else if (n < 1200000) cnt = countPrimesRange(1100000, n) + 85714;
    else if (n < 1300000) cnt = countPrimesRange(1200000, n) + 92938;
    else if (n < 1400000) cnt = countPrimesRange(1300000, n) + 100021;
    else if (n < 1500000) cnt = countPrimesRange(1400000, n) + 107126;
    else if (n < 1600000) cnt = countPrimesRange(1500000, n) + 114155;
    else if (n < 1700000) cnt = countPrimesRange(1600000, n) + 121127;
    else if (n < 1800000) cnt = countPrimesRange(1700000, n) + 128141;
    else if (n < 1900000) cnt = countPrimesRange(1800000, n) + 135072;
    else                  cnt = countPrimesRange(1900000, n) + 142029;

    return cnt;
}