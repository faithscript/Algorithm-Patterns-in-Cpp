// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for(char c : s){
            cnt[c - 'a']++;
        }
        for(int i = 0; i < s.size(); ++i){
            if(cnt[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};

// game plan: use a vector to store the character indices
// pre fill it with the characters in the sdtribng then iuterate again for when the count is 1, and return i
//else just return -1