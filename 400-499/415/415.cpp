#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		vector<int> digits;

		int i = num1.length() - 1;
		int j = num2.length() - 1;
		
		// Start from last digits of the strings, till both strings are finished and there is
		// no carry over
		for (int digit = 0; i >= 0 || j >= 0 || digit > 0; i--, j--) {
			digit += (i >= 0 ? (num1[i] - '0') : 0) + (j >= 0 ? (num2[j] - '0') : 0);
			digits.push_back(digit % 10);
			digit /= 10;
		}
		
		// Init the result, need to assign enough space
		int l = digits.size();
		string ret(l + 1, '0');
		
		// Populate the digits backward
		for (int n = 0; n < l; n++)
			ret[n] = digits[l - n - 1] + '0';
		
		// End of string
		ret[l] = '\0';
		
		return ret;
	}
};