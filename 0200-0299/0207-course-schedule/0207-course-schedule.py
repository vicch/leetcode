"""
For course A that depends on course B, it can be reprensented as course A has "1" dependency, and course B unblocks
course A. When course B is finished, course A's counter can decrement by 1. If the counter becomes 0, it means course A
can be finished as well, and thus it unblocks other courses accordingly.

Collect the lists of courses that each course can unblock, and its counter of remaining dependencies. Then using the
method above, we can maintain the counters of each course being unblocked. This can continue till there is no more
course that can be finished.

Check if all courses are finished via a global counter at the end.
"""
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        reverseDeps = [[] for _ in range(numCourses)]
        remainDeps = [0] * numCourses
        finished = 0

        for p in prerequisites:
            reverseDeps[p[1]].append(p[0])
            remainDeps[p[0]] += 1

        queue = []
        # Init queue with courses that can be finished at start
        for i in range(numCourses):
            if remainDeps[i] == 0:
                queue.append(i)

        # Continue till no more courses can be finished
        while queue:
            i = queue.pop(0)
            # For each course current course unblocks, remove its dependency counter
            for d in reverseDeps[i]:
                remainDeps[d] -= 1
                # If counter reaches 0, all this courses dependencies are finished, then it can be finished as well
                if remainDeps[d] == 0:
                    queue.append(d)
            finished += 1

        # Check if all courses are finished
        return finished == numCourses
