"""
[NEED_REVIEW]

The min window has to start on a certain index, so the brute force solution is to attempt each index, look for the local min window and maintain
a global min. The issue is repeatedly traversing the substrings, leading to a O(N^2) complexity.

The key of improved solution is sliding window, where we only need to check the chars on the borders when extending or shrinking the window.
The approach is:

1. Extend right pointer of the window until a fulfilling substring is found, i.e. all required chars are included in the window.
2. Shrink left pointer while keeping the required chars fulfilled, and update the global optimal result if current window is better.
3. Continue step 1 until the end is reached.

To check if all required chars are fulfilled, we maintain a hashmap of char counts in the window, whenever a count reaches the required count in
string T, mark the char as fulfilled. When all chars are fulfilled, a good window is reached.

The trick is the flow control, which can be simplified via proper while conditions.

Time complexity:
- O(S+T), as the window pointers move through string S almost twice, and string T is traversed to get char counts.

Space complexity:
- O(1), as we only store char counts, and the cardinality is constant.
"""
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        counts = Counter(t)
        windowCounts = defaultdict(int)

        required = len(counts)
        achieved = 0

        l, r = 0, 0
        optimalL, optimalR = -1, len(s)

        while r < len(s):
            char = s[r]
            windowCounts[char] += 1

            if char in counts and windowCounts[char] == counts[char]:
                achieved += 1

            while l <= r and achieved == required:
                if r - l < optimalR - optimalL:
                    optimalL, optimalR = l, r

                char = s[l]
                windowCounts[char] -= 1
                
                if char in counts and windowCounts[char] < counts[char]:
                    achieved -= 1
                
                l += 1
            
            r += 1
        
        return s[optimalL:optimalR+1] if optimalL >= 0 else ""
