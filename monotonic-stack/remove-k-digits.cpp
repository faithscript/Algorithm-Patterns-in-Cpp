// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

class Solution {
public:
    string removeKdigits(string num, int k) {
        // remove digits larger and earlier
        // monotonic increasing stack, building the number digit by digit
        // remove from the stack when the current digit is smaller than the top of the stack, which means we found 
        // a better option

        // use the stack or string to store digits
        // for each digit in nums, if k > 0 and the top of the stack is > the current digit, pop from the stack 
        // and decrement k, push the current digit
        // if k > 0 after finishing, pop from the end of the stack
        // remove the leading zeros,m and return 0 if the list is empty

        string stk;
        for(char d: num){
            while(!stk.empty() && k > 0 && stk.back() > d){
                stk.pop_back();
                k--;
            }
            stk.push_back(d);
        }
        // if there are still digits to remove, so the number is already increasing)
        while(k-- && !stk.empty()){
            stk.pop_back();
        }

        // remove leading zeros
        int s = 0;
        while(s < stk.size() && stk[s] == '0'){
            s++;
        }
        string ans = stk.substr(s);
        return ans.empty()? "0" : ans;


    }
};