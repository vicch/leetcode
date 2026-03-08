"""
# Problem Type & Pattern

A one-pass filtering problem with state tracking. We process the array left-to-right, keeping only the first occurrence of each anagram group. The operation constraints (removing adjacent anagrams repeatedly) naturally collapse into a single linear scan because once we decide to keep a word, all words to its left are finalized.

---

# Solution Explanation

## Step 1 - Brute Force Idea

Repeatedly scan the array from left to right, removing any word at index `i` where `words[i-1]` and `words[i]` are anagrams. Continue this process until a full scan finds no adjacent anagram pairs to remove. Each scan is O(n) and we might need multiple scans, giving worst-case O(n²) time.

## Step 2 - Optimization Insight

The key observation is that once we decide to keep a word at position `i`, all words before `i` are permanently final. We only need to know whether the current word is an anagram of the *last kept word* — all earlier words don't matter because any anagram groups would have already been collapsed by then. This eliminates the need for repeated scans.

## Step 3 - Final Optimal Strategy

Initialize the result with the first word and track its "canonical form" (sorted string). Iterate through remaining words, comparing each word's sorted form to the last kept word's sorted form. If they differ, add the word to result and update the tracker. If they match, skip the word (it's an anagram of the last kept and should be removed).

## Complexity

Time: O(n × k log k) where n = number of words, k = average word length (sorting each word)
Space: O(n × k) for the result array, plus O(k) for tracking the sorted form of the last kept word
"""

class Solution:
    def removeAnagrams(self, words):
        result = [words[0]]
        prev = sorted(words[0])

        for w in words[1:]:
            if sorted(w) != prev:
                result.append(w)
                prev = sorted(w)

        return result
