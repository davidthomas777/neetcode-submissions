class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        // for each number in nums
        for (int num : nums) {
            // add to curSum
            curSum += num;
            // get diff
            int diff = curSum - k;
            // counts subarrays ending with sum k
            res += prefixSums[diff];
            // increment prefix sum
            prefixSums[curSum]++;
        }
        return res;
    }
};