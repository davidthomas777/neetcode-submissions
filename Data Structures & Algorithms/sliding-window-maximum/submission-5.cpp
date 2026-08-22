class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // should be the length of how long the window moves. so (nums.size - k) + 1
        vector<int> res;
        // indexes for left, right, and total len of vector nums
        int start = 0;
        int end = k - 1;
        int total_len = nums.size() - 1;
        while (end <= total_len) {
            int current_max = nums[start];
            // iterate from start to end of k to find max
            for (int i = start; i <= end; i++) {
                if (nums[i] > current_max) {
                    current_max = nums[i];
                }
            }
            // push back the max to res
            res.push_back(current_max);

            // update start and end pointers
            start++;
            end++;
        }
        return res;
    }
};
