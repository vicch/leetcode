"""
Typical use case of cache with TTL: memorize the last time each message was printed, and for the next matching message,
check if the last printed time has expired. Print and refresh the cache if yes.

Time complexity:
- O(1), for hashmap lookup

Space complexity:
- O(N), for number of unique messages
"""
class Logger(object):
    def __init__(self):
        self.last_messages = {}

    def shouldPrintMessage(self, timestamp, message):
        """
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        if message not in self.last_messages or self.last_messages[message] <= timestamp - 10:
            self.last_messages[message] = timestamp
            return True
        return False
