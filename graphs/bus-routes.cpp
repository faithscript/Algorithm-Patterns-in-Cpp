// You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

// For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
// You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

// Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> stopToBuses;
        int n = routes.size();

        for(int i = 0; i < n; i++){
            for(const auto& stop: routes[i]){
                stopToBuses[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedBus;


        for(const auto& bus: stopToBuses[source]){
            q.push({bus, 1});
            visitedBus.insert(bus);
        }


        while(!q.empty()){
            auto [bus, busTaken] = q.front(); q.pop();

            for(int stop: routes[bus]){
                if(stop == target) return busTaken;

                for(int nextBus: stopToBuses[stop]){
                    if(!visitedBus.count(nextBus)){
                        q.push({nextBus, busTaken + 1});
                        visitedBus.insert(nextBus);
                    }
                }
            }
        }
        return -1;
    }
};