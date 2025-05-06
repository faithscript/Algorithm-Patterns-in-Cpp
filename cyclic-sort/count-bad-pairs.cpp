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

/*
Approach Explanation:
1. We use the relationship: j - i != nums[j] - nums[i] to identify bad pairs
2. We can rearrange this to find good pairs (where j - i == nums[j] - nums[i])
3. Rearranging: nums[j] - j == nums[i] - i
4. This means for good pairs, the value (nums[index] - index) must be the same for both elements
5. So we count how many pairs have the same value of (nums[index] - index)
6. The total pairs possible in an array of size n is n*(n-1)/2
7. We subtract the count of good pairs from the total possible pairs to get bad pairs
*/

/*
Prefix Sum and Pair Counting Explanation:

The way we count pairs in this problem is similar to how prefix sums work. When we process each element,
we're essentially forming pairs with all previously seen elements that share the same (nums[i] - i) value.

Consider elements with the same (nums[i] - i) value:
- First occurrence: 0 pairs (nothing to pair with yet)
- Second occurrence: 1 pair (can pair with the previous element)
- Third occurrence: 2 pairs (can pair with both previous elements)
- Fourth occurrence: 3 pairs (can pair with all three previous elements)

This creates a pattern: 0 + 1 + 2 + 3 + ... + (k-1) pairs for k elements with the same value.
This sum equals k*(k-1)/2, which is the formula for combinations of k elements taken 2 at a time.

The hash map effectively creates these running counts for each different (nums[i] - i) value,
allowing us to add the appropriate number of pairs each time we encounter a new element.
*/

// we should find the good pairs first
// nums[j] - j  = nums[i] - i
// so we count the good pairs

// draw out the code to see it in action properly honestly

vector<int> nums = {4, 1, 3, 3};

// Will hold the total count of good pairs
long long count = 0;

// Get the size of the array
int n = nums.size();

// Calculate total possible pairs using the formula n*(n-1)/2
long long total = (n*(n-1))/2;

// Map to count occurrences of (nums[i] - i) value
unordered_map<int, long long> mp;

// Iterate through the array
for(int i = 0; i < n; i++){
    // Calculate the key value (nums[i] - i)
    long long key = nums[i] - i;
    
    // For current element, add number of previous elements with the same key
    // These form good pairs with the current element
    count += mp[key];
    
    // Increment the count of elements with this key
    mp[key]++;
}

// Total pairs - Good pairs = Bad pairs
return total - count;

/* that's it :)*/