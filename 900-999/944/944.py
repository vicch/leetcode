class Solution:
  def minDeletionSize(self, A: List[str]) -> int:
    if len(A) < 2:
      return 0

    d = 0

    # zip(*array) converts an array of strings to array of tuples, where tuple N contains the
    # Nth chars of each string, e.g.
    # a = ['abc', 'def', 'ghi']
    # zip(*a) -> [('a', 'd', 'g'), ('b', 'e', 'h'), ('c', 'f', 'i')]

    for col in zip(*A):
      for i in range(len(col) - 1):
        if col[i] > col[i+1]:
          d += 1
          break

    return d
