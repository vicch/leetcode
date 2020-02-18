// Problem:
// Given an array of integers and an integer k, find the number of unique k-
// diff pairs in the array. A k-diff pair is defined as an integer pair (i, j),
// where i and j are numbers in the array and their absolute difference is k.
// 
// Example:
// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2 ((1, 3) and (3, 5))
// 
// Solution:
// Use 1 map to store occurence of all numbers. For each number n, if n + k
// exists, a k-diff pair is found. If k == 0, a pair is found when the same
// number appears more than once.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_map<int,int> m;
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
            m[nums[i]]++;

        if (k > 0) {
            for (auto it = m.begin(); it != m.end(); ++it)
               if (m.find(it->first + k) != m.end())
                   res++;
        } else {
            for (auto it = m.begin(); it != m.end(); ++it)
               if (it->second > 1)
                   res++;
        }

        return res;
    }
};