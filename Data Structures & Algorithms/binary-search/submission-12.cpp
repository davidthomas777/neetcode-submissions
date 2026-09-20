class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        // [1, 2, 3, 4, 5, 6, 7, 8], target = 2
        // l = 0, r = 7
        // 7 + 0 = 7 / 2 = 3
        // nums[3] is 4
        // r = 3 - 1 = 2
        // l = 0, r = 2
        while (l <= r) {
            int m = (r + l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};
