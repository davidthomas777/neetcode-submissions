class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // size 5
        // [1, 2, 3, 4, 5]
        // remove 2,
        // iterate, 1, gets to 2,
        int nums_size = nums.size();
        int remove_count = 0;
        for (int i = 0; i < nums_size - remove_count; i++) {
            // if nums[i] equals target val, remove it
            // and add it to the back of the list
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                nums.push_back(val);
                remove_count++;
                i--;
            }
        }
        return nums_size - remove_count;
    }
};