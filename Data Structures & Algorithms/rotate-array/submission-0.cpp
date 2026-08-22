class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // s: [1, 2, 3, 4, 5, 6, 7, 8], k = 4
        // 1: [8, 1, 2, 3, 4, 5, 6, 7]
        // 2: [7, 8, 1, 2, 3, 4, 5, 6]
        // 3: [6, 7, 8, 1, 2, 3, 4, 5]
        // 4: [5, 6, 7, 8, 1, 2, 3, 4]
        int nums_length = nums.size();
        int rotate_count = 0;

        while (rotate_count != k) {
            for (int i = 1; i < nums_length; i++) {
                // swap current with first element
                swap(nums[i], nums[0]);
            }
            rotate_count++;
        }
    }
};