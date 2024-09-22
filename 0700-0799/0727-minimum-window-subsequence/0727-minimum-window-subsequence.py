"""
The problem can be divided into:
- Find the shortest substring of s1 starting on each index i that contains s2 as subsequence
- Find the shortest substring of s1 ending on each index j that contains s2 as subsequence

The optimal result s1[i:j] must be the intersection of these substrings. So the local optimal solution can be found via
greedy improvement process, where we find the shortest s1[i1:j] that start on i, then the shortest s1[i2:j] that ends
on j. Then compare it with an overall optimal.

After finding the local optimal, the next potential optimal will at least start after index i of current optimal.
(Proof?)
"""
class Solution(object):
    def minWindow(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: str
        """
        # Find the min index j in s1 where s1[i:j] (i.e. the shortest substring that starts on index i) contains s2 as
        # subsequence
        def findLeftMostEnd(i1):
            i2 = 0
            while i1 < len(s1):
                if s1[i1] == s2[i2]:
                    i2 += 1
                    # Full s2 matched
                    if i2 == len(s2):
                        break
                i1 += 1
            return i1 if i2 == len(s2) else None

        # Find the max index i in s1 where s1[i:j] (i.e. the shorted substring that ends on index j) contains s2 as
        # subsequence
        def findRightMostStart(i1):
            i2 = len(s2) - 1
            while i2 >= 0:
                if s1[i1] == s2[i2]:
                    i2 -= 1
                i1 -= 1
            return i1 + 1

        min_window_len = float('inf')
        min_window = ''

        # Search for subsequences starting from each index in s1
        i = 0
        while i < len(s1):
            j = findLeftMostEnd(i)
            if j is None:
                break

            improved_i = findRightMostStart(j)

            # Step 3: Update the minimum window if the current window is smaller
            window_len = j - improved_i + 1
            if window_len < min_window_len:
                min_window_len = window_len
                min_window = s1[improved_i:j + 1]

            # Search for the next local optimal subsequence
            # We can skip the starting index in-between, because none of them will lead to a better result
            i = improved_i + 1

        return min_window
