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
 

// game plan
// binary search
// 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0; int r = arr.size();

        while(l < r){
            int mid = l + (r-l)/2;
            int missing = arr[mid] - mid - 1;

            if(missing < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l + k;
    }
};