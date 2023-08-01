#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ret;
		
		for (int i = 1, j = 1, k = 1; i <= n; i++, j++, k++) {
			if (j == 3 && k == 5) {
				j = 0, k = 0;
				ret.push_back("FizzBuzz");
			} else if (j == 3) {
				j = 0;
				ret.push_back("Fizz");
			} else if (k == 5) {
				k = 0;
				ret.push_back("Buzz");
			} else {
				ret.push_back(to_string(i));
			}
		}
		
		return ret;
	}
};