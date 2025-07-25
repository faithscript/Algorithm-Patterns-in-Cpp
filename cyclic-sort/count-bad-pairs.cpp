// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

 

// Example 1:

// Input: nums = [4,1,3,3]
// Output: 5
// Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
// The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
// The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
// The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
// The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
// There are a total of 5 bad pairs, so we return 5.
// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 0
// Explanation: There are no bad pairs.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        int  n = nums.size();
        long long total = (n * (n - 1)) / 2;
        unordered_map<int, long long>mp;
        for(int i = 0; i < nums.size(); i++){
            long long key = nums[i] - i;
            count += mp[key];
            mp[key]++; 
            
        }
        return total - count;
    }
};

// use proof by contradiction using 1 2 3 4 5 example
// total keeps total pairs and count tries to catch up then you return a difference
// count the nums[i] - i, and append the previous count before adding to the frequency again.
// prefix sums and pairs type solution

// so we keep a map of their nums[i] - i and count the good pairs, count should keep the prefix sums of the update to count pairs
// so 0 0 0 can from 3 unique pairs
// 0 0 0 0 can form 6 unique pairs = 0 + 1 + 2 + 3