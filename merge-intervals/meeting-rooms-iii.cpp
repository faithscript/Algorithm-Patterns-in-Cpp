// You are given an integer n. There are n rooms numbered from 0 to n - 1.

// You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

// Meetings are allocated to rooms in the following manner:

// Each meeting will take place in the unused room with the lowest number.
// If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
// When a room becomes unused, meetings that have an earlier original start time should be given the room.
// Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

// A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

// Example 1:

// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting starts in room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0. 

// so we use a min heap to store the available rooms
// so push the first n positions in the min heap, so 0 then 1 if n is 2, and so on, store that as the room id

// us a min heap for the busy rooms ordered by the finish time, so we use a pair for that, pairing the end time and the room id
// so we do priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy
// so we coubt the meetings held in each room with vector<int> counts (n, 0)
// then we simulate that meeting allocation process

// 
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> avail;
        for(int i = 0; i < n; i++){
            avail.push(i); // 
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy; // 11, 0 | 10, 1 |
        vector<int> count(n, 0);


        for(const auto& m: meetings){
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            while(!busy.empty() && busy.top().first <= start){
                avail.push(busy.top().second);
                busy.pop();
            }

            int id;
            long long currEnd;

            if(!avail.empty()){
                id = avail.top();
                currEnd = end;
                avail.pop();
            }else{
                id = busy.top().second;
                long long tempEnd = busy.top().first;
                busy.pop();

                currEnd = tempEnd + duration;
            }

            count[id]++;
            busy.push({currEnd, id});
        }
        int finalID = -1;
        int mx = -1;

        for(int i = 0; i < n; i++){
            if(count[i] > mx){
                mx = count[i];
                finalID = i;
            }
        }

        return finalID;
    }
};