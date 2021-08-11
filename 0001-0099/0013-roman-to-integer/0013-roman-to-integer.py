"""
According to definition, there is only one case when the value represented by one letter should be substracted from the
total value: when the next letter's value is higher than this letter's value.

So just check for such situations, otherwise just add up the values represented by the letters.
"""

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

        # Translate all letters to values
        values = [mapping[c] for c in s]

        total = 0

        for i in range(len(values) - 1):
            # Current value should be substracted
            if values[i] < values[i+1]:
                total -= values[i]
            else:
                total += values[i]

        # Last value is always added
        total += values[-1]

        return total
