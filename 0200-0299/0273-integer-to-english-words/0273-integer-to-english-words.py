"""
The problem can be divided into:
- Convert each section between the commas, then append the "thousands" suffix.
- For each section, there are 2 patterns for <20 and >=20.
- The words can be predefined and indexed by the number values.
"""
class Solution(object):
    def __init__(self):
        # Prepend empty slots so we don't need to offset the index when reading
        self.below_twenty =[
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        self.tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        self.thousands = ["", "Thousand", "Million", "Billion"]

    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "Zero"

        result = []
        index = 0
        while num > 0:
            section = num % 1000
            if section != 0:
                result.append(self.helper(section) + self.thousands[index])
            num //= 1000
            index += 1

        # The sections were processed from smaller end
        result.reverse()
        return " ".join(result).strip()

    def helper(self, num):
        if num == 0:
            return ""
        elif num < 20:
            # The extra space for different cases:
            # - If it's the lowest section, it will be stripped
            # - If it's higher section, there needs a space before "Thousand" etc.
            return self.below_twenty[num] + " "
        elif num < 100:
            # Recursive invocation to simplify the logic
            return self.tens[num // 10] + " " + self.helper(num % 10)
        else:
            return self.below_twenty[num // 100] + " Hundred " + self.helper(num % 100)
