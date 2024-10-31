"""
It's natrual to use a sliding window on string S, and for each slide, check if the current window is an anagram.

To identify an anagram, we need to track the chars count in the window. It's an anagram when it exactly matches the string P. For each slide we
only need to look at the border chars to update the chars count inside the window.

There are tricks of flow control and state presentation:
- Instead of matching all chars count, we can keep a counter that counts the remaining letters need to be exactly matched to form an anagram.
  This counter is updated when a char reaches or leaves the exact match state. And when it reaches 0, it means all chars are matched and thus
  it's an anagram.
- Traverse the entire string S, and for each cycle, always extend the window's right border to current index, and conditionally shrink the left
  border.

Time complexity:
- O(N), where N is length of string S.

Space complexity:
- O(K), for the counter, where K is number of distinct chars, and can be considered constant.
"""
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        ls, lp = len(s), len(p)

        # Prune impossible cases
        if ls < lp:
            return []

        counts = Counter(p)
        # Remaining letters from getting an anagram in current window.
        # It's an anagram when this counter reaches 0.
        remain = len(counts)
        results = []

        for i in range(ls):
            # Extend window's right border to this char.
            c = s[i]
            if c in counts:
                # Always decrement char count, even to negative values.
                counts[c] -= 1
                # If count just reached 0, this char isn't blocker of anagram.
                if counts[c] == 0:
                    remain -= 1
            
            # Shrink window's left border.
            if i >= lp:
                c = s[i - lp]
                if c in counts:
                    # Always increment char count.
                    counts[c] += 1
                    # If count just reaches 1, it must previously be 0, and it becomes blocker of anagram.
                    if counts[c] == 1:
                        remain += 1

            # If there is no blocker, the current window is an anagram.
            if remain == 0:
                results.append(i - lp + 1)

        return results
