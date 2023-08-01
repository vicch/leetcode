"""
The problem can be generalized as finding the kth element of an array merged from 2 sorted arrays, where k is the middle
index of the merged array. It can then be divided and conquered using this generic kth() method. The key is to exclude
part of the arrays and narrow the kth element down to the remaining parts.

Consider 2 sorted arrays and their respective median elements:

l1: [_, _, ... _, ... _, _,]
     0  1  ... m1 ... -2 -1

l2: [_, _, ... _, ... _, _,]
     0  1  ... m2 ... -2 -1

If m1 + m2 < k and l1[m1] > l2[m2], then we can deduct the kth element isn't in l2[0:m2], because if it is, and
assuming this element is l2[n], and n < m2, then consider the merged list of l1 and l2 being l3:
- Among the elements l3[:k], which is basically l1[:k-n] + l2[:n], and l2[n] is the largest of these k elements
- Because m1 + m2 < k, and n < m2, so m1 + n < k, and m1 < k - n
- Because l1[m1] > l2[m2] > l2[n], and m1 < k - n, there must be l1[k - n] > l2[n]
- But we already assumed l2[n] > l1[k - n], so conclusion: l3[k] mustn't be in l2[:m2]

Thus the search can be narrowed down by excluding l2[:m2]. And for the other 3 combinations:
- m1 + m2 < k, l1[m1] <= l2[m2]
- m1 + m2 >= k, l1[m1] > l2[m2]
- m1 + m2 >= k, l1[m1] <= l2[m2]
Similar exclusions can be made.
"""
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        def kth(l1, l2, k):
            if not l1:
                return l2[k]
            if not l2:
                return l1[k]
            
            m1, m2 = len(l1) // 2, len(l2) // 2

            if m1 + m2 < k:
                if l1[m1] > l2[m2]:
                    return kth(l1, l2[m2+1:], k-m2-1)
                else:
                    return kth(l1[m1+1:], l2, k-m1-1)
            else:
                if l1[m1] > l2[m2]:
                    return kth(l1[:m1], l2, k)
                else:
                    return kth(l1, l2[:m2], k)
        
        l = len(nums1) + len(nums2)
        if l % 2 == 1:
            return kth(nums1, nums2, (l - 1) / 2)
        else:
            return (kth(nums1, nums2, l / 2 - 1) + kth(nums1, nums2, l / 2)) / 2.0
