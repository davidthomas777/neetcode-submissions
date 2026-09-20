class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = nums.size();
        int l = 0;
        int r = nums.size() - 1;
    
        // [-1, 0, 2, 4, 6, 8]
        // l = 0, r = 5, target = 5
        // m = 2, nums[m] = 2, nums[mid] < target, l = mid + 1 = 3
        // l = 3, r = 5, m = 3 + 5 = 8 / 2 = 4
        // nums[4] = 6 > target, res = mid = 4, r = 4
        // l = 3, r = 4, 7 / 2 = 3, nums[3] = 4, l = mid + 1 = 4
        // l = 4, r = 4, 8 / 2 = 4, nums[4] = 6 > target, res = 4, r = mid - 1
        // return res = 4
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};