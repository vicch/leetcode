"""
Consider a multi-dimensional DP, for the 2 strings A and B, DP[m][n] contains the LCS length for the sub-strings A[0:m]
and B[0:n]. There are 2 cases:

- If A[m] and B[n] are the same character, then DP[m][n] is extending the LCS up to DP[m-1][n-1] by 1.
- If not, then DP[m][n] is not extending the LCS, and the LCS up to DP[m][n] is equal to the better LCS of the previous
  locations, i.e. DP[m-1][n] and DP[m][n-1].

By visiting all cells of the DP array from start to end, the last cell will contain the LCS for the 2 complete strings.
"""
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        l1, l2 = len(text1), len(text2)
        # Arrays are 0-indexed with index n indicating the nth char of the string, so length needs to be str length + 1.
        # Higher dimension list cannot use multiplication, otherwise every element is the same reference to the lower
        # dimension list.
        dp = [[0] * (l2+1) for _ in range(l1+1)]

        # dp[0][0] remains 0, the iterations start from the 1st char of each string.
        for i in range(1, l1+1):
            for j in range(1, l2+1):
                if text1[i-1] == text2[j-1]:
                    # Extending previous LCS
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[l1][l2]
