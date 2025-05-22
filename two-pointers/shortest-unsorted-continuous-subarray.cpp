// Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1, r = -1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                l = i - 1;
                break;
            }
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                r = i + 1;
                break;
            }
        }
        if(l == -1 && r == -1){
            return 0;
        }
        int sMin = INT_MAX, sMax = INT_MIN;
        for(int i = l; i <= r; ++i){
            sMin = min(sMin, nums[i]);
            sMax = max(sMax, nums[i]);
        }
        while(l > 0 && nums[l-1] > sMin){
            l--;
        }
        while(r < nums.size() - 1 && nums[r+1] < sMax){
            r++;
        }

        return r - l + 1;
    }
};