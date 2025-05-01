/*
    Conflicting Appointments - Problem Description
    
    Given an array of intervals representing 'N' appointments, determine if a person can attend all appointments
    without any conflicts. Two appointments conflict if they overlap in time.
    
    Example 1:
    Appointments: [[1,4], [2,5], [7,9]]
    Output: false
    Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
    
    Example 2:
    Appointments: [[6,7], [2,4], [8,12]]
    Output: true
    Explanation: None of the appointments overlap, a person can attend all of them.
    
    Algorithm Approach:
    1. Sort all appointments by their start time
    2. Check each pair of adjacent appointments for overlap
    3. If any overlap is found, return false (cannot attend all)
    4. If no overlaps are found, return true (can attend all)
*/

// Initialize vector of appointments
vector<vector<int>> appointments = {{1, 4}, {2, 5}, {7, 9}};
bool attend = true;

// Sort appointments by start time
sort(appointments.begin(), appointments.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
});

// Check for any overlapping appointments
int prev = appointments[0][1], n = appointments.size();

for(int i = 1; i < n; i++){
    int curr = appointments[i][0];
    if(prev > curr){
        attend = false;
        // you can return false here as well
    }
    prev = appointments[i][1];
}

// return attend here

