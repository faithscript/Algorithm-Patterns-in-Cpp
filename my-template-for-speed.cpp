#include <bits/stdc++.h>
using namespace std;

typedef         long long                   ll;  // 64-bit integer, for values up to 10^18
typedef         pair<int, int>              pii; // pair of integers, useful for coordinates or ranges
typedef         unordered_map<char, int>    umci; // hash map (char → int), O(1) lookups
typedef         unordered_map<int, int>     umii; // hash map (int → int), great for frequency counts
typedef         vector<int>                 vi;  // dynamic array of integers
typedef         vector<long long>           vll; // dynamic array of long longs

typedef         set<int>                    si;  // ordered set, maintains sorted integers, O(log n) operations
typedef         set<ll>                     sll; // ordered set of long longs
typedef         set<string>                 ss;  // ordered set with lexicographical sorting
typedef         unordered_set<int>          usi; // hash set of integers, O(1) average lookup
typedef         unordered_set<ll>           usll; // hash set of long longs
typedef         unordered_set<char>         uss; // hash set of characters

// Common macros for iteration
#define         rep(i, n)                   for (int i = 0; i < (n); ++i) // loop from 0 to n-1, efficient array traversal
#define         rep1(i, a, b)               for (int i = (a); i <= (b); ++i) // loop from a to b inclusive
#define         all(v)                      v.begin(), v.end() // pass entire container to algorithms (e.g., sort(all(v)))
#define         pb                          push_back // append elements to vector
#define         sz(a)                       (int)a.size() // get size as int, prevents size_t warnings


const int N = 2e5 + 20;
int cnt[N], pref[N], dp[N];
int t;
ll n, k, a, b, c, x;
string s;
string yh = "YES\n";
string no = "NO\n";


void solve(){
    // your solution
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
