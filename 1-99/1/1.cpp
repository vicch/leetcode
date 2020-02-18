#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> cache;
		
		for (int i = 0; i < nums.size(); i++) {
			// Found in cache, return the indice
			if (cache.find(target - nums[i]) != cache.end())
				return vector<int> {cache[target - nums[i]], i};
			
			// Not found in cache, add index to cache
			cache[nums[i]] = i;
		}
		
		return vector<int> {-1, -1};
	}
};