"""
Consider DP: dp[i][j] represents the min steps needed (i.e. distance) to make word1[i:] and word2[j:] the same, then:

- If word1[i] == word2[j], no step is needed on current letters, and dp[i][j] == dp[i+1][j+1]
- Otherwise there are 3 options:

- Remove current letter on word1
- Insert current letter of word2 to word1
- Replace current letter of word1 with word2

Find the optimal distance among all 3 solutions and set it to dp[i][j].

At the end, dp[0][0] is the distance between the whole strings word1 and word2.
"""

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = len(word1), len(word2)
        dp = [[None] * l2 for _ in range(l1)]

        def getDistance(i, j):
            # If either pointer has reached the end, the distance at this point is either remove or insert all remaining
            # letters on the other string
            if i >= l1:
                return l2 - j
            elif j >= l2:
                return l1 - i

            if dp[i][j] is None:
                # If letters match, no change is needed, move both pointers forwards
                if word1[i] == word2[j]:
                    dp[i][j] = getDistance(i+1, j+1)

                else:
                    # If remove current letter of word1
                    dist1 = getDistance(i+1, j) + 1

                    # If insert current letter of word2 to word1
                    dist2 = getDistance(i, j+1) + 1

                    # If replace current letter of word1 with current letter of word2
                    dist3 = getDistance(i+1, j+1) + 1

                    dp[i][j] = min(dist1, dist2, dist3)

            return dp[i][j]

        return getDistance(0, 0)
