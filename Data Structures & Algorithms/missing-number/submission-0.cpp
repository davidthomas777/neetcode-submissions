class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size() * (nums.size() + 1)) / 2;
        int sum_list = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum_list += nums[i];
        }
        return sum - sum_list;
    }
};
