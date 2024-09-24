"""
A less systematic approach: the idea is that we interwoven the chars, and the most difficult char to organize would be
the most frequent one. If this char is organized properly, all other chars can fall in places pretty easily.

The method is to present the chars in a matrix row by row, starting with the most frequent one which decides the width:

e.g. "aab" would be:

a a
b

or "aaa...bbb...ccc...ddd..." would be:

a a a ... a ... a
b b ... b c ... c
d d ...

Then join the chars column by column: a b d a b d a ...

The most frequent char needs to take up the entire first row, and the order or remaining chars doesn't matter, as they
won't stretch more than one row, and they will be separated at least by one char in the first row.
"""
class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)

        # Count all occurrences while maintaining most frequent char and its count
        max_char, max_count = "", 0
        counts = collections.defaultdict(int)
        for c in s:
            counts[c] += 1
            if counts[c] > max_count:
                max_char, max_count = c, counts[c]

        # Pruning condition: if one char appears >50% in original string, there is no solution
        if max_count > ceil(1.0 * n / 2):
            return ""

        # Join the chars in a single sequence, starting with the most frequent one
        chars = [max_char] * max_count
        for char, count in counts.items():
            if char == max_char:
                continue
            chars.extend([char] * count)

        # Compute dimensions of the matrix to follow to walk through the chars
        width, height = max_count, int(ceil(1.0 * n / max_count))

        result = ""
        # Iterate x and y coordinates of the matrix
        for i in range(width):
            for j in range(height):
                # Map matrix cell to index in the one-dimensional list
                index = j * width + i
                # On the last row of the matrix, there may be out-of-bound index
                if index >= n:
                    break
                result += chars[index]

        return result
