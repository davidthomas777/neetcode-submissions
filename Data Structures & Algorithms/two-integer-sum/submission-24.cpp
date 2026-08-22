class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a map that matches a value in the vector to its index
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }
        for (int j = 0; j < nums.size(); j++) {
            int difference = target - nums[j];
            if (indices.count(difference) && indices[difference] != j) {
                return {j, indices[difference]};
            }
        }
        return {};
    }
};