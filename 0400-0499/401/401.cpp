#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		// Pre-computed hours and minutes
		vector<int> hours[4] = {
			{0},
			{1, 2, 4, 8},
			{3, 5, 6, 9, 10},
			{7, 11}
		};
		vector<int> minutes[6] = {
			{0},
			{1, 2, 4, 8, 16, 32},
			{3, 5, 6, 9, 10, 12, 17, 18, 20, 24, 33, 34, 36, 40, 48},
			{7, 11, 13, 14, 19, 21, 22, 25, 26, 28, 35, 37, 38, 41, 42, 44, 49, 50, 52, 56},
			{15, 23, 27, 29, 30, 39, 43, 45, 46, 51, 53, 54, 57, 58},
			{31, 47, 55, 59}
		};
		vector<string> times;
		
		// both i and num-i must be within valid range
		for (int i = max(0, num - 5); i < min(4, num + 1); i++) {
			for (auto h : hours[i]) {
				for (auto m : minutes[num - i]) {
					times.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
				}
			}
		}
		
		return times;
	}
};