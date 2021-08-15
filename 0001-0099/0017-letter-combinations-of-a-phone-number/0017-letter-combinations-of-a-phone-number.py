"""
Typical backtracking: the list of combinations up to each digit is the combinations of:

- the combinations up to the preceding digit
- the possible letters of current digit

Multiply the 2 lists and continue to next digit.
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

        def backtrack(offset, combinations):
            # Reached last digit
            if offset == len(digits):
                return combinations

            # Cartesian product of existing list (combinations of digits before current one) and possible letters of
            # current digit
            return backtrack(offset + 1, [c + l for c in combinations for l in letters[digits[offset]]])

        # Note: kick off with list of one empty string instead of empty list
        return backtrack(0, [""])
