// Problem:
// Given a nested list of integers, implement an iterator to flatten it. Each
// element is either an integer, or a list whose elements may also be integers
// or other lists.
// 
// Example:
// Input: [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// 
// Solution:
// Flatten each element in the nested list, push integer into a vector and
// recursively flatten lists.

class NestedIterator {
    vector<int> nums;
    int s, i;
    
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (NestedInteger i: nestedList)
            flatten(i);
        s = nums.size();
        i = 0;
    }
    
    void flatten(NestedInteger& i) {
        if (i.isInteger())
            nums.push_back(i.getInteger());
        else
            for (NestedInteger j: i.getList())
                flatten(j);
        return;
    }

    int next() {
        return nums[i++];
    }

    bool hasNext() {
        return i < s;
    }
};