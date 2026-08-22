class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // size of array
        int n = nums.size();
        // res list
        vector<int> res(n);

        // iterate through each number
        for (int i = 0; i < n; i++) {
            int prod = 1;
            // iterate through self again except itself
            for (int j = 0; j < n; j++) {
                // if number not the same
                if (i != j) {
                    prod *= nums[j];
                }
            }
            // set index to product for each iteration
            res[i] = prod;
        }
        // return res
        return res;
    }
};