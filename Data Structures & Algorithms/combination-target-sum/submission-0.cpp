class Solution {
public:
    // total
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        // params: starting vector, target, current sublist, current index
        dfs(nums, target, cur, 0);
        return res;
    }   

    void dfs(vector<int> & nums, int target, vector<int> & cur, int i) {
        // if the target reaches 0 exactly, we push back the current vector cur into res
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        // if current sum goes over the target, or index i is out of bounds
        if (target < 0 || i >= nums.size()) {
            return;
        }

        // otherwise:
        cur.push_back(nums[i]);
        // recursively try again with nums[i] subtracted from target with same index
        dfs(nums, target - nums[i], cur, i);
        // pop value and try next one i + 1instead
        cur.pop_back();
        dfs(nums, target, cur, i + 1);
    }
};
