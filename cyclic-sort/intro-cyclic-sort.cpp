/*
    Cyclic Sort - Introduction
    
    Cyclic sort is a pattern useful for dealing with arrays containing values in a given range.
    This pattern describes an approach where you iterate through the array and place each number
    at its correct position.
    
    The key insight of Cyclic Sort is that we can use the array values as indices.
    If the array contains values in range [1...n] or [0...n-1], we can efficiently sort it
    by placing each number at its correct position.
    
    Example:
    Input: [3, 1, 5, 4, 2]
    Output: [1, 2, 3, 4, 5]
    
    Algorithm steps:
    1. Iterate through the array
    2. If the current element is not at its correct position, swap it with the element at its correct position
    3. Continue until all elements are in their correct positions
*/
/*
Problem Statement
We are given an array containing n objects. Each object, when created, was assigned a unique number from the range 1 to n based on their creation sequence. 
This means that the object with sequence number 3 was created just before the object with sequence number 4.

Write a function to sort the objects in-place on their creation sequence number in  without using any extra space. For simplicity, 
let's assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.

Example 1:

Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]
Example 2:

Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]

*/

vector<int> nums = {3, 1, 5, 4, 2};

int i = 0;
while(i < nums.size()){
    int c = nums[i] - 1; // nums[i] = i + 1; i = nums[i] - 1;
    if(nums[i]!= nums[c]){
        swap(nums[i], nums[c]);
    }else{
        i++;
    }
}

// this will sort the array in place

