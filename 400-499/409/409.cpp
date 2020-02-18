#include <string>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int count[52] = {0};
		int len = 0;
		
		// Count the chars
		for (char c : s)
			if (c >= 'A' && c <= 'Z')
				count[c - 'A'] += 1;
			else
				count[c - 'a' + 26] += 1;
		
		// For how many chars are in pairs
		for (int i = 0; i < 52; i++)
			// -2 is 1111...1110, so N & -2 equals to N - N % 2
			len += count[i] & -2;
		
		// If there is still char left, use any one as the center char
		if (len < s.length())
			len += 1;
		
		return len;
	}
};
