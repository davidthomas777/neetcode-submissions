class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map indicies to their value
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            // map value to index its seen at
            mp[nums[i]].push_back(i);
        }

        for (pair<int, vector<int>> p : mp) {
            // if more than one of a value
            if (p.second.size() > 1) {
                for (int i = 1; i < p.second.size(); i++) {
                    if (p.second[i] - p.second[i-1] <= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};