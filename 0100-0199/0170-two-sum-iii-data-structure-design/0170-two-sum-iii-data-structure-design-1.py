"""
Similar to plain two-sum problem, maintain the occurrences of added numbers, then iterate and look up the occurrence of
its complement for each target sum.

Edge case is when a candidate is equal to its complement, where its occurrence needs to be at least 2.

Time complexity:
- add(): O(1) for hashmap update
- find(): O(N) for linear iteration of added (unique) numbers

Space complexity:
- O(N) for hashmap of (unique) numbers
"""
class TwoSum:
    def __init__(self):
        self.counts = {}

    def add(self, number):
        if number not in self.counts:
            self.counts[number] = 0
        self.counts[number] += 1

    def find(self, value):
        for num in self.counts.keys():
            complement = value - num
            if complement != num:
                if complement in self.counts:
                    return True
            elif self.counts[num] > 1:
                return True
        return False
