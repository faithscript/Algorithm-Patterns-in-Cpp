// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        // Push all characters onto the stack
        for (char c : s) {
            st.push(c);
        }

        // Pop characters back into the array
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};
