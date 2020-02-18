# Problem

Given a list of airline tickets represented by pairs of departure and arrival airports `[from, to]`, reconstruct the itinerary in order. All of the tickets belong to a man who departs from `JFK`. Thus, the itinerary must begin with `JFK`.

## Example 1

```
input  = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
output = ["JFK","MUC","LHR","SFO","SJC"]
```

## Example 2

```
input  = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
output = ["JFK","ATL","JFK","SFO","ATL","SFO"]
```

## Note

- If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.
- You may assume all tickets form at least one valid itinerary.

# Solution

(This is copied from someone else's solution.)

We can cleverly use the call stacks in recursive function calls to solve this problem.

1. Transform the edges to adjacency lists, and sort them in alphabetic order.
2. Visit `JFK`, and recursively visit the first adjacent node of each node, and remove that node from the adjacency list.
3. When there is no more adjacent node, we have reached the end of the trip. Push this node into the route and return.
4. Reverse the route in the end.
