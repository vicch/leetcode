"""
The key is find the min rounds to complete n tasks, with each round completing 2 or 3 tasks. Basically:
f(n) = min(f(n-3), f(n-2)) + 1

But it actually doesn't need a recursion, because by manually listing the min rounds starting from 2
(1 task isn't completable), the pattern can be found:

tasks minRounds
2     1
3     1
4     2
5     2
6     2
7     3
8     3
9     3
...

So f(n) = floor((n + 2) / 3)
"""
class Solution(object):
    def minimumRounds(self, tasks):
        """
        :type tasks: List[int]
        :rtype: int
        """

        counts = collections.defaultdict(int)

        for t in tasks:
            counts[t] += 1

        rounds = 0
        for c in counts.values():
            if c < 2:
                return -1
            rounds += int((c + 2) / 3)
        
        return rounds
