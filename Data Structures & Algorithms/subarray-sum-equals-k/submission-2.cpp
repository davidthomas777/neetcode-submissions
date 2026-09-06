class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        // for each number in nums
        for (int num : nums) {
            curSum += num;             // running total up to here
            int diff = curSum - k;     // the earlier total we need
            res += prefixSums[diff];   // each past occurrence = one subarray
            prefixSums[curSum]++;      // record this total for future lookups
        }
        return res;
    }
};