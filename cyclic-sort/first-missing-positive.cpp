/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

/*
Algorithm Explanation:

1. Problem Insight: 
   - We want to find the smallest missing positive integer in the array.
   - For an array of size n, the answer must be in the range [1, n+1].
   - If all numbers 1 to n are present, then the answer is n+1.

2. Key Approach:
   - Use cyclic sort pattern where we place each number at its correct index (nums[i] at index nums[i]-1).
   - Only valid numbers (1 to n) can be placed at their correct positions.
   - After sorting, scan for the first position where the index+1 doesn't match the value.

3. Implementation Details:
   - First, mark all invalid numbers (≤0 or >n) by replacing them with n+1 (out of valid range).
   - Then, perform cyclic sort, placing each valid number at its correct position.
   - Finally, scan the array - the first position where nums[i] ≠ i+1 is our answer.
   - If all elements are in place, return n+1.
*/

vector<int> nums = {3, 4, -1, 1};
int n = nums.size();  // Get size once for efficiency and clarity

// Step 1: Mark all numbers outside the valid range [1,n] as n+1
// This effectively removes negative numbers, zeros, and numbers > n from consideration
for(int i = 0; i < nums.size(); i++){
    if(nums[i] <= 0 || nums[i] > n){
        nums[i] = n + 1;  // Using n+1 as a marker for invalid numbers
    }
}

// Step 2: Perform cyclic sort - place each number at its correct index
// For each valid number k, place it at index k-1
for(int i = 0; i < nums.size(); i++){
    // Current number falls in valid range and isn't already at its correct position
    while(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i] - 1]){
        swap(nums[i], nums[nums[i] - 1]);  // Place at correct position
    }
}

// Step 3: Find the first position where the expected number is missing
// If position i doesn't contain i+1, then i+1 is missing
for(int i = 0; i < nums.size(); i++){
    if(nums[i] != i + 1){
        return i + 1;  // Found the first missing positive integer
    }
}

// Step 4: If all positions have correct values, the answer is n+1
return n + 1;  // All numbers from 1 to n are present, so n+1 is the answer

// Time Complexity: O(n) - we make at most 2n swaps in the sorting phase
// Space Complexity: O(1) - we use only constant extra space