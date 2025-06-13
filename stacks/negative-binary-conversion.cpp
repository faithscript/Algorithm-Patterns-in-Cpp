// Given an integer n, return a binary string representing its representation in base -2.

// Note that the returned string should not have leading zeros unless the string is "0".

 

// Example 1:

// Input: n = 2
// Output: "110"
// Explantion: (-2)2 + (-2)1 = 2
// Example 2:

// Input: n = 3
// Output: "111"
// Explantion: (-2)2 + (-2)1 + (-2)0 = 3
// Example 3:

// Input: n = 4
// Output: "100"
// Explantion: (-2)2 = 4

class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";

        stack<char>st;

        while(n != 0){
            int rem = n%-2;
            n/=-2;

            if(rem < 0){
                rem += 2; // if rem is -1, then n is -1 but should be 1 and 0;
                n+=1;
            }

            st.push('0'+rem);
        }

        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        return res;
    }
};


class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0) return "0";

        string res = "";

        while(n != 0){
            int rem = n%-2;
            n/=-2;

            if(rem < 0){
                rem += 2; // if rem is -1, then n is -1 but should be 1 and 0;
                n+=1;
            }

            res = char('0' + rem) + res;
        }

        return res;
    }
};

