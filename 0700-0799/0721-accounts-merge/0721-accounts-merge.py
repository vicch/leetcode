"""
[NEED_REVIEW]

A typical union find problem: the emails in each input account form a union, where each email links to a root email
identifying a union.

Then the unions are merged when there are overlapping emails across two accounts.

After traversing all accounts, the emails should be properly unioned. Then by traversing all emails in the union and
finding their roots, all emails can be grouped by the roots. Each group is the all the emails of a merged account.

The account name can be looked up via a reverse lookup hashmap updated when traversing the accounts.

Time complexity:
- O(N*a(N)), where a(N) is inverse Ackermann function representing time complexity of union/find operations when there are
  N elements in the union find data structure. O(a(N)) grows very slowly and nearly constant.
- O(NlogN), for sorting the emails.
- Overall: O(NlogN)

Space complexity:
- O(N), for the union find data structure.
- O(N), for the lookup and email groups.
- Overall: O(N)
"""
import collections

class UnionFind:
    def __init__(self):
        self.parent = {}

    def find(self, x):
        # Path compression
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.parent[rootY] = rootX

class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        uf = UnionFind()
        emailNames = {}

        # Build the email unions, and email-name lookup map
        for account in accounts:
            name = account[0]
            firstEmail = account[1]

            for email in account[1:]:
                # Init each email's root as itself
                if email not in uf.parent:
                    uf.parent[email] = email

                # Union the email with the first email in current account
                uf.union(firstEmail, email)

                # Reverse map from name to email
                emailNames[email] = name

        # Group emails by their root base on the unions
        emailGroups = collections.defaultdict(list)
        for email in uf.parent:
            rootEmail = uf.find(email)
            emailGroups[rootEmail].append(email)

        # Merge names with sorted emails per email group
        merged = []
        for rootEmail, emails in emailGroups.items():
            merged.append([emailNames[rootEmail]] + sorted(emails))

        return merged
