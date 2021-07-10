#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		// Lookup list of the last occurrence position of each char, assuming
		// it's ASCII char. If we don't know the possible range of the char, we
		// need to use a hash map, which takes more space.
		vector<int> lastPos (128, -1);

		// Init the starting position of current window, and length of current
		// longest non-repeating substring.
		int startIdx = 0, maxLen = 0;
		
		for (int i = 0; i < s.size(); i++) {
			
			if (startIdx <= lastPos[s[i]]) {
				// If current character's last occurrence exists, and is after
				// the window's starting position, the window needs to be moved
				// to start after the last occurrence of current character (so
				// that current character only appears once in current window,
				// which is at current position).
				startIdx = lastPos[s[i]] + 1;
			} else {
				// If window doesn't need to move (current character doesn't
				// exist in current window), check if the longest non-repeating
				// substring lengths needs to be updated.
				maxLen = max(maxLen, i - startIdx + 1);
			}

			// Update the lookup list
			lastPos[s[i]] = i;
		}
		
		return maxLen;
	}
};
