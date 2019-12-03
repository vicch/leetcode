#include <stdio.h>

typedef int bool;

bool isBadVersion(unsigned long version);
unsigned long firstBadVersion(unsigned long n);
unsigned long range(unsigned long f, unsigned long t);
unsigned long iterRange(unsigned long f, unsigned long t);

unsigned long main()
{
    printf("%ld\n", firstBadVersion(2126753390));

    return 0;
}

bool isBadVersion(unsigned long version)
{
    printf("%ld\n", version);
    return version >= 1702766719;
}

unsigned long firstBadVersion(unsigned long n)
{
    unsigned long left = 1;
    unsigned long right = n;
    while (left < right) {
        unsigned long mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

// unsigned long firstBadVersion(unsigned long n)
// {
//     if (isBadVersion(1))
//         return 1;

//     return range(1, n);
// }

// unsigned long range(unsigned long f, unsigned long t)
// {
//     if (f == t)
//         return f;

//     if (f + 1 == t)
//         return t;

//     if (f + 3 >= t)
//         return iterRange(f, t);

//     unsigned long v1 = (f * 3 + t) / 4;
//     unsigned long v2 = (f + t) / 2;
//     unsigned long bv1 = isBadVersion(v1);
//     unsigned long bv2 = isBadVersion(v2);

//     if (bv1 && bv2)
//         return range(f, v1);
//     else if (!bv1 && bv2) {
//         if (v2 == v1 + 1)
//             return v2;
//         else
//             return range(v1, v2);
//     }

//     unsigned long v3 = (f + t * 3) / 4;
//     unsigned long bv3 = isBadVersion(v3);

//     if (!bv2 && !bv3)
//         return range(v3, t);
//     else {
//         if (v3 == v2 + 1)
//             return v3;
//         else
//             return range(v2, v3);
//     }
// }

// unsigned long iterRange(unsigned long f, unsigned long t)
// {
//     for (f += 1; f < t; f++) {
//         if (isBadVersion(f))
//             return f;
//     }
//     return t;
// }