// You are given a string s and an array of strings words. All the strings of words are of the same length.

// A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
// Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]

// Output: [0,9]

// Explanation:

// The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
// The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

// Output: []

// Explanation:

// There is no concatenated substring.

// Example 3:

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

// Output: [6,9,12]

// Explanation:

// The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
// The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
// The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

 

// Constraints:

// 1 <= s.length <= 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int wordL = words[0].size();
        unordered_map <string, int> wmp;
        for(string st: words) wmp[st]++;
        vector<int> ans;

        for(int i = 0; i < wordL; ++i){
            int start = i, cnt = 0;
            unordered_map<string, int> sub;

            for(int end = i; end + wordL <= n; end+=wordL){
                string word = s.substr(end, wordL);

                if(wmp.count(word)){
                    cnt++;
                    sub[word]++;
                    while (sub[word] > wmp[word]){
                        string firstW = s.substr(start, wordL);
                        sub[firstW]--;
                        cnt--;
                        start += wordL;
                    }
                    if(cnt == words.size()) ans.push_back(start);

                }else{
                    sub.clear();
                    cnt = 0;
                    start = end + wordL;
                }
            }
        }
        return ans;

    }
};