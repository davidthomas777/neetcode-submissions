class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 1;
        int r = n - 1;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            l = i + 1;
            r = n - 1;
            while (l < r) {
                int current = nums[i] + nums[l] + nums[r];
                if (current == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;  // skip dup l
                    while (l < r && nums[r] == nums[r + 1]) r--;  // skip dup r
                }
                else if (current < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return res;
        // [-4, -1, -1, 0, 1, 2]
        // []
    }
};
