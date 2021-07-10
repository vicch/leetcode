#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int i, j, k;
		
		// Moves the fast pointer, note it goes beyond the end of the array so the last part
		// can be processed correctly
		for (i = 0, j = 0, k = 0; i <= chars.size(); i++) {

			// Skip logic below and keep moving the fast pointer if the char is repeating
			if (i < chars.size() && chars[i] == chars[j])
				continue;
			
			// Write the char part of the compressed array, the char is always written, even if
			// it's not being compressed (which should be a single char without following
			// number in the compressed array)
			chars[k++] = chars[j];
			
			// Write the number part of the compressed array, skip it if the char only shows up
			// once
			if (i - j > 1)
				for (auto c : to_string(i - j))
					chars[k++] = c;
			
			// Make the slow pointer catch up with the fast pointer
			j = i;
		}
		
		// Current writing position marks the length of the compressed array
		return k;
	}
};
