"""
Based on math, if there is a GCD string, then its length must also be GCD of both strings.

It cannot be a smaller divisor than the GCD, because if both strings are divisible by this smaller string, then they must be divisible by the
GCD string as well.

So we just need to get the potential GCD string as substring str1[:gcd], and check if both strings are divisible by it, by traversing the string
and compare the corresponding index.

Time complexity:
- O(N + M), for traversing the strings.

Space complexity:
- O(min(N, M)), for the potential GCD string.
"""
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        def gcd(a, b):
            # When b becomes 0, the previous values of b (which is now assigned to a) is the GCD.
            while b:
                a, b = b, a % b
            return a

        def isDivisible(s1, s2):
            l1, l2 = len(s1), len(s2)
            # Traverse s1 and rotate pointer of s2, to compare the corresponding chars.
            for i in range(l1):
                if s1[i] != s2[i % l2]:
                    return False
            return True

        l1, l2 = len(str1), len(str2)
        lgcd = gcd(l1, l2)
    
        # The potential GCD string.
        sgcd = str1[:lgcd]

        if isDivisible(str1, sgcd) and isDivisible(str2, sgcd):
            return sgcd
        
        return ""
        