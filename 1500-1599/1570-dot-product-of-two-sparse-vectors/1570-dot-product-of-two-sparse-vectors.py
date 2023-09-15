"""
The object basically needs to memorize the dimensions that are non-zero, then intersect the dimensions of the 2 vectors
and add up the product for the dimensions. The mem can be based on hashmap from dimension index to value.

Some tricks:
- Iterate the vector object with shorter dimensions, for a bit perf gain. This also speeds up the case when only one
vector is sparse.
- Instead of hashmap, use list for less space. As the dimension indice are naturally sorted, we can use 2 pointers to
iterate the lists by moving the pointer with smaller dimension index, and add the product if they match.

Time: O(n) for populating the mem
Space: O(m) where m is number of non-zero dimensions
"""
class SparseVector:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.dims = {i: v for i, v in enumerate(nums) if v > 0}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec):
        """
        :type vec: 'SparseVector'
        :rtype: int
        """
        product = 0
        # Iterate the smaller list of dimensions.
        if len(vec.dims) < len(self.dims):
            for i, v in vec.dims.items():
                if i in self.dims:
                    product += self.dims[i] * v
        else:
            for i, v in self.dims.items():
                if i in vec.dims:
                    product += vec.dims[i] * v
        return product
