"""
The resulting bits array is:

Section   | 0 | 1   | 2       | 3 
Index   0 | 1 | 2 3 | 4 5 6 7 | 8 9 ...
Value   0 | 1 | 1 2 | 1 2 2 3 | 1 2 ...

Section N's length is 2^N. And the values in sections N is just [bits[0] + 1, bits[1] + 1, ...]. So the result array
can be obtained by using a pointer that repeatedly starts from index 0 and iterate 2^N times to read existing values
and increment by 1 to populate the following values.

Time: O(n)
Space: O(n), including the output array
"""
class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n == 0:
            return [0]
        
        bits = [0]
        length = 1
        
        while True:
        	# Start iterating 2^N numbers from index 0
            for i in range(length):
            	# Populate next value
                bits.append(bits[i] + 1)
                # If enough values have been populated
                if len(bits) == n + 1:
                    return bits
            length *= 2
