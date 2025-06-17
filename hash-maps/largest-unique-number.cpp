// Given an array of integers, identify the highest value that appears only once in the array. If no such number exists, return -1.

// Examples:

// Example 1:

// Input: [5, 7, 3, 7, 5, 8]
// Expected Output: 8
// Justification: The number 8 is the highest value that appears only once in the array.
// Example 2:

// Input: [1, 2, 3, 2, 1, 4, 4]
// Expected Output: 3
// Justification: The number 3 is the highest value that appears only once in the array.
// Example 3:

// Input: [9, 9, 8, 8, 7, 7]
// Expected Output: -1
// Justification: There is no number in the array that appears only once.
// Constraints:

// 1 <= nums.length <= 2000
// 0 <= nums[i] <= 1000


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int maxUnique = -1;
        unordered_map<int, int>mp;

        for(int& z : A){
            mp[z]++;
        }
        for(int& z: A){
            if(mp[z] == 1 && z > maxUnique){
                maxUnique = z;
            }
        }
        return maxUnique;
    }
};
