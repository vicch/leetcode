#include <string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i, j;
		// Start from beginning of s and t, always move forward on t
		for (i = 0, j = 0; i < s.length(), j < t.length(); j++) {
			// Only move forward on s when the current char is found in t
			if (s[i] == t[j]) i++;
		}
		// If we have reached the end of s, all chars were found
		return i == s.length();
	}
};
