"""
Backtracking with tail recursion: don't pass the combinations up to current level to the next level, but pop the
combinations up from the bottom level as return value.
"""
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        
        letters = {
            "2": ["a", "b", "c"],
            "3": ["d", "e", "f"],
            "4": ["g", "h", "i"],
            "5": ["j", "k", "l"],
            "6": ["m", "n", "o"],
            "7": ["p", "q", "r", "s"],
            "8": ["t", "u", "v"],
            "9": ["w", "x", "y", "z"]
        }

        def combinations(offset):
            if offset == len(digits):
                return [""]
            
            return [l + c for l in letters[digits[offset]] for c in combinations(offset + 1)]

        return combinations(0)
