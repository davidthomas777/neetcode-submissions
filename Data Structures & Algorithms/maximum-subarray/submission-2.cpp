class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            cur_sum = max(curr, cur_sum + curr);
            res = max(res, cur_sum);
        }
        return res;
    }
};
