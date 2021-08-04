class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Filter out non-alphanumeric characters and lowercase all characters
        s = "".join(c.lower() for c in s if c.isalnum())
        
        l = len(s)
        for i in range(l // 2):
            # Compare char pairs from head and tail
            if s[i] != s[l-i-1]:
                return False

        return True
