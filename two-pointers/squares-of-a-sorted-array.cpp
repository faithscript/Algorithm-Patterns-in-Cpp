Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int n = nums.size() - 1;
        vector<int> result(nums.size());

        while(i <= j){
            long long iS = nums[i] * nums[i];
            long long jS = nums[j] * nums[j];
            if(iS > jS){
                result[n] = iS;
                i++;
            }else{
                result[n] = jS;
                j--;
            }
            n--;
        }
        return result;
    }
};