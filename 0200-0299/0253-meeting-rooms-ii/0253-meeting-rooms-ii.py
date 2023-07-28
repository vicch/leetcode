"""
The question is asking for the maximum number of concurrent meetings, i.e. the maximum number of meetings that have
overlapping times. 2 meetings overlap if the one that started earlier hasn't finished when the other starts. So an
ordering of the meetings by their starting time is important, which can achieved by sorting.

With the meetings sorted by starting times, iterate them and keep track of the finishing times of currently overlapping
meetings. This running number is the number of concurrent meetings at those points. Maintain a global max value for this
running number. And when the next meeting starts, push its finishing time to the list, and remove meetings that have
ended from the list when it starts.
"""