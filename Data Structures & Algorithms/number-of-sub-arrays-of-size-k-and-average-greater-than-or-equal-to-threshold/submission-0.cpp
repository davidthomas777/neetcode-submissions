class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int r = 0;
        int n = arr.size();
        int res = 0;

        /*
        arr = [2, 2, 2, 2, 5, 5, 5, 8]
        k = 3 (size of sub array)
        average of current subarray must be >= threshold
        */

        int window_total = 0;
        while (r < n) {
            window_total += arr[r];
            r++;
            // if window size is k
            if (r - l == k) {
                // if average of current window is >= threshold
                if (window_total / k >= threshold) {
                    res += 1;
                }
                window_total -= arr[l];
                l++;
            }
        }
        return res;
    }
};