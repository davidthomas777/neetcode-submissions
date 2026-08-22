class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 = [10, 20, 20, 40, 0, 0], m = 4
        // num2 = [1, 2], n = 2
        //  if nums1[m] > nums2[n], we swap nums1[end] with nums1[m]
        // [10, 20, 20, 0, 0, 40]
        // [10, 20, 0, 0, 20, 40]
        // [10, 0, 0, 20, 20, 40]
        // [0, 0, 10, 20, 20, 40]
        //  else, we replace nums1[end] with nums2[n]
        int end = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        // while nums2 position is 0 or larger
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                swap(nums1[end], nums1[i]);
                i--;
            }
            else {
                nums1[end] = nums2[j];
                j--;
            }
            end--;
        }
    }
};