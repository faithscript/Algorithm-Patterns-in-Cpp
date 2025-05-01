/*
    Interval Intersection - Problem Description
    
    Given two lists of non-overlapping intervals sorted by their start times,
    find all intersections between these two interval lists.
    
    An intersection is defined as the interval that exists in both lists.
    For two intervals to intersect, they must share at least one common point.

    Example:
    Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
    Output: [[2, 3], [5, 6], [7, 7]]
    Explanation: The output contains all intervals where arr1 and arr2 overlap.
    
    Algorithm Approach:
    1. Use two pointers to traverse both interval lists simultaneously
    2. For each pair of intervals, calculate their intersection (if any)
    3. Move the pointer of the interval that ends earlier to the next interval
    4. Continue until we've processed all intervals in either list
*/

// Initialize the two interval vectors
vector<vector<int>> arr1 = {{1, 3}, {5, 6}, {7, 9}};
vector<vector<int>> arr2 = {{2, 3}, {5, 7}};
vector<vector<int>> result;

int i = 0, j = 0, m = arr1.size(), n = arr2.size();

while(i < m && j < n){
    // Find the intersection points
    int start = max(arr1[i][0], arr2[j][0]);
    int end = min(arr1[i][1], arr2[j][1]);

    // If there is an intersection, add it to the result
    // SO, If the maximum start time between two intervals is more than the minimum end time
    if(start <= end){
        result.push_back({start, end});
    }
    
    // Move the pointer of the interval that ends earlier
    if(arr1[i][1] < arr2[j][1]){
        i++;
    }else{
        j++;
    }
}

// you can return the result here



