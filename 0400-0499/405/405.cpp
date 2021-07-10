#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string toHex(int num) {
		// Mapping of digits to chars
		char map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
		vector<int> digits;
		// Flag to mark the number as negative
		bool negative = false;
		string hex = "";
		int i, j;
		
		if (num == 0)
			return "0";
		
		if (num < 0) {
			// -1 (1111...) actually mirrors 0 (0000...) insteac of 1 in binary form, so need to
			// offset the number by 1 if it's negative
			num = - (num + 1);
			negative = true;
		}
		
		// We fill in the 8 digits, even if they are all 0s in the end
		for (i = 0; i < 8; i++) {
			// If the number is negative, the digit should be mirrored, e.g. 0 mirrors to 15
			digits.push_back(negative ? (15 - num % 16) : (num % 16));
			num = num / 16;
		}
		
		// Ignore the trailing 0s
		for (i = 7; i >= 0 && digits[i] == 0; i--);
		
		// Translate the digits to chars
		for (j = 0; i >= 0; i--, j++)
			hex[j] = map[digits[i]];
		
		// Ending char
		hex[j] = '\0';
		
		return hex;
	}
};