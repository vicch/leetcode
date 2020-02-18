#include <map>
#include <multiset>
#include <vector>

using namespace std;

class Solution {
private:
	map<string, multiset<string>> targets; // Adjacency lists
	vector<string> route;
	void visit(string stop);
public:
	vector<string> findItinerary(vector<vector<string>>& tickets);
};

vector<string> Solution::findItinerary(vector<vector<string>>& tickets) {
	// Init the adjacency lists
	for (auto t : tickets) {
		targets[t[0]].insert(t[1]);
	}
	// Visit first node
	visit("JFK");
	// Reverse the route and return
	return vector<string>(route.rbegin(), route.rend());
}

void Solution::visit(string stop) {
	while (targets[stop].size()) {
		// Visit the next stop
		string next = *targets[stop].begin();
		targets[stop].erase(targets[stop].begin());
		visit(next);
	}
	// When there is no next stop, this is the end stop of current call
	route.push_back(stop);
}