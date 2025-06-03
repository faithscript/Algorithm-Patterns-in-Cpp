// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

class Solution
{
public:
    int findLength(const vector<char> &arr)
    {
        int l = 0;
        int s = 0;
        unordered_map<char, int>mp;

        for(int e = 0; e < arr.size(); e++){
            mp[arr[e]]++;
            while(mp.size() > 2){
                mp[arr[s]]--;
                if(mp[arr[s]] == 0) mp.erase(arr[s]);
                s++;
            }

            l = max(l, e - s + 1);
        }
        return l;
    }
};