"""
This is more of the problem about DS manipulation than algorithm. Firstly we need to collect the sorted website visits
per user. Then we count then occurrence of all unique three-website combinations of those visits. Lastly return the
combination with highest count and smallest value.

Time: pretty hard to tell
Space: same
"""
class Solution(object):
    def mostVisitedPattern(self, username, timestamp, website):
        """
        :type username: List[str]
        :type timestamp: List[int]
        :type website: List[str]
        :rtype: List[str]
        """
        # Collect website visits by user, no need to sort these globally, we only need to sort the visits per user.
        userVisits = collections.defaultdict(list)
        for i in range(len(username)):
            userVisits[username[i]].append((timestamp[i], website[i])) # O(n*k)

        patternCounts = collections.defaultdict(int)
        for visits in userVisits.values():
            # Sort visits by timestamps for this user.
            visits.sort(key=lambda x: x[0]) # O(klogk)
            websites = [v[1] for v in visits]

            # For each unique pattern of three-website combination, maintain the counter.
            for pattern in set(itertools.combinations(websites, 3)): # O(k^3)
                patternCounts[tuple(pattern)] += 1
        
        # Sort the patterns by counts in desc order, then by alphabetic in asc order.
        sortedPatterns = sorted(patternCounts.items(), key=lambda x: (-x[1], x[0])) # O(n*k^3)?
        return sortedPatterns[0][0]
