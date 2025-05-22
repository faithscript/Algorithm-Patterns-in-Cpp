// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> a;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return a;

        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size() - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j + 1, l = nums.size() - 1;
                while(k < l){
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        a.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1])k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }else if(sum < target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return a;
    }
};