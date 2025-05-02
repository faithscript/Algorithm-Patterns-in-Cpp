/*
    Find Duplicate Number - Problem Description
    
    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
    There is only one repeated number in nums, return this repeated number.
    
    You must solve the problem without modifying the array nums and using only constant extra space.

    Example 1:
    Input: nums = [1,3,4,2,2]
    Output: 2
    
    Algorithm Approach:
    1. Use cyclic sort to place each number at its correct index (nums[i] at index nums[i]-1)
    2. When we encounter a duplicate number, it will try to go to an index that already has the correct value
    3. After sorting, the first number that doesn't match its expected position is the duplicate
*/

vector<int> nums = {1, 3, 4, 2, 2};

// Apply cyclic sort - place each number at index (value-1)
for(int i = 0; i < nums.size(); i++){
    // While current number isn't at its correct position and hasn't been encountered before
    while(nums[i] != nums[nums[i] - 1]){
        swap(nums[i], nums[nums[i] - 1]);
    }
}

// Find the number that isn't at its correct position
for(int i = 0; i < nums.size(); i++){
    if(nums[i] != i+1){
        // Return the duplicate number
        return nums[i];
    }
}

// If no duplicate found (should not happen given the problem constraints)
return -1;
/* the end */

// Find all duplicate numbers will just need a  push back of all the nums[i] into the array;