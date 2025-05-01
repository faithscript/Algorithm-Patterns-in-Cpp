/* 
   Merging Intervals - Introduction
   
   The core concept of merging intervals involves identifying and combining overlapping intervals.
   
   Example: Intervals: [[1, 4], [2, 5], [7, 9]]
   
   Each interval is represented as [start time, end time]
   
   When intervals [1, 4] and [2, 5] overlap, we merge them to form [1, 5]
   [7, 9] remains unchanged as it doesn't overlap with any other interval.

   Output: [[1, 5], [7, 9]]
*/

/*
   Key Considerations in Merging Intervals:
   
   1. We must sort intervals by start time to enable efficient merging
      Example: {[1, 4], [10, 12], [6, 7]} should be sorted to {[1, 4], [6, 7], [10, 12]}

   2. Overlapping Condition:
      Two intervals overlap when one interval starts before or during the end of another
      More precisely: If interval A ends after interval B starts, they overlap
      
      Example: [1, 4] overlaps with [2, 5] because 4 > 2

   3. Merging Rule:
      When merging overlapping intervals [a, b] and [c, d], the result is:
      [min(a, c), max(b, d)]
      
      Example: Merging [1, 4] with [2, 5] gives [1, 5]
*/ 

// Implementation of the merge intervals algorithm

vector<vector<int>>intervals = {{1, 4}, {2, 5}, {7, 9}};
vector<vector<int>>answer;

int n = intervals.size();

// sorting by the start times
sort(intervals.begin(), intervals.end(), [](const vector<int>&a, vector<int>&b){
   return a[0] < b[0];
});

//initialize previous interval

vector<int>prev = intervals[0];
for(int i = 1; i < n; i++){
   vector<int>curr = intervals[i];
   if(prev[1] >= curr[0]){
      prev[1] = max(prev[1], curr[1]);
   }else{
      answer.push_back(prev);
      prev = curr;
   }
}

// the last interval is left out of the push back loop
answer.push_back(prev);

// you can return the answer


