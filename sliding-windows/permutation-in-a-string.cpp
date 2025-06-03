// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        vector<int>a1(26, 0);
        vector<int>a2(26, 0);
        for(char ch: s1) a1[ch - 'a']++; // frequency is here.
        int n = s1.length();
        int start = 0;
        for(int end = 0; end < s2.length(); end++){
            a2[s2[end] - 'a']++;
            while(end - start + 1 == n){
                if(a1 == a2) return true;
                a2[s2[start] - 'a']--;
                start++;
            }
        }
        return false;

    }
};
