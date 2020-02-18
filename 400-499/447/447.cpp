#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
	int getDistance(vector<vector<int>>& points, int i, int j) {
		int x = points[i][0] - points[j][0];
		int y = points[i][1] - points[j][1];
		return x * x + y * y;
	}

public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int total = 0;
		
		for (int i = 0; i < points.size(); i++) {
			// Cache of counts of distances
			unordered_map<int, int> cache;
			
			// For each point i, iterate all other points
			for (int j = 0; j < points.size(); j++) {
				int dist = getDistance(points, i, j);

				// Assuming the current count of this distance is n, then:
				// - number of boomerangs before current increment = n * (n - 1)
				// - number of boomerangs after current increment  = (n + 1) * n
				// The diff is n * 2, so we just need to add n * 2 to get the new number of
				// boomerangs from the old number
				if (cache[dist] > 0)
					total += cache[dist] * 2;

				// Increment count of this distance
				cache[dist] += 1;
			}
		}
		
		return total;
	}
};
