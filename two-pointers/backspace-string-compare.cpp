// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sc = 0;
        int tc = 0;
        int i = s.size() - 1;
        int j = t.size() - 1;

        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    sc++;
                    i--;
                }else if(sc > 0){
                    sc--;
                    i--;
                }else{
                    break;
                }
            }
            while(j >= 0){
                if(t[j] == '#'){
                    tc++;
                    j--;
                }else if(tc > 0){
                    tc--;
                    j--;
                }else{
                    break;
                }
            }
            if(i >= 0 && j >= 0 && s[i] != t[j]) return false;
            else if(i >= 0 != j >= 0) return false;

            i--;
            j--;

        }

    return true;

    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sc = 0;
        int tc = 0;
        string ns = "";
        string ts = "";

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '#'){
                sc++;
            }else{
                if(sc == 0){
                    ns += s[i];
                }else{
                    sc--;
                }
            }
        }
        for(int i = t.size() - 1; i >= 0; i--){
            if(t[i] == '#'){
                tc++;
            }else{
                if(tc == 0){
                    ts += t[i];
                }else{
                    tc--;
                }
            }
        }

        return ns == ts;

    }
};