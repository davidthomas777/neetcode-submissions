class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = 0;                          // 0 if not rotated
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) { 
                pivot = i; 
                break; 
            }
        }
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int curr = nums[(mid + pivot) % n];    // map virtual index to real index
            if (curr == target) return true;
            if (curr < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};