/*
We are given an array containing n distinct numbers taken from the range 0 to n. Since the array has only n numbers out of the total n+1 numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2

*/

// Initialize the vector array with the example input
vector<int> nums = {4, 0, 3, 1};  // Missing number is 2

// Additional test cases
vector<int> nums2 = {8, 3, 5, 2, 4, 6, 0, 1};  // Missing number is 7
vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};  // Missing number is 8

// using nums

int i = 0;
whlie(i < nums.size()){
    int curr = nums[i];  // nums[i] = i;
    if(nums[i] != nums[curr]){
        swap(nums[i], nums[curr]);
    }else{
        i++;
    }
}

for(int j = 0; j < nums.size(); j++){
    if(nums[j] != j){
        //return that number which will be j
        return j;
    }
}

// return the last number (n) if no number was returned
return n;

