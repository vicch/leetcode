"""
Prefix sum is the sum of first n elements in an array, prefixSum[n] = sum(array[0:n])

The key is find the relation between prefix sums: if prefixSum[n] and prefixSum[m] have the same remainder (modulo)
when dividing by k, then sum(array[n:m]) is divisible by k.

So the solution is for each prefixSum[n], find the number of prefixSum[m], where m < n, and have the same remainder
when divided by k.
"""
class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # Prefix sum modulo counts
        modulos = collections.defaultdict(int)
        # For subarrays starting from the first element, its previous prefix sum is 0
        modulos[0] = 1

        count = 0
        prefixSum = 0

        for n in nums:
            prefixSum += n
            modulo = prefixSum % k
            # Find number of previous prefix sums with same modulo
            count += modulos.get(modulo, 0)
            modulos[modulo] += 1

        return count
