// Problem:
// Given a non-empty array of integers, return the k most frequent elements.
// 
// Example:
// Input: [1,1,1,2,2,3], k = 2
// Output: [1,2]
// 
// Solution:
// Use an unordered map to store numbers and occurences. Sort occurences by
// buckets (for N numbers there are at most N + 1 buckets). Then collect k
// numbers starting from the largest bucket to the smallest.

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> r;

        for (int n: nums)
            m[n]++;

        for (auto p: m)
            buckets[p.second].push_back(p.first);
        
        for (int i = buckets.size() - 1; i >= 0 && r.size() < k; i--) {
            for (int n: buckets[i]) {
                r.push_back(n);
                if (r.size() == k)
                    break;
            }
        }

        return r;
    }
};