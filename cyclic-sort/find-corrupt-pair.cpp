/*
We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.

Example 1:

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
*/

// it's just a matter of sorting then appending the missing and duplicate number

vector<int> nums = {3, 1, 2, 5, 2};

// cyclic sorting

for(int i = 0; i < nums.size(); ++i){
    while(nums[i] != nums[nums[i] - 1]){
        swap(nums[i], nums[nums[i] - 1]);
    }
}

for(int i = 0; i < nums.size(); ++i){
    if(nums[i] != i+1){
        return vector<int> {nums[i], i+1};
    }
}
// else
return vector<int> {-1, -1};

/* the endddd */
