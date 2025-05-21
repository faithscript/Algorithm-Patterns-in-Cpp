// Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

// Example 1:

// Input: [-1, 0, 2, 3], target=3 
// Output: 2
// Explanation: The triplet [-1, 0, 3] has the sum '2' which is closest to the target.

// There are two triplets with distance '1' from the target: [-1, 0, 3] & [-1, 2, 3]. Between these two triplets, the correct answer will be [-1, 0, 3] as it has a sum '2' which is less than the sum of the other triplet which is '4'. This is because of the following requirement: 'If there are more than one such triplet, return the sum of the triplet with the smallest sum.'


int tripletSumCloseToTarget(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int closest = INT_MAX, minDiff = INT_MAX;
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - sum);
            if (diff < minDiff || (diff == minDiff && sum < closest)) {
                closest = sum;
                minDiff = diff;
            }
            if (sum < target) ++left;
            else --right;
        }
    }
    return closest;
}