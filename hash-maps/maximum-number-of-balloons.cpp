// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:



// Input: text = "nlaebolko"
// Output: 1
// Example 2:



// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26, 0);

        for(char c: text) cnt[c - 'a']++;

        return min({
            cnt['b' - 'a'],
            cnt['a' - 'a'],
            cnt['l' - 'a'] / 2,
            cnt['o' - 'a'] / 2,
            cnt['n' - 'a']
        });
    }
};