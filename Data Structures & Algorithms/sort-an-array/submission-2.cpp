class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        // if array of size 1 return 
        if (l == r) return;
        int m = (l + r) / 2;
        // left half
        mergeSort(nums, l, m);
        // right half
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        // copy each half into its own vector
        vector<int> left(nums.begin() + l, nums.begin() + m + 1);
        vector<int> right(nums.begin() + m + 1, nums.begin() + r + 1);

        // left array index
        int i = 0;
        // right array index
        int j = 0;
        // write index for nums
        int k = l;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            }
            else {
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < left.size()) {
            nums[k] = left[i];
            k++;
            i++;
        }
        while (j < right.size()) {
            nums[k] = right[j];
            k++;
            j++;
        }
    }
};