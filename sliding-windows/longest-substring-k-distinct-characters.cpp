// Given a string, find the length of the longest substring in it with no more than K distinct characters.

// You can assume that K is less than or equal to the length of the given string.

// Example 1:

// Input: String="araaci", K=2  
// Output: 4  
// Explanation: The longest substring with no more than '2' distinct characters is "araa".
// Example 2:

// Input: String="araaci", K=1  
// Output: 2  
// Explanation: The longest substring with no more than '1' distinct characters is "aa".
// Example 3:

// Input: String="cbbebi", K=3  
// Output: 5  
// Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

class Solution
{
public:
    int findLength(const string &str, int k)
    {
        unordered_map<char, int>mp;
        int mx = 0; 
        int s = 0;
        for(int e = 0; e < str.length(); e++){
            mp[str[e]]++;
            while(mp.size() > k){
                mp[str[s]]--;
                if(mp[str[s]] == 0) mp.erase(str[s]);
                s++;
            }
            mx = max(mx, e - s + 1);
        }
        return mx;
    }
};
