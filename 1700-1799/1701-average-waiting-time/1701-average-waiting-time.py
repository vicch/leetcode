"""
There is no alternative or better way than computing and aggregating the wait time per customer.

The trick is to find the preparation start time for each customer: it's either the end time of last customer, or the
arrive time of current customer, whichever comes later.

We can keep a running timer indicating the current time as each customer is served.
"""
class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        waitTotal = 0
        current = 0

        for arrival, time in customers:
            # Start time of current customer
            current = max(current, arrival)

            # End time of current customer
            current += time

            # Aggregate their wait time
            waitTotal += current - arrival

        return 1.0 * waitTotal / len(customers)
