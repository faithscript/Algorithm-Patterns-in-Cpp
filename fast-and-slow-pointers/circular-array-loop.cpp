//You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

// If nums[i] is positive, move nums[i] steps forward, and
// If nums[i] is negative, move nums[i] steps backward.
// Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

// A cycle in the array consists of a sequence of indices seq of length k where:

// Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
// Every nums[seq[j]] is either all positive or all negative.
// k > 1
// Return true if there is a cycle in nums, or false otherwise.

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;
            
            int dir = (nums[i] > 0)? 1 : -1;

            int slow = i;
            int fast = i;

            while(nums[fast] * dir > 0 && nums[next(fast, n, nums)] * dir > 0){
                slow = next(slow, n, nums);
                fast = next(fast, n, nums);
                fast = next(fast, n, nums);

                if(slow == fast){
                    if(slow != next(slow, n, nums)) return true; // prevents the cycle from being size - 1
                    break;
                }
            }
            int curr = i;
            while(nums[curr]*dir>0){
                int nextCurr = next(curr, n, nums);
                nums[curr] = 0;
                curr = nextCurr;
            }
        }
        return false;
    }

    int next(int i, int n, vector<int>& nums) {
        return (i + nums[i] % n + n) % n;
    }
};
// game plan: turn the numbers you've looked over to 0
// next function called N
// plan
// iterate over the whole array and continue if you witness zero, array a
// set the constant of the direction depending on the sign of nums[i]; call it d
// set your fast and slow pointer, as f d
//and while a_f*d > 0 && a_N(f)*d >0 , we perform s = N(s) and f = N(N(f))
// cycle occurs when s == f, so the pointers met up
// make sure the cycle isn't 1 by checking if s != N(s) meaning return true or you break the while loop;

// to turn the numbers we've looked over we can set a pointer, p to i, and while(a_p*d > 0)
// set a_p to 0, and perform p = N(p)

// next formula is i + a_i % n
// since it can be negfative, i +a_i % n + n
// final normalization
// (i + a_i % n + n) % n

