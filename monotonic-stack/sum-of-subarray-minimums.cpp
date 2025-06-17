// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        // PLE: index of the nearest left element of i where arr[PLE[i]] < arr[i], if none then -1
        // NLE: index of the nearest element to the right of i such that arr[NLE[i]] < arr[i], if none use arr.size()

        // left = 1 - -1 = 2
        // right = 4 - 1 = 3
        // it is min (left * right) times
        // this contributes to arr[i] * left * right to the sum

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> PLE(n), NLE(n);
        stack<int> st;

        // finding the PLE;
        for(int i = 0; i < n; ++i){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            PLE[i] = st.empty()? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; --i){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            NLE[i] = st.empty()? n: st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            int l = i - PLE[i], r = NLE[i] - i;
            ans = (ans + 1LL * (arr[i] * l % MOD) * r % MOD) % MOD;
        }
        return ans;

    }
};