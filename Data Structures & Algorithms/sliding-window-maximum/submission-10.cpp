class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> output;
        // deque for indexes
        std::deque<int> q;
        int left = 0;
        int right = 0;
        // index int to last element in nums
        int num_len = nums.size() - 1;

        // while right index is in-bounds
        while (right < nums.size()) {
            // pop smaller values from q
            while (!q.empty() && nums[q.back()] < nums[right]) {
                q.pop_back();
            }
            q.push_back(right);

            if (left > q.front()) {
                q.pop_front();
            }

            if (right + 1 >= k) {
                output.push_back(nums[q.front()]);
                left += 1;
            }
            right += 1;
        }
        return output;
    }
};
