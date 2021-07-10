#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	// Return list of prime factors of the given number
	vector<int> getPrimeFactors(int num) {

		// The string's length is < 10000, if it's a composite number, one of its factors must
		// be smaller than sqrt(10000) which is 100
		vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		vector<int> factors;
		
		// Stop the loop if it reaches the last prime numbers in the list, or the number itself
		// is smaller than a prime number
		for (int i = 0; i < 25 && primes[i] <= num; i++)
			if (num % primes[i] == 0)
				factors.push_back(primes[i]);
		
		return factors;
	}
	
	// Check if the string can be divided as n identical substrings
	bool hasNRepeatedSubstring(string s, int n) {
		int l = s.size();
		int m = l / n;

		// For each char in the first substring of length m
		for (int i = 0; i < m; i++)
			// Check if it's equal to its corresponding char in the rest of the substrings of
			// length m
			for (int j = i + m; j < l; j += m)
				// If any substring is not identical, return false
				if (s[i] != s[j])
					return false;
		
		// All substrings are identical
		return true;
	}
public:
	bool repeatedSubstringPattern(string s) {
		vector<int> factors = getPrimeFactors(s.size());
		
		// For each prime factor n of the length, check if the string can be divided as n
		// identical substrings
		for (int f : factors)
			if (hasNRepeatedSubstring(s, f))
				return true;
		
		return false;
	}
};
