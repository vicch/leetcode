"""
Just count the letter occurrences in both the available chars, and each word, and check if the needed letters are achievable one by one.

Can be improved to stop early if any letter in the target word cannot be fulfilled.

Time complexity:
- O(N + M * K), N = length of chars, M = number of words, K = letters for check per word.

Space complexity:
- O(1), as the cardinality is limited to letters which is constant.
"""
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        def isFormable(letters, word):
            for c in word:
                if c not in letters or letters[c] <= 0:
                    return False
                letters[c] -= 1
            return True

        avail = Counter(chars)
        result = 0
        for word in words:
            copy = avail.copy()
            if isFormable(copy, word):
                result += len(word)
                    
        return result
