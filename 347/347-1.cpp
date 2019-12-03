// Problem:
// Given a non-empty array of integers, return the k most frequent elements.
// 
// Example:
// Input: [1,1,1,2,2,3], k = 2
// Output: [1,2]
// 
// Solution:
// Use an unordered map to store numbers and occurences. Sort the map by value,
// then return k numbers from the end. (Sort map in C++ returns a multimap, and
// the keys and values are flipped.)

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> c;
        multimap<int, int> sc;
        multimap<int, int>::reverse_iterator it;
        vector<int> r;
        
        for (int n: nums)
            c[n]++;
        
        // Sort map by value, result is a multimap
        sc = flip_map(c);
        
        // Return values of k right-most elements of sorted map
        for (it = sc.rbegin(); k > 0 && it != sc.rend(); it++, k--)
            r.push_back(it->second);
            
        return r;
    }
    
    multimap<int, int> flip_map(const map<int, int> &src) {
        multimap<int, int> dst;
        transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair);
        return dst;
    }

    static pair<int, int> flip_pair(const pair<int, int> &p) {
        return pair<int, int>(p.second, p.first);
    }
};