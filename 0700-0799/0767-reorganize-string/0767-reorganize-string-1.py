"""
The optimal strategy is simply: for any prefix of the string, the next char should be the one that is currently most
frequent as well as unequal to the precedent char.

Since we constantly read and update the char with most occurrence, it's naturally to use a heap to store the counts.

The trick is to keep the last char out of the heap for selection of next char, but insert it back when the next char is
appended. The appended char then takes the place of the last char.

Assuming k = distinct chars:

Time complexity:
- Counting chars: O(n)
- Heap read/write: O(logk) * n
- Final: O(nlogk)

Space complexity:
- Counter: O(k)
- Heap: O(k)
- Result: O(n)
- Final: O(n + k)
"""
import heapq
from collections import Counter

class Solution(object):
    def reorganizeString(self, s):
        freq = Counter(s)

        # Build max heap using negative values
        max_heap = [(-count, char) for char, count in freq.items()]
        heapq.heapify(max_heap)

        # Optional pruning technique: there is no solution, if any char occurs >50% of original string
        max_count = -(heapq.nsmallest(1, max_heap)[0][0])
        if max_count > ceil(len(s) / 2) + 1:
            return ""

        # Hold last character and its remaining count
        prev_count, prev_char = 0, ''

        result = []

        # There is no option to place next char when either all chars placed, or there is still one held in prev_char
        # which cannot be placed repeatedly.
        while max_heap:
            # Get the next char to place
            count, char = heapq.heappop(max_heap)

            result.append(char)

            # If the previous character has remaining count, push it back into the heap
            if prev_count < 0:
                heapq.heappush(max_heap, (prev_count, prev_char))

            # Rotate previous character and count
            prev_count, prev_char = count + 1, char

        result_str = ''.join(result)

        # If the result's length is not the same as the input string, it's impossible to reorganize
        return result_str if len(result_str) == len(s) else ""
