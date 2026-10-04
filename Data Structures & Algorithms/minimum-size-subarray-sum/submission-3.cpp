class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int cur_sum = 0;
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            cur_sum += nums[r];
            while (cur_sum >= target) {
                res = min(res, r - l + 1);
                cur_sum -= nums[l];
                l++;
            }
            r++;
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};