/*
    Insert Interval - Problem Description
    
    Given a sorted list of non-overlapping intervals, insert a new interval into the list
    while ensuring the resulting list contains only non-overlapping intervals.
    
    If necessary, merge the new interval with existing ones to maintain the non-overlapping property.

    Example:
    Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
    Output: [[1,3], [4,7], [8,12]]
    Explanation: After insertion, [4,6] overlaps with [5,7], so they are merged into [4,7].
*/

/*
    Algorithm Approach:
    
    1. Add all intervals that end before the new interval starts
    2. Merge the new interval with any intervals that overlap with it
    3. Add all remaining intervals that start after the new interval ends
    
    This three-step approach efficiently handles the insertion while maintaining the 
    non-overlapping property of the resulting interval list.
*/

vector<vector<int>> intervals = {{1, 3}, {5, 7}, {8, 12}};
vector<int> newInterval = {4, 6};
vector<vector<int>>answer;

int i = 0, n = intervals.size();

// Step 1: Add all intervals that end before newInterval starts
while(i < n && intervals[i][1] < newInterval[0]){
    answer.push_back(intervals[i]);
    i++;
}

// Step 2: Merge overlapping intervals
while(i < n && intervals[i][0] <= newInterval[1]){
    newInterval[0] = min(intervals[i][0], newInterval[0]);
    newInterval[1] = max(intervals[i][1], newInterval[1]);
    i++;
}

// Step 3: Add the merged interval
answer.push_back(newInterval);

// Step 4: Add all remaining intervals
while(i < n){
    answer.push_back(intervals[i]);
    i++;
}

//you can return the answer


