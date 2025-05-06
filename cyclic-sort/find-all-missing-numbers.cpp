/*
We are given an unsorted array containing numbers taken from the range 1 to 'n'. The array can have duplicates, which means some numbers will be missing. 
Find all those missing numbers.

Example 1:

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.

*/

// Initialize the vector array with the example input
vector<int> nums = {2, 3, 1, 8, 2, 3, 5, 1};  // Missing numbers: 4, 6, 7

// the beautiful thing about cyclic sort is that we can use indices to our advantage, so the missing numbers will just be the indices that have the wrong numbers in them

vector<int>answer;
for(int i = 0; i < nums.size(); i++){
    while(nums[i] != i + 1){
        swap(nums[i], nums[nums[i] - 1]);
    }
}

for(int i = 0; i < nums.size(); i++){
    if(nums[i] != i+1){
        answer.push_back(i+1);
    }
}

/* you can return answer here */ 

