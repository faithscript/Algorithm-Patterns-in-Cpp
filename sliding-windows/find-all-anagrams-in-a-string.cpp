// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

// Example 1:

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>aP(26, 0); vector<int>aS(26, 0);
        vector<int>ans;
        for(char ch: p) aP[ch - 'a']++;
        int n = p.length(), st = 0;

        for(int en = 0; en < s.length(); en++){
            aS[s[en] - 'a']++;
            if(en - st + 1 == n){
                if(aS == aP){
                    ans.push_back(st);
                }
                aS[s[st] - 'a']--;
                st++;
            }
        }
        return ans;
    }
};