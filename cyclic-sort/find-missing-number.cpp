/*
We are given an array containing n distinct numbers taken from the range 0 to n. Since the array has only n numbers out of the total n+1 numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            while(nums[i] < n && nums[i] != nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                return i;
            }
        }

        return n;

    }
};
