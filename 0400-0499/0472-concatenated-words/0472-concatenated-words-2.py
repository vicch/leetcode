"""
The DP approach, from bottom up: we check whether each index i could be reached, but checking if there is a previous
index j that can be reached while the substring between j and i is available in the dict.
"""
class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        lookup = set(words)
        
        def _dp(word):
            n = len(word)

            # dp[n] means if we can reach index n of current word using available words
            dp = [False] * (n + 1)
            dp[0] = True
            
            # Check if we can reach index i
            for i in range(1, n + 1):
            	# Check if there is a bridge index j, that can be reached, and can lead to index i via existing word
                for j in range(i):
                	# Avoid matching word by itself
                    if j == 0 and i == n:
                        continue
                    if dp[j] and word[j:i] in lookup:
                        dp[i] = True
                        break
            
            return dp[n]

        result = []
        for word in words:
            if _dp(word):
                result.append(word)
        
        return result
