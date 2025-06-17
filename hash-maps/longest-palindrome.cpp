// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase and/or uppercase English letters only.

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;

        int ans = 0;
        bool hasOdd = false;

        for(auto& [c, freq] : mp){
            if(freq % 2 == 0){
                ans += freq;
            }else{
                ans += freq - 1;
                hasOdd = true;
            }
        }

        if(hasOdd) ans += 1;

        return ans;
        
        
    }
};