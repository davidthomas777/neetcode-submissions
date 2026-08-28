class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i - k - 1]); // drop element leaving the window
            if (window.count(nums[i])) return true;    // duplicate inside window
            window.insert(nums[i]);
        }
        return false;
        // [1, 2, 3, 1], k = 3
        // window [1], cur = 1, i = 0
        // window [1, 2], cur = 2, i = 1
        // window [1, 2, 3], cur = 3, i = 2
        // window [1, 2, 3] cur = 1, i = 3, since cur in window, return true;

    }
};