class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int i = 0;
        int r = nums.size() - 1;

        //
        while (i <= r) {
            // swap all 0's to left ptr
            if (nums[i] == 0) {
                swap(nums[l], nums[i]);
                // update next left ptr
                l++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
            i++;
        }
    }
};