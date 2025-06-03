// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        int mnL = INT_MAX, count = 0, idx = 0, start = 0;

        unordered_map<char, int>tMap;
        unordered_map<char, int>sMap;

        for(char c: t) tMap[c]++;

        for(int end = 0; end < s.size(); end++){
            sMap[s[end]]++;

            if(tMap.count(s[end]) && tMap[s[end]] == sMap[s[end]]) count++;

            while(count == tMap.size()){
                if(end - start + 1 < mnL){
                    mnL = end - start + 1;
                    idx = start;
                }

                sMap[s[start]]--;
                if(tMap.count(s[start]) && sMap[s[start]] < tMap[s[start]]){
                    count--;
                }
                start++;
            }
        }

        if(mnL == INT_MAX) return "";
        return s.substr(idx, mnL);
    }
};
