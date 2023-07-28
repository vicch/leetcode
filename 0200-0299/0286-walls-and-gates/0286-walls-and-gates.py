"""
At first it seems a typical DFS problem: starting from each gate cell and progressively mark the adjacent cells with
incrementing distance. For searches that start from other gates, stop the search when a smaller distance is met.

Actually it's simpler as BFS: pushing all gate cells to the queue first, then pop cells from the queue and mark its
adjacent cells (that are not walls and not marked yet) with distance that is +1 of current cell's distance, and
continue. If one cell is closer to another gate, it must have been visited and marked already.
"""