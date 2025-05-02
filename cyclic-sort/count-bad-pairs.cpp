/*
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

*/

// we should find the good pairs first
// nums[j] - j  = nums[i] - i
// so we count the good pairs

// draw out the code to see it in action properly honestly

vector<int> nums = {4, 1, 3, 3};

long long count = 0;
int n = nums.size();
long long total = (n*(n-1))/2;
unordered_map<int, long long> mp;
for(int i = 0; i < n; i++){
    long long key = nums[i] - 1;
    count += mp[key];
    mp[key]++;
}

return total - count;

/* that's it :)*/