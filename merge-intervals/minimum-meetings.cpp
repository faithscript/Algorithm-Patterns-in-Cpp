/*
    Minimum Meeting Rooms - Problem Description
    
    Given a list of intervals representing meeting time slots, find the minimum number
    of meeting rooms required to schedule all meetings without conflicts.
    
    A meeting room can only be used for one meeting at a time. If a meeting ends at time X,
    another meeting can start at time X (no buffer time required between meetings).
    
    Example 1:
    Meetings: [[1,4], [2,5], [7,9]]
    Output: 2
    Explanation: We need two meeting rooms to accommodate [1,4] and [2,5] simultaneously.
    
    Example 2:
    Meetings: [[6,7], [2,4], [8,12], [1,3]]
    Output: 2
    Explanation: We need two rooms because [2,4] and [1,3] overlap.
    
    Algorithm Approach:
    1. Sort all meetings by their start time
    2. Use a min-heap (priority queue) to track end times of meetings in progress
    3. For each meeting, check if any previous meeting has ended (room freed up)
    4. The maximum size of the heap at any point represents the minimum rooms needed
*/

vector<vector<int>>meetings = {{1, 4}, {2, 5}, {7, 9}};
int minRooms = 0;
int curRooms = 0;

sort(meetings.begin(), meetings.end(), [](const vector<int>&a, const vector<int>&b){
    return a[0] < b[0];
});

priority_queue<int, vector<int>, greater<int>> minHeap;

for(int i = 0; i < meetings.size(); i++){
    while(!minHeap.empty() && minHeap.top() < meetings[i][0]){
        minHeap.pop();
        curRooms--;
    }
    minHeap.push(meetings[i][1]);
    curRooms++;
    minRooms = max(minRooms, curRooms);
}

struct compareEnd{
    bool operator()(const Job& a, const Job& b){
        return a.end > b.end;
    }
};

priority_queue<Job, vector<Job>, compareEnd> minHeap;
int currCPU = 0, maxCPU = 0;

for(const auto& job: jobs){
    while(!minHeap.empty() && minHeap.top().end <= job.start){
        currCPU -= minHeap.top().cpuLoad;
        minHeap.pop();
    }
    minHeap.push(job);
    currCPU += job.cpuLoad;
    maxCPU = max(currCPU, maxCPU);
}
// you can return maxCPU here
