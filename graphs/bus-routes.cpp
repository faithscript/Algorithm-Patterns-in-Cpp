// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
SOLUTION: Buses as Nodes, Edges as Shared Stops
==============================================
- Each bus (route) is a node.
- There is an edge between two buses if they share at least one stop.
- BFS from all buses containing the source stop to any bus containing the target stop.
- The answer is the minimum number of buses needed to reach the target stop.
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> stopToBuses;
        // Build stop -> buses map
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }
        // BFS setup
        queue<pair<int, int>> q; // (bus index, buses taken)
        unordered_set<int> visitedBuses;
        unordered_set<int> visitedStops;
        // Start from all buses that include the source stop
        for (int bus : stopToBuses[source]) {
            q.push({bus, 1});
            visitedBuses.insert(bus);
        }
        visitedStops.insert(source);
        while (!q.empty()) {
            auto [bus, busesTaken] = q.front();
            q.pop();
            // Check if this bus visits the target stop
            for (int stop : routes[bus]) {
                if (stop == target) return busesTaken;
                // For each stop, try all buses that visit this stop
                for (int nextBus : stopToBuses[stop]) {
                    if (!visitedBuses.count(nextBus)) {
                        q.push({nextBus, busesTaken + 1});
                        visitedBuses.insert(nextBus);
                    }
                }
            }
        }
        return -1; // Not possible
    }
};

// Example 1:

// Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
// Output: 2
// Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
// Example 2:

// Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
// Output: -1
 

 

// Constraints:

// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 105
// All the values of routes[i] are unique.s
// sum(routes[i].length) <= 105
// 0 <= routes[i][j] < 106
// 0 <= source, target < 106

