"""
One approach is find a way to choose a delimiter and escape it in the original strings before joining, then un-escape
it when decoding. The rules to follow is a bit annoying.

Another approach is to invent a simple encoding with metadata: if we know the length of each sub-string, then it's easy
to decode. The lengths can be encoded into the string in a certain format, e.g "3:abc2:ab", so the decoding logic keeps
looking for the "xx:" pattern after each sub-string, and parse the "xx" as length for the next. Keep 2 running pointers
to mark the start and end of each "xx" field.
"""
class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        return ''.join([str(len(s)) + ':' + s for s in strs])

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        strs = []
        i = 0
        while i < len(s):
            # 2nd pointer stops at ":" delimiter
            j = i
            while s[j] != ':':
                j += 1
            # Parse the length
            l = int(s[i:j])
            # Move 1st pointer to start of next cycle
            i = j + l + 1
            # Extract sub-string
            strs.append(s[j+1:i])
        return strs
