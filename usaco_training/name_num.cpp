// Name That Number
// Among the large Wisconsin cattle ranchers, it is customary to brand cows with serial numbers to please the Accounting Department. The cow hands don't appreciate the advantage of this filing system, though, and wish to call the members of their herd by a pleasing name rather than saying, "C'mon, #4734, get along."

// Help the poor cowhands out by writing a program that will translate the brand serial number of a cow into possible names uniquely associated with that serial number. Since the cow hands all have cellular saddle phones these days, use the standard Touch-Tone(R) telephone keypad mapping to get from numbers to letters (except for "Q" and "Z"):

//           2: A,B,C     5: J,K,L    8: T,U,V
//           3: D,E,F     6: M,N,O    9: W,X,Y
//           4: G,H,I     7: P,R,S
// Acceptable names for cattle are provided to you in a file named "dict.txt", which contains a list of fewer than 5,000 acceptable cattle names (all letters capitalized). Take a cow's brand number and report which of all the possible words to which that number maps are in the given dictionary which is supplied as dict.txt in the grading environment (and is sorted into ascending order).

// For instance, the brand number 4734 produces all the following names:

// GPDG GPDH GPDI GPEG GPEH GPEI GPFG GPFH GPFI GRDG GRDH GRDI
// GREG GREH GREI GRFG GRFH GRFI GSDG GSDH GSDI GSEG GSEH GSEI
// GSFG GSFH GSFI HPDG HPDH HPDI HPEG HPEH HPEI HPFG HPFH HPFI
// HRDG HRDH HRDI HREG HREH HREI HRFG HRFH HRFI HSDG HSDH HSDI
// HSEG HSEH HSEI HSFG HSFH HSFI IPDG IPDH IPDI IPEG IPEH IPEI
// IPFG IPFH IPFI IRDG IRDH IRDI IREG IREH IREI IRFG IRFH IRFI
// ISDG ISDH ISDI ISEG ISEH ISEI ISFG ISFH ISFI
// As it happens, the only one of these 81 names that is in the list of valid names is "GREG".

// Write a program that is given the brand number of a cow and prints all the valid names that can be generated from that brand number or ``NONE'' if there are no valid names. Serial numbers can be as many as a dozen digits long.

// PROGRAM NAME: namenum
// INPUT FORMAT
// A single line with a number from 1 through 12 digits in length.
// SAMPLE INPUT (file namenum.in)
// 4734

/*
PROB: namenum
LANG: C++
*/


#include <bits/stdc++.h>
using namespace std;

typedef         long long                   ll;
typedef         pair<int, int>              pii;
typedef         unordered_map<char, int>    umci;
typedef         unordered_map<int, int>     umii;
typedef         unordered_map<string, int>  umsi;
typedef         vector<int>                 vi;
typedef         vector<long long>           vll;
typedef         vector<pair<int, int>>      vpii;

typedef         set<int>                    si;
typedef         set<ll>                     sll;
typedef         set<string>                 ss;
typedef         unordered_set<int>          usi;
typedef         unordered_set<ll>           usll;
typedef         unordered_set<char>         uss;

#define         rep(i, n)                   for (int i = 0; i < (n); ++i)
#define         rep1(i, a, b)               for (int i = (a); i < (b); ++i)
#define         all(v)                      v.begin(), v.end()
#define         pb                          push_back
#define         sz(a)                       (int)a.size()

string n;

void solve() {
    cin >> n;
    ifstream dict_file("dict.txt");
    unordered_set<string> dict;
    string word;

    while(getline(dict_file, word)){
        if(word.size() == n.size()){
            dict.insert(word);
        }
    }

    dict_file.close();
    string current = "";
    vector<string> valid_names;

    string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", 
                       "MNO", "PQRS", "TUV", "WXYZ"};

    function<void(int)> backtrack = [&](int index){
        if(index == n.size()){
            if(dict.count(current)) {
                valid_names.push_back(current);
            }
            return;
        }
        int digit = n[index] - '0';

        for(char c : keypad[digit]){
            current.push_back(c);
            backtrack(index + 1);
            current.pop_back();
        }
    };


    backtrack(0);

    if (valid_names.empty()) {
        return;
    } else {
        sort(valid_names.begin(), valid_names.end()); 
        for (const string& name : valid_names) {
            cout << name << endl;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    solve();
    return 0;
}
