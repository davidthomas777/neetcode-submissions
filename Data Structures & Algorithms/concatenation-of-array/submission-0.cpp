class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int nums_len = nums.size();
        for (int i = 0; i < nums_len; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};