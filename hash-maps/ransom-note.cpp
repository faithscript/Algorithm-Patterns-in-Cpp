// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0);
        vector<int> m(26, 0);

        for(char c: ransomNote) r[c - 'a']++;
        for(char c : magazine) m[c - 'a']++;

        for(int i = 0; i < 26; i++){
            if(r[i] > 0 && m[i] < r[i]) return false;
        }

        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> m(26, 0);

        for(char c : magazine) m[c - 'a']++;

        for(char c: ransomNote){
            if(--m[c - 'a'] < 0) return false;
        }

        return true;
    }
};