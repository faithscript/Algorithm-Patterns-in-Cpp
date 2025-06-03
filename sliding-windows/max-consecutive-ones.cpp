// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mxL = 0;
        int mxF = 0;
        int s = 0;

        unordered_map<int, int> mp;

        for(int e = 0; e < nums.size(); e++){
            if(nums[e] == 1){
                mp[nums[e]]++; 
                mxF = max(mp[nums[e]], mxF);  
            }
            if(e - s + 1 - mxF > k){
                mp[nums[s]]--;
                s++;
            }
            mxL = max(mxL, e - s + 1);
        }

        return mxL;
    }
};
