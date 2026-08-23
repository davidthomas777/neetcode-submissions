class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 2; i++) {
            // skip duplicates for i and j
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    res.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            j++;
        }
        vector<vector<int>> res_list(res.begin(), res.end());
        return res_list;
    }
};
