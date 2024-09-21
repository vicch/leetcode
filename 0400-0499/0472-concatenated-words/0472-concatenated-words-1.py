"""
Firstly this problem can be divided into: iterate the words and check if it can be concatenated, and collect it in the
result if yes.

Then for each word, it can be considered as a variation of "climbing stairs" problem, where each word in the dict is a
possible step to take if it is the prefix of the target word.

Then by attempting all possible next steps recursively from the start of the word, and return true if the end of the
word can be reached, we get the result for that word.

Naturally this can be optimized with:
- A dict the memorizes all word suffixes that can or cannot be concatenated, and resued across the words, or
- A DP array that remembers the local results per word.
- The memorization will lead to more, and unpredictable space complexity, while the DP array is predictable but less
performant overall.

Also note that we don't need to enumerate or return the actual concatenation solution, which means each cycle only
needs a binary result, and can return as soon as a yes/no is confirmed.
"""
class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        lookup = set(words)
        memory = dict()

        def _dfs(word):
            # Check if already memorized
            if word in memory:
                return memory[word]

            # Iterate prefix and suffix combinations
            for i in range(1, len(word)):
                prefix, suffix = word[:i], word[i:]

                # The prefix doesn't work, return early
                if prefix not in lookup:
                    continue

                # If prefix works, check if suffix works: either it's directly a word, or it can be concatenated
                if suffix in lookup or _dfs(suffix):
                    memory[word] = True
                    return True
            
            # None of the combinations work, this word cannot be concatenated
            memory[word] = False
            return False

        result = []
        for word in words:
            if _dfs(word):
                result.append(word)
        return result
