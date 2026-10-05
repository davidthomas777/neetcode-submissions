class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums2) {
            nums1.push_back(num);
        }
        sort(nums1.begin(), nums1.end());
        for (int num : nums1) {
            cout << num << endl;
        }
        // median is the middle value
        // if odd
        // [1, 2, 3, 4, 5] l = 0, r = 4, 0 + 4 / 2 = 2, 
        // if even
        // [1, 2, 3, 4, 5, 6] l = 0, r = 5, m1= 5 / 2 = 2, m2 = m + 1, 
        // so median = m1 +  m2 / 2 = 3 + 4 = 7 / 2 = 3.5
        int nums1_size = nums1.size();
        int l = 0;
        int r = nums1_size - 1;
        int m = (l + r) / 2;

        if (nums1_size % 2 == 1) {
            return static_cast<double>(nums1[m]);
        }
        else {
            int m2 = nums1[m + 1];
            double res = (nums1[m] + m2) / 2.0;
            return res;
        }
    }
};
