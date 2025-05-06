/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/
 
// There are two approaches to this problem:
// 1. Linear search - Iterate through numbers, tracking which ones are missing (O(n+k) time)
// 2. Binary search - Exploit the sorted nature of the array for more efficiency (O(log n) time)

// APPROACH 1: LINEAR SEARCH
vector<int> arr = {2, 3, 4, 7, 11}; int k = 5;

int curr = 1;      // Start checking from the first positive integer
int count = 0;     // Count of missing numbers found so far
int i = 0;         // Pointer to current position in the array

// Continue until we've found k missing numbers
while(count < k){
    if(i < arr.size() && arr[i] == curr){
        // Current number exists in the array, move to next array element
        i++;
    }else{
        // Current number is missing, increment our missing count
        count++;
        if(count == k){
            // Found the kth missing number
            return curr;
        }
    }
    // Move to the next number to check
    curr++;
}

return curr;  // Fallback return (should not reach here given the problem constraints)

// Note: The binary search approach would be more efficient for large arrays
// as it can find the kth missing number in O(log n) time rather than O(n+k).

// APPROACH 2: BINARY SEARCH
/*
Binary Search Insight:
We can calculate how many positive numbers are missing before any position in the array.

Key Observation:
- In a perfect array with no missing numbers, arr[i] would equal i+1
  (e.g., [1,2,3,4,5] at indices [0,1,2,3,4])
- The difference (arr[i] - (i+1)) tells us how many numbers are missing up to position i

For example, with arr = [2,3,4,7,11]:
- At index 0: arr[0] = 2, expected = 1, missing = 2-1 = 1 number
- At index 1: arr[1] = 3, expected = 2, missing = 3-2 = 1 number
- At index 2: arr[2] = 4, expected = 3, missing = 4-3 = 1 number
- At index 3: arr[3] = 7, expected = 4, missing = 7-4 = 3 numbers
- At index 4: arr[4] = 11, expected = 5, missing = 11-5 = 6 numbers

Binary Search Strategy:
1. We use binary search to find the "lower bound" - the first position where the number 
   of missing values reaches or exceeds k
2. Once found, the kth missing number will be k + "number of positions we've examined"

Mathematical Insight (Why left + k works):
- After binary search, 'left' tells us how many array positions we've examined
- For each position, we expect to see the number (position+1)
- The kth missing number will be (left + k)

For our example where k = 5:
- Binary search gives us left = 4 (examined 4 positions)
- The answer is 4 + 5 = 9
*/

// Binary search implementation using lower bound approach
int findKthPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size();
    
    // Binary search to find the lower bound - first position where missing >= k
    while (left < right) {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1);
        
        if (missing < k) {
            // Not enough missing numbers yet, search right half
            left = mid + 1;
        } else {
            // Too many missing numbers, search left half
            right = mid;
        }
    }
    
    /*
    Elegant Solution Explanation (left + k):
    
    After binary search ends, 'left' represents the number of elements we've examined.
    Consider what this means:
    
    1. We've looked at elements 0 to (left-1) in the array
    2. In a perfect sequence, these positions would contain numbers 1 to left
    3. But k numbers are missing from this sequence
    
    Think of it this way:
    - If no numbers were missing, position 'left' would contain the number (left+1)
    - With k numbers missing, the value at position 'left' would be (left+1+k)
    - But since we're looking for the kth missing number, it's the kth number 
      before the value at position 'left', which is (left+k)
    
    This works even if 'left' is at the array boundary:
    - If left = 0: No elements examined, so the kth missing is just k
    - If left = arr.size(): We've examined all elements, and the kth missing 
      is (arr.size() + k)
    */
    return left + k;
}


// the end//