#include <stdio.h>
#include <math.h>

double myPow(double x, int n);

int main()
{
    printf("%f\n", myPow(8.88023, 3));
    printf("%f\n", myPow(-13.62608, 3));

    printf("%f\n", myPow(1.0, 2147483647));   // Pass: 1.00000
    printf("%f\n", myPow(-1.0, 2147483647));  // Pass: -1.00000
    printf("%f\n", myPow(1.0, -2147483648));  // Pass: 1.00000
    printf("%f\n", myPow(-1.0, -2147483648)); // Pass: 1.00000

    printf("%f\n", myPow(0.00001, 3));               // Pass: 0.00000
    printf("%f\n", myPow(0.00001, -3));              // Nopa: 999999999999999.50000
    printf("%f\n", myPow(0.00001, 2147483647));      // Pass: 0.00000
    printf("%f\n", myPow(0.00001, -2147483648));     // Pass: inf

    printf("%f\n", myPow(-0.00001, 3));              // Pass: -0.00000
    printf("%f\n", myPow(-0.00001, -3));             // Nopa: -999999999999999.50000
    printf("%f\n", myPow(-0.00001, 2147483647));     // Pass: -0.00000
    printf("%f\n", myPow(-0.00001, -2147483648));    // Pass: inf

    printf("%f\n", myPow(2147483647, 3));            // Pass: 9903520300447984143910830080.00000
    printf("%f\n", myPow(2147483647, -3));           // Pass: 0.00000
    printf("%f\n", myPow(2147483647, 2147483647));   // Pass: inf
    printf("%f\n", myPow(2147483647, -2147483648));  // Pass: 0.00000

    printf("%f\n", myPow(-2147483648, 3));           // Pass: -9903520314283042199192993792.00000
    printf("%f\n", myPow(-2147483648, -3));          // Pass: -0.00000
    printf("%f\n", myPow(-2147483648, 2147483647));  // Pass: -inf
    printf("%f\n", myPow(-2147483648, -2147483648)); // Pass: 0.00000

    return 0;
}

double myPow(double x, int n)
{
    double r = 1.0;
    int multi = (n > 0) ? 1 : 0;
    int sign = (x > 0) ? 1 : ((n % 2 == 0) ? 1 : -1);

    x = (x < 0) ? -x : x;
    if (x == 1.0)
        return x * sign;

    if (n == -2147483648) {
        if ((x > 0 && x < 1) || (x < 0 && x > -1)) return INFINITY;
        else return 2.3E-308;
    }
    n = abs(n);
    
    while (n-- > 0) {
        r = (multi) ? r * x : r / x;
        if (r > 1.7E+308) return INFINITY * sign;
        if (r < 2.3E-308) return 0.0 * sign;
    }
    return r * sign;
}