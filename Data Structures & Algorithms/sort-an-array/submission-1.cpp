class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // if size is 1 
        if (l == r) return;
        // middle calculation
        int m = (l + r ) / 2;
        // recursive call left half
        mergeSort(arr, l, m);
        // recrusive call right half
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
    // merge two sorted subarrays back into one
    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        //
        int i = l;
        int j = m + 1;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }
};