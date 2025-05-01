class Job {
public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

/*
    Maximum CPU Load - Problem Description
    
    We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. 
    Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.

    Example:
    Jobs: [[1,4,3], [2,5,4], [7,9,6]]
    Output: 7
    Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the jobs are running at the 
    same time i.e., during the time interval (2,4).
    
    Algorithm Approach:
    1. Sort all jobs by their start time
    2. Use a min-heap to track active jobs (sorted by end time)
    3. For each job, remove completed jobs from the heap
    4. Add the current job to the heap and calculate total CPU load
    5. Track the maximum CPU load seen at any point
*/

// Initialize the job values
vector<Job> jobs = {
    Job(1, 4, 3),  // Start: 1, End: 4, CPU Load: 3
    Job(2, 5, 4),  // Start: 2, End: 5, CPU Load: 4
    Job(7, 9, 6)   // Start: 7, End: 9, CPU Load: 6
};

// Alternative example with higher CPU load overlap
vector<Job> jobs2 = {
    Job(1, 4, 6),  // Start: 1, End: 4, CPU Load: 6
    Job(2, 6, 5),  // Start: 2, End: 6, CPU Load: 5
    Job(3, 9, 7)   // Start: 3, End: 9, CPU Load: 7
};

// For testing different scenarios
vector<Job> jobs3 = {
    Job(6, 7, 10), // Start: 6, End: 7, CPU Load: 10
    Job(2, 4, 11), // Start: 2, End: 4, CPU Load: 11
    Job(8, 12, 15) // Start: 8, End: 12, CPU Load: 15
};
