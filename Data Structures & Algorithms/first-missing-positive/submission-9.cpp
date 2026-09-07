class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // while nums[i] is positive and equal to the size of 
            // the array or less, and the current number in nums 
            // doesn't already hold this value
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i != nums[i-1]) return i;
            // if all negative values, i will just be 1 sice 1 doesnt exist
            // in an all negative array.
        }
        // if input array is a permuation of 1... n
        return n + 1;
    }
};