"""
No complex algorithm, just collect and convert the time points per name, then check if there is >=3 time points within a 60-minute window.

The trick is to handle the time strings as numerics by converting them to minutes, and sort them. Also note that there is no need to consider
cycles as all times are supposed to be the same day.

For window checking, a simple way is to just compare if each time[n] vs. time[n+2] are >60 minutes apart.
"""
class Solution(object):
    def alertNames(self, keyName, keyTime):
        """
        :type keyName: List[str]
        :type keyTime: List[str]
        :rtype: List[str]
        """
        def stringToMinute(s):
            base = ord('0')
            return (ord(s[0]) - base) * 600 + (ord(s[1]) - base) * 60 + (ord(s[3]) - base) * 10 + (ord(s[4]) - base)
 
        records = defaultdict(list)
        for i in range(len(keyName)):
            records[keyName[i]].append(stringToMinute(keyTime[i]))

        result = []
        for name, minutes in records.items():
            minutes.sort()
            for i in range(len(minutes) - 2):
                if minutes[i] + 60 >= minutes[i + 2]:
                    result.append(name)
                    break
        
        result.sort()
        return result
