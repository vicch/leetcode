"""
There are 2 patterns of palindrome: "abcba", and "abba"

Each substring (that is potentially a palindrome) can be uniquely identified by a pair of numbers (referred to
as coordinate) [center, radius]:
- For the first pattern, for example, "bcb" in "abcba" can be written as [2, 1], where 2 is index of "c", and
  1 is the number of letters before and after "c"
- For the second pattern, for example, "bb" in "abba" can be written as [1, 1], where 1 is index of the first
  "b", and 1 is the number of letters before (and inclusive of current letter) and after "b"

Out of all these substrings, the longest panlindrome is the one that has the longest radius. It can be found
in this way:
1. Init a list of coordinates with each char of the string as center, and 0 as radius.
2. Increment each coordinate's radius, if the new substring is not a palindrome, remove this coordinate from
   the list. If an coordinate is [x, y], to check if the new substring [x, y+1] is palindrome, we only need to
   compare the 2 chars off the head and tail of substring [x, y], because [x, y] was confirmed a palindrome
   in the previous cycle.
3. When there are none coordinate left, the last one that in the list will represent the longest palindrome.
"""
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)

        # Init longest palindrome coordinates for each pattern
        p1, p2 = [0, 0], [0, 0]

        # Get longest palindrome of pattern 1
        coords = [[i, 0] for i in range(length)]
        while len(coords) > 0:
            # All remaining palindromes have the same length, so any of them is the "longest", just pick the 1st one
            p1 = coords[0]
            for c in list(coords):
                c[1] += 1
                if c[0]-c[1] < 0 or c[0]+c[1] >= length or s[c[0]-c[1]] != s[c[0]+c[1]]:
                    coords.remove(c)

        # In the last cycle, the radius was incremented to a value that non substring is left, so the radius of the
        # longest palindrome is this value minus 1
        p1[1] -= 1

        # Get longest palindrome of pattern 2
        coords = [[i, 0] for i in range(length)]
        while len(coords) > 0:
            p2 = coords[0]
            for c in list(coords):
                c[1] += 1
                if c[0]-c[1]+1 < 0 or c[0]+c[1] >= length or s[c[0]-c[1]+1] != s[c[0]+c[1]]:
                    coords.remove(c)

        p2[1] -= 1

        # Check which pattern's longest palindrome is longer, by calculating the lengths via radius
        if p1[1] * 2 + 1 > p2[1] * 2:
            return s[p1[0]-p1[1]:p1[0]+p1[1]+1]
        else:
            return s[p2[0]-p2[1]+1:p2[0]+p2[1]+1]

s = Solution()
print(s.longestPalindrome("babad"))
print(s.longestPalindrome("cbbd"))
print(s.longestPalindrome("a"))
print(s.longestPalindrome("ac"))