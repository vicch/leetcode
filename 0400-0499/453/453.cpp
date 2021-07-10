#include <vector>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = INT_MAX;
		long sum = 0;
		
		for (auto n : nums) {
			// Get sum of all numbers
			sum += n;
			// Find the min number
			if (min > n)
				min = n;
		}
		
		// How many moves are needed to reduce all numbers to the value of the min number
		return sum - min * nums.size();
	}
};
